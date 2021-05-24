#include "Showtime.h"
#include "ui_Showtime.h"
#include "SeatAvailability.h"
#include <sstream>
#include "string"

Showtime::Showtime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Showtime)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString db_path = QDir::currentPath();
    db_path =  db_path + QString("/database.db");
    mydb.setDatabaseName(db_path);
    updateShowtime();

}

Showtime::~Showtime()
{
    delete ui;
}



QString Showtime::toHourMinute(int minute){
    int hours = minute / 60;
    int minutes = minute % 60;
    return QString::number(hours) + " HR " + QString::number(minutes) + " MIN";
}

QPixmap Showtime::toPixmap(const QByteArray &buffer){
    QPixmap result;
    QDataStream bRead( buffer );
    bRead >> result;

    return result;
}


void Showtime::onAddWidgets(int movieID, QString name, int length, int timeSlot, QPixmap img){
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->frame->layout());

    // concentrate on the line indentation
    QGroupBox* groupBox = new QGroupBox(tr("%1").arg(layout->count()),ui->frame);
    QHBoxLayout* hOfGroupBox = new QHBoxLayout;
        QLabel* picture = new QLabel();
        picture->setFixedWidth(469);
        picture->setFixedHeight(200);
        int w = picture->width();
        int h = picture->height();
        picture->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        QVBoxLayout* movieDetails = new QVBoxLayout;
        movieDetails->addStretch();
            QVBoxLayout* nameAndLength = new QVBoxLayout;
                QLabel* movieName = new QLabel(name);
                movieName->setFont(QFont("Arial", 14, QFont::Bold));
                QLabel* movieLength = new QLabel(toHourMinute(length));
                movieLength->setFont(QFont("Arial", 8));
            nameAndLength->addWidget(movieName);
            nameAndLength->addWidget(movieLength);
            nameAndLength->addStretch();
            QHBoxLayout* buttonsOfTime = new QHBoxLayout;
                for (int i = 0;i < timeSlot ; i++ ) {
                    QPushButton *button = new QPushButton();

                    switch (i) {
                        case 0:
                            button->setText("12:20 PM");

                            button->setProperty("myId",movieID);
                            connect(button, &QPushButton::clicked, [this, button](){
                                setMovieIDChosen(button->property("myId").toInt());
                            });

                            connect(button, SIGNAL(clicked()), this, SLOT(implementButton()));
                            break;
                        case 1:
                            button->setText("1:50 PM");

                            button->setProperty("myId",movieID);
                            connect(button, &QPushButton::clicked, [this, button](){
                                setMovieIDChosen(button->property("myId").toInt());
                            });

                            connect(button, SIGNAL(clicked()), this, SLOT(implementButton()));
                            break;
                        case 2:
                            button->setText("2:45 PM");

                            button->setProperty("myId",movieID);
                            connect(button, &QPushButton::clicked, [this, button](){
                                setMovieIDChosen(button->property("myId").toInt());
                            });

                            connect(button, SIGNAL(clicked()), this, SLOT(implementButton()));
                            break;
                        case 3:
                            button->setText("4:45 PM");

                            button->setProperty("myId",movieID);
                            connect(button, &QPushButton::clicked, [this, button](){
                                setMovieIDChosen(button->property("myId").toInt());
                            });

                            connect(button, SIGNAL(clicked()), this, SLOT(implementButton()));
                            break;
                        case 4:
                            button->setText("7:40 PM");

                            button->setProperty("myId",movieID);
                            connect(button, &QPushButton::clicked, [this, button](){
                                setMovieIDChosen(button->property("myId").toInt());
                            });

                            connect(button, SIGNAL(clicked()), this, SLOT(implementButton()));
                            break;
                    }

                    button->setMinimumSize(85, 23);
                    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
                    buttonsOfTime->addWidget(button);
                }


            buttonsOfTime->addStretch();
        movieDetails->addLayout(nameAndLength);
        movieDetails->addLayout(buttonsOfTime);
//        movieDetails->addStretch();
    hOfGroupBox->addWidget(picture);
    hOfGroupBox->addLayout(movieDetails);


    groupBox->setLayout(hOfGroupBox);

    layout->insertWidget(layout->count() - 1, groupBox);

    mButtonToLayoutMap.insert(groupBox, hOfGroupBox);


}

void Showtime::updateShowtime(){
    mydb.open();
    QSqlQuery query;
    query.exec("SELECT * FROM movies");
    int i = 0;
    while (query.next()) {
//        int movieID = query.value(0).toInt();
        QString movieName = query.value(1).toString();
        int length = query.value(2).toInt();
        int timeSlot = query.value(3).toInt();
        QPixmap moviePhoto = toPixmap(query.value(4).toByteArray());
        onAddWidgets(i, movieName, length, timeSlot, moviePhoto);
        i++;
    }
    mydb.close();
}

// connect button to a particular timeSlot
void Showtime::implementButton(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    if (buttonSender->text() == "12:20 PM"){
        Cart::getInstance().setTimeSlot(0);
    } else if (buttonSender->text() == "1:50 PM"){
        Cart::getInstance().setTimeSlot(1);
    } else if (buttonSender->text() == "2:45 PM"){
        Cart::getInstance().setTimeSlot(2);
    } else if (buttonSender->text() == "4:45 PM"){
        Cart::getInstance().setTimeSlot(3);
    } else if (buttonSender->text() == "7:40 PM"){
        Cart::getInstance().setTimeSlot(4);
    }

    SeatAvailability *sa = new SeatAvailability();
    sa->show();
    hide();
}

void Showtime::setMovieIDChosen(int id)
{
    Cart::getInstance().setMovieIDChosen(id);
//    qDebug() << "Movie ID Chosen : " << id;
}

