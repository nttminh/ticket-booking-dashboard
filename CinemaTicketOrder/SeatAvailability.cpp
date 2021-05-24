#include "SeatAvailability.h"
#include "ui_SeatAvailability.h"
#include "FoodAndDrinks.h"

SeatAvailability::SeatAvailability(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeatAvailability)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString db_path = QDir::currentPath();
    db_path =  db_path + QString("/database.db");
    mydb.setDatabaseName(db_path);

    updateSeatAvailable(Cart::getInstance().getMovieIDChosen() , Cart::getInstance().getTimeSlot());
    connectAllButtonToFunction();
}

SeatAvailability::~SeatAvailability()
{
    delete ui;
}

// button "Continue"
void SeatAvailability::on_pushButton_clicked()
{
    FoodAndDrinks *fad = new FoodAndDrinks();
    hide();
    fad->show();
}

void SeatAvailability::updateSeatAvailable(int movieIndex, int timeSlot){
    mydb.open();
    QSqlQuery query;
    query.exec("SELECT * FROM movies");
    for (int i = 0; i <= movieIndex; i++ ) {
        query.next();
    }
    Cart::getInstance().setMovieIDInDatabase(query.value(0).toInt());
    Cart::getInstance().setTicketSoldInDataBase(query.value(5).toInt());
    Cart::getInstance().setFoodSoldInDataBase(query.value(6).toDouble());
    qDebug() << "movie name chosen: " << query.value(1).toString();
    qDebug() << "ticket Sold: " << query.value(5).toString();
    qDebug() << "food Sold: " << query.value(6).toString();


    Cart::getInstance().vectorSeats = toVectorBool(query.value(timeSlot + 7).toByteArray()); // theaterA locate at column 7, theaterE at 11;
    updateDisableSeats(Cart::getInstance().vectorSeats); // set disable
    mydb.close();
}





QByteArray toBytearray( const QVector<bool>& data )
{
  QByteArray result;
  QDataStream bWrite( &result, QIODevice::WriteOnly );
  bWrite << data;

  return result;

}

QVector<bool> SeatAvailability::toVectorBool( const QByteArray& buffer )
{
  QVector<bool> result;
  QDataStream bRead( buffer );
  bRead >> result;

  return result;

}

void SeatAvailability::connectAllButtonToFunction()
{
    connect(ui->pushButton_A1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_A12, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_B12, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_C12, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_D12, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_E12, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_F12, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_G12, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H1, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H2, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H3, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H4, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H5, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H6, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H7, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H8, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H9, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H10, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H11, SIGNAL(clicked()),this, SLOT(chooseSeat()));
    connect(ui->pushButton_H12, SIGNAL(clicked()),this, SLOT(chooseSeat()));

}

