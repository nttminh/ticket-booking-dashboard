#include "ShowtimeAdmin.h"
#include "ui_ShowtimeAdmin.h"
#include "QSqlQueryModel"
#include "QSqlQuery"
#include "QFileDialog"
#include "QMessageBox"
#include "QByteArray"
#include "QSqlError"
#include "QVector"
#include "QDir"

ShowtimeAdmin::ShowtimeAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowtimeAdmin)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString db_path = QDir::currentPath();
    db_path =  db_path + QString("/database.db");
    mydb.setDatabaseName(db_path);

    updateTable();
}

ShowtimeAdmin::~ShowtimeAdmin()
{
    delete ui;
}

QByteArray ShowtimeAdmin::toByteArray(const QVector<bool> &data){
      QByteArray result;
      QDataStream bWrite( &result, QIODevice::WriteOnly );
      bWrite << data;

      return result;
}

QByteArray ShowtimeAdmin::toByteArray(const QPixmap &data){
      QByteArray result;
      QDataStream bWrite( &result, QIODevice::WriteOnly );
      bWrite << data;

      return result;
}

void ShowtimeAdmin::removeMovie(){
    int row=ui->tableView_movieList->currentIndex().row();
    if(QMessageBox::question(0,"Delete", "Record no. "
                             +QString::number(row+1)
                             +" will be deleted. Are you sure?",
                             QMessageBox::No,QMessageBox::Yes)==
                             QMessageBox::Yes){
//       model->removeRow(row);
    }
}



void ShowtimeAdmin::updateTable(){
    mydb.open();

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery(mydb);
    query->prepare("SELECT * FROM movies");
    query->exec();
    model->setQuery(*query);
    ui->tableView_movieList->setModel(model);
    ui->tableView_movieList->setColumnHidden(4, true);


    mydb.close();

//    qDebug() << (model->rowCount());

}

void ShowtimeAdmin::on_btn_choosePhoto_clicked()
{
    QString imageFile = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "JPEG file (*.JPG);;PNG file (*.PNG);;All files(*.*)");

    QFileInfo info(imageFile);
    QPixmap image (imageFile);
    moviePhoto = image;
    int w = ui->label_moviePhoto->width();
    int h = ui->label_moviePhoto->height();
    ui->label_moviePhoto->setPixmap(image.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_moviePhoto->show();
}

void ShowtimeAdmin::on_btn_addMovie_clicked()
{
    QString movieName;
    int movieLength;
    int timeSlot;

    try {
        movieName   = ui->lineEdit_movieName->text().trimmed();               //name of movie
        movieLength     = ui->lineEdit_movieLength->text().toInt();     //length, which is minutes of movie
        timeSlot        = ui->comboBox_timeSlot->currentIndex() + 1;    //how many times the movie will be played per day
        if (movieName.size() == 0){
            throw QString("Movie name must be specified");
        }
        if  (movieLength < 0 || ui->lineEdit_movieLength->text().isEmpty()){
            throw QString("Length must be > 0");
        }

    }  catch (QString err) {
        QMessageBox :: critical(this,"Error",err);
        return;
    }  catch (...){
        QMessageBox :: critical(this,"Error","Unhandled exception has occured");
        return;
    }

    // store 96 seats available to a vector
    QVector<bool> seatAvailableTheaterA;
    QVector<bool> seatAvailableTheaterB;
    QVector<bool> seatAvailableTheaterC;
    QVector<bool> seatAvailableTheaterD;
    QVector<bool> seatAvailableTheaterE;
    for (int i = 0;i < 96; i++) {
        seatAvailableTheaterA.push_back(false);
        seatAvailableTheaterB.push_back(false);
        seatAvailableTheaterC.push_back(false);
        seatAvailableTheaterD.push_back(false);
        seatAvailableTheaterE.push_back(false);
    }

    mydb.open();
    QSqlQuery *query = new QSqlQuery(mydb);
        query->prepare("INSERT INTO movies(name, length, timeSlot, img, theaterA, theaterB, theaterC, theaterD, theaterE) values (?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query->addBindValue(movieName);
        query->addBindValue(movieLength);
        query->addBindValue(timeSlot);
        query->addBindValue(toByteArray(moviePhoto));
        query->addBindValue(toByteArray(seatAvailableTheaterA));
        query->addBindValue(toByteArray(seatAvailableTheaterB));
        query->addBindValue(toByteArray(seatAvailableTheaterC));
        query->addBindValue(toByteArray(seatAvailableTheaterD));
        query->addBindValue(toByteArray(seatAvailableTheaterE));
        if(!query->exec())
        {
            QMessageBox::critical(this,"Error","Couldn't insert data");
            qDebug() << query->lastError();
        }
    mydb.close();
    updateTable();

    ui->lineEdit_movieName->clear();
    ui->lineEdit_movieLength->clear();
    ui->comboBox_timeSlot->setCurrentIndex(-1);
    ui->label_moviePhoto->clear();
}

void ShowtimeAdmin::on_btn_removeMovie_clicked()
{
    mydb.open();
    int movieID = ui->lineEdit_movieIdWillBeRemoved->text().toInt();
    ui->lineEdit_movieIdWillBeRemoved->clear();

    QSqlQuery query;
        query.prepare("DELETE FROM movies WHERE movieId = :id");
        query.bindValue(":id",movieID);
        if (query.exec()){
        } else { QMessageBox::critical(this,"Error","cannot find the movieID provided"); }
    mydb.close();
    updateTable();
}

void ShowtimeAdmin::on_pushButton_export_clicked()
{
    // pop up a save dialog
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Movie List"), "",
        tr("Text file (*.txt);;All Files (*)"));
    // If fileName is not empty, we create a QFile object, file, with fileName
    if (fileName.isEmpty())
          return;
      else {
          QFile file(fileName);
          // we attempt to open the file in WriteOnly mode. If this is unsuccessful, we display a QMessageBox to inform the user.
          if (!file.open(QIODevice::WriteOnly)) {
              QMessageBox::information(this, tr("Unable to open file"),
                  file.errorString());
              return;
          }
          /*
           * Otherwise, we instantiate a QDataStream object, out, to write the open file.
           * QDataStream requires that the same version of the stream is used for reading and writing.
           * We ensure that this is the case by setting the version used to the version introduced with Qt 4.5 before serializing the data to file.
           */
          QTextStream out(&file);

          mydb.open();
          QSqlQuery query;
          query.exec("SELECT * FROM movies");
          while (query.next()) {
              int movieID = query.value(0).toInt();
              QString movieName = query.value(1).toString();
              int length = query.value(2).toInt();
              int timeSlot = query.value(3).toInt();
              // write to data stream
              out << QString::number(movieID) << QString(" (") << movieName << QString(") ") << QString::number(length) << QString(" ") << QString::number(timeSlot) << QString("\n");
          }
          mydb.close();
      }


}