// connect button to a particular timeSlot
void SeatAvailability::chooseSeat(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    if (buttonSender->text() == "A1"){
        Cart::getInstance().vectorSeats.replace(0, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A2"){
            Cart::getInstance().vectorSeats.replace(1, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A3"){
            Cart::getInstance().vectorSeats.replace(2, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A4"){
            Cart::getInstance().vectorSeats.replace(3, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A5"){
            Cart::getInstance().vectorSeats.replace(4, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A6"){
            Cart::getInstance().vectorSeats.replace(5, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A7"){
            Cart::getInstance().vectorSeats.replace(6, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A8"){
            Cart::getInstance().vectorSeats.replace(7, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A9"){
            Cart::getInstance().vectorSeats.replace(8, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A10"){
            Cart::getInstance().vectorSeats.replace(9, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A11"){
            Cart::getInstance().vectorSeats.replace(10, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "A12"){
            Cart::getInstance().vectorSeats.replace(11, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B1"){
        Cart::getInstance().vectorSeats.replace(12, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B2"){
            Cart::getInstance().vectorSeats.replace(13, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B3"){
            Cart::getInstance().vectorSeats.replace(14, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B4"){
            Cart::getInstance().vectorSeats.replace(15, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B5"){
            Cart::getInstance().vectorSeats.replace(16, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B6"){
            Cart::getInstance().vectorSeats.replace(17, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B7"){
            Cart::getInstance().vectorSeats.replace(18, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B8"){
            Cart::getInstance().vectorSeats.replace(19, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B9"){
            Cart::getInstance().vectorSeats.replace(20, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B10"){
            Cart::getInstance().vectorSeats.replace(21, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B11"){
            Cart::getInstance().vectorSeats.replace(22, buttonSender->isChecked());
    }
     else if (buttonSender->text() == "B12"){
            Cart::getInstance().vectorSeats.replace(23, buttonSender->isChecked());
    }
    else if (buttonSender->text() == "C1"){
       Cart::getInstance().vectorSeats.replace(24, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C2"){
           Cart::getInstance().vectorSeats.replace(25, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C3"){
           Cart::getInstance().vectorSeats.replace(26, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C4"){
           Cart::getInstance().vectorSeats.replace(27, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C5"){
           Cart::getInstance().vectorSeats.replace(28, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C6"){
           Cart::getInstance().vectorSeats.replace(29, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C7"){
           Cart::getInstance().vectorSeats.replace(30, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C8"){
           Cart::getInstance().vectorSeats.replace(31, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C9"){
           Cart::getInstance().vectorSeats.replace(32, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C10"){
           Cart::getInstance().vectorSeats.replace(33, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C11"){
           Cart::getInstance().vectorSeats.replace(34, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "C12"){
           Cart::getInstance().vectorSeats.replace(35, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D1"){
       Cart::getInstance().vectorSeats.replace(36, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D2"){
           Cart::getInstance().vectorSeats.replace(37, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D3"){
           Cart::getInstance().vectorSeats.replace(38, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D4"){
           Cart::getInstance().vectorSeats.replace(39, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D5"){
           Cart::getInstance().vectorSeats.replace(40, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D6"){
           Cart::getInstance().vectorSeats.replace(41, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D7"){
           Cart::getInstance().vectorSeats.replace(42, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D8"){
           Cart::getInstance().vectorSeats.replace(43, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D9"){
           Cart::getInstance().vectorSeats.replace(44, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D10"){
           Cart::getInstance().vectorSeats.replace(45, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D11"){
           Cart::getInstance().vectorSeats.replace(46, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "D12"){
           Cart::getInstance().vectorSeats.replace(47, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E1"){
       Cart::getInstance().vectorSeats.replace(48, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E2"){
           Cart::getInstance().vectorSeats.replace(49, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E3"){
           Cart::getInstance().vectorSeats.replace(50, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E4"){
           Cart::getInstance().vectorSeats.replace(51, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E5"){
           Cart::getInstance().vectorSeats.replace(52, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E6"){
           Cart::getInstance().vectorSeats.replace(53, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E7"){
           Cart::getInstance().vectorSeats.replace(54, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E8"){
           Cart::getInstance().vectorSeats.replace(55, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E9"){
           Cart::getInstance().vectorSeats.replace(56, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E10"){
           Cart::getInstance().vectorSeats.replace(57, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E11"){
           Cart::getInstance().vectorSeats.replace(58, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "E12"){
           Cart::getInstance().vectorSeats.replace(59, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F1"){
       Cart::getInstance().vectorSeats.replace(60, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F2"){
           Cart::getInstance().vectorSeats.replace(61, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F3"){
           Cart::getInstance().vectorSeats.replace(62, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F4"){
           Cart::getInstance().vectorSeats.replace(63, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F5"){
           Cart::getInstance().vectorSeats.replace(64, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F6"){
           Cart::getInstance().vectorSeats.replace(65, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F7"){
           Cart::getInstance().vectorSeats.replace(66, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F8"){
           Cart::getInstance().vectorSeats.replace(67, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F9"){
           Cart::getInstance().vectorSeats.replace(68, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F10"){
           Cart::getInstance().vectorSeats.replace(69, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F11"){
           Cart::getInstance().vectorSeats.replace(70, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "F12"){
           Cart::getInstance().vectorSeats.replace(71, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G1"){
       Cart::getInstance().vectorSeats.replace(72, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G2"){
           Cart::getInstance().vectorSeats.replace(73, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G3"){
           Cart::getInstance().vectorSeats.replace(74, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G4"){
           Cart::getInstance().vectorSeats.replace(75, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G5"){
           Cart::getInstance().vectorSeats.replace(76, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G6"){
           Cart::getInstance().vectorSeats.replace(77, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G7"){
           Cart::getInstance().vectorSeats.replace(78, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G8"){
           Cart::getInstance().vectorSeats.replace(79, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G9"){
           Cart::getInstance().vectorSeats.replace(80, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G10"){
           Cart::getInstance().vectorSeats.replace(81, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G11"){
           Cart::getInstance().vectorSeats.replace(82, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "G12"){
           Cart::getInstance().vectorSeats.replace(83, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H1"){
       Cart::getInstance().vectorSeats.replace(84, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H2"){
           Cart::getInstance().vectorSeats.replace(85, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H3"){
           Cart::getInstance().vectorSeats.replace(86, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H4"){
           Cart::getInstance().vectorSeats.replace(87, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H5"){
           Cart::getInstance().vectorSeats.replace(88, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H6"){
           Cart::getInstance().vectorSeats.replace(89, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H7"){
           Cart::getInstance().vectorSeats.replace(90, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H8"){
           Cart::getInstance().vectorSeats.replace(91, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H9"){
           Cart::getInstance().vectorSeats.replace(92, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H10"){
           Cart::getInstance().vectorSeats.replace(93, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H11"){
           Cart::getInstance().vectorSeats.replace(94, buttonSender->isChecked());
   }
    else if (buttonSender->text() == "H12"){
           Cart::getInstance().vectorSeats.replace(95, buttonSender->isChecked());
   }
}


void SeatAvailability::updateDisableSeats(QVector<bool> &vector)
{
    for (int i = 0; i < vector.size() ; i++ ) {
        if (vector.at(i)){
            switch (i) {
            case 0:
                ui->pushButton_A1->setDisabled(true);
                break;
            case 1:
                ui->pushButton_A2->setDisabled(true);
                break;
            case 2:
                ui->pushButton_A3->setDisabled(true);
                break;
            case 3:
                ui->pushButton_A4->setDisabled(true);
                break;
            case 4:
                ui->pushButton_A5->setDisabled(true);
                break;
            case 5:
                ui->pushButton_A6->setDisabled(true);
                break;
            case 6:
                ui->pushButton_A7->setDisabled(true);
                break;
            case 7:
                ui->pushButton_A8->setDisabled(true);
                break;
            case 8:
                ui->pushButton_A9->setDisabled(true);
                break;
            case 9:
                ui->pushButton_A10->setDisabled(true);
                break;
            case 10:
                ui->pushButton_A11->setDisabled(true);
                break;
            case 11:
                ui->pushButton_A12->setDisabled(true);
                break;
            case 12:
                ui->pushButton_B1->setDisabled(true);
                break;
            case 13:
                ui->pushButton_B2->setDisabled(true);
                break;
            case 14:
                ui->pushButton_B3->setDisabled(true);
                break;
            case 15:
                ui->pushButton_B4->setDisabled(true);
                break;
            case 16:
                ui->pushButton_B5->setDisabled(true);
                break;
            case 17:
                ui->pushButton_B6->setDisabled(true);
                break;
            case 18:
                ui->pushButton_B7->setDisabled(true);
                break;
            case 19:
                ui->pushButton_B8->setDisabled(true);
                break;
            case 20:
                ui->pushButton_B9->setDisabled(true);
                break;
            case 21:
                ui->pushButton_B10->setDisabled(true);
                break;
            case 22:
                ui->pushButton_B11->setDisabled(true);
                break;
            case 23:
                ui->pushButton_B12->setDisabled(true);
                break;
            case 24:
                ui->pushButton_C1->setDisabled(true);
                break;
            case 25:
                ui->pushButton_C2->setDisabled(true);
                break;
            case 26:
                ui->pushButton_C3->setDisabled(true);
                break;
            case 27:
                ui->pushButton_C4->setDisabled(true);
                break;
            case 28:
                ui->pushButton_C5->setDisabled(true);
                break;
            case 29:
                ui->pushButton_C6->setDisabled(true);
                break;
            case 30:
                ui->pushButton_C7->setDisabled(true);
                break;
            case 31:
                ui->pushButton_C8->setDisabled(true);
                break;
            case 32:
                ui->pushButton_C9->setDisabled(true);
                break;
            case 33:
                ui->pushButton_C10->setDisabled(true);
                break;
            case 34:
                ui->pushButton_C11->setDisabled(true);
                break;
            case 35:
                ui->pushButton_C12->setDisabled(true);
                break;
            case 36:
                ui->pushButton_D1->setDisabled(true);
                break;
            case 37:
                ui->pushButton_D2->setDisabled(true);
                break;
            case 38:
                ui->pushButton_D3->setDisabled(true);
                break;
            case 39:
                ui->pushButton_D4->setDisabled(true);
                break;
            case 40:
                ui->pushButton_D5->setDisabled(true);
                break;
            case 41:
                ui->pushButton_D6->setDisabled(true);
                break;
            case 42:
                ui->pushButton_D7->setDisabled(true);
                break;
            case 43:
                ui->pushButton_D8->setDisabled(true);
                break;
            case 44:
                ui->pushButton_D9->setDisabled(true);
                break;
            case 45:
                ui->pushButton_D10->setDisabled(true);
                break;
            case 46:
                ui->pushButton_D11->setDisabled(true);
                break;
            case 47:
                ui->pushButton_D12->setDisabled(true);
                break;
            case 48:
                ui->pushButton_E1->setDisabled(true);
                break;
            case 49:
                ui->pushButton_E2->setDisabled(true);
                break;
            case 50:
                ui->pushButton_E3->setDisabled(true);
                break;
            case 51:
                ui->pushButton_E4->setDisabled(true);
                break;
            case 52:
                ui->pushButton_E5->setDisabled(true);
                break;
            case 53:
                ui->pushButton_E6->setDisabled(true);
                break;
            case 54:
                ui->pushButton_E7->setDisabled(true);
                break;
            case 55:
                ui->pushButton_E8->setDisabled(true);
                break;
            case 56:
                ui->pushButton_E9->setDisabled(true);
                break;
            case 57:
                ui->pushButton_E10->setDisabled(true);
                break;
            case 58:
                ui->pushButton_E11->setDisabled(true);
                break;
            case 59:
                ui->pushButton_E12->setDisabled(true);
                break;
            case 60:
                ui->pushButton_F1->setDisabled(true);
                break;
            case 61:
                ui->pushButton_F2->setDisabled(true);
                break;
            case 62:
                ui->pushButton_F3->setDisabled(true);
                break;
            case 63:
                ui->pushButton_F4->setDisabled(true);
                break;
            case 64:
                ui->pushButton_F5->setDisabled(true);
                break;
            case 65:
                ui->pushButton_F6->setDisabled(true);
                break;
            case 66:
                ui->pushButton_F7->setDisabled(true);
                break;
            case 67:
                ui->pushButton_F8->setDisabled(true);
                break;
            case 68:
                ui->pushButton_F9->setDisabled(true);
                break;
            case 69:
                ui->pushButton_F10->setDisabled(true);
                break;
            case 70:
                ui->pushButton_F11->setDisabled(true);
                break;
            case 71:
                ui->pushButton_F12->setDisabled(true);
                break;
            case 72:
                ui->pushButton_G1->setDisabled(true);
                break;
            case 73:
                ui->pushButton_G2->setDisabled(true);
                break;
            case 74:
                ui->pushButton_G3->setDisabled(true);
                break;
            case 75:
                ui->pushButton_G4->setDisabled(true);
                break;
            case 76:
                ui->pushButton_G5->setDisabled(true);
                break;
            case 77:
                ui->pushButton_G6->setDisabled(true);
                break;
            case 78:
                ui->pushButton_G7->setDisabled(true);
                break;
            case 79:
                ui->pushButton_G8->setDisabled(true);
                break;
            case 80:
                ui->pushButton_G9->setDisabled(true);
                break;
            case 81:
                ui->pushButton_G10->setDisabled(true);
                break;
            case 82:
                ui->pushButton_G11->setDisabled(true);
                break;
            case 83:
                ui->pushButton_G12->setDisabled(true);
                break;
            case 84:
                ui->pushButton_H1->setDisabled(true);
                break;
            case 85:
                ui->pushButton_H2->setDisabled(true);
                break;
            case 86:
                ui->pushButton_H3->setDisabled(true);
                break;
            case 87:
                ui->pushButton_H4->setDisabled(true);
                break;
            case 88:
                ui->pushButton_H5->setDisabled(true);
                break;
            case 89:
                ui->pushButton_H6->setDisabled(true);
                break;
            case 90:
                ui->pushButton_H7->setDisabled(true);
                break;
            case 91:
                ui->pushButton_H8->setDisabled(true);
                break;
            case 92:
                ui->pushButton_H9->setDisabled(true);
                break;
            case 93:
                ui->pushButton_H10->setDisabled(true);
                break;
            case 94:
                ui->pushButton_H11->setDisabled(true);
                break;
            case 95:
                ui->pushButton_H12->setDisabled(true);
                break;

            }
        }
    }
}
