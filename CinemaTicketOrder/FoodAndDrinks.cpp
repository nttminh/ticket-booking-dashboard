#include "FoodAndDrinks.h"
#include "ui_FoodAndDrinks.h"
#include "Finish.h"

FoodAndDrinks::FoodAndDrinks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodAndDrinks)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString db_path = QDir::currentPath();
    db_path =  db_path + QString("/database.db");
    mydb.setDatabaseName(db_path);

    connectAllButtonToSlot();
}

FoodAndDrinks::~FoodAndDrinks()
{
    delete ui;
}

void FoodAndDrinks::on_pushButton_clicked()
{

}

void FoodAndDrinks::chooseItem(int index)
{
    QString itemName = indexToName(index);
    double itemPrice = indexToPrice(index);

    // use overloaded operator here
    Item item(itemName,itemPrice);


    Cart::getInstance().setFoodCost(Cart::getInstance().getFoodCost() + itemPrice);

    ui->label_foodCost->setText(QString::number(Cart::getInstance().getFoodCost()));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,0,new QTableWidgetItem(itemName));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,1,new QTableWidgetItem(QString::number(itemPrice)));
}

void FoodAndDrinks::clearAll(){
    Cart::getInstance().setFoodCost(0.00);
    ui->label_foodCost->setText(QString::number(Cart::getInstance().getFoodCost()));

    while (ui->tableWidget->rowCount() > 0){
        ui->tableWidget->removeRow(0);
    }
}

void FoodAndDrinks::checkOut()
{
    QString movieName;
    int updateTicket = Cart::getInstance().getTicketSoldInDataBase() + Cart::getInstance().getTicketSold();
    double updateFood = Cart::getInstance().getFoodSoldInDataBase() + Cart::getInstance().getFoodCost();
    int movieIDInDatabase = Cart::getInstance().getMovieIDInDatabase();

    QString updateSeatQuery;
    switch (Cart::getInstance().getTimeSlot()) {
        case 0:
            updateSeatQuery = "theaterA=";
            break;
        case 1:
            updateSeatQuery = "theaterB=";
            break;
        case 2:
            updateSeatQuery = "theaterC=";
            break;
        case 3:
            updateSeatQuery = "theaterD=";
            break;
        case 4:
            updateSeatQuery = "theaterE=";
            break;
    }

    mydb.open();
    QSqlQuery *query = new QSqlQuery(mydb);
        query->prepare("UPDATE movies SET ticketSold=?, foodSold='" + QString::number(updateFood) + "'"
                        ", " + updateSeatQuery + "=?                    WHERE movieId='" + QString::number(movieIDInDatabase) + "' ");
        query->addBindValue(updateTicket);
        query->addBindValue(toByteArray(Cart::getInstance().vectorSeats));
        qDebug() << "Ticket sold in db = " << Cart::getInstance().getTicketSoldInDataBase();
        qDebug() << "Ticket sold in this session = " << Cart::getInstance().getTicketSold();
        qDebug() << "Food sold in db = " << Cart::getInstance().getFoodSoldInDataBase();
        qDebug() << "Food sold in this session = " << Cart::getInstance().getFoodCost();

        if(!query->exec())
        {
            QMessageBox::critical(this,"Error","Couldn't insert data");
            qDebug() << query->lastError();
        }
    mydb.close();

    Finish *finish = new Finish();
    hide();
    finish->show();
}

QByteArray FoodAndDrinks::toByteArray(const QVector<bool> &data){
      QByteArray result;
      QDataStream bWrite( &result, QIODevice::WriteOnly );
      bWrite << data;

      return result;
}


QString FoodAndDrinks::indexToName(int index){
    switch (index) {
        case 0:
            return "Traditional Popcorn";
        case 1:
            return "Kids Pack Popcorn";
        case 2:
            return "Coke";
        case 3:
            return "ICEE";
        case 4:
            return "Bottled Drinks";
        case 5:
            return "Costa Coffee";
        case 6:
            return "Chicken Tenders";
        case 7:
            return "Curly Fries";
        case 8:
            return "Ice Cream";
        case 9:
            return "Gluten Free Snacks";
        case 10:
            return "Candy";
        case 11:
            return "Special: Wonder Woman 1984";
        case 12:
            return "Cameo Party Pack";
        case 13:
            return "Kids Party Pack";
        case 14:
            return "Tenders & Fries Pack";
    }
}

double FoodAndDrinks::indexToPrice(int index){
    switch (index) {
        case 0:
            return 8.79;
        case 1:
            return 7.09;
        case 2:
            return 6.49;
        case 3:
            return 6.99;
        case 4:
            return 4.99;
        case 5:
            return 1.00;
        case 6:
            return 8.29;
        case 7:
            return 5.99;
        case 8:
            return 4.69;
        case 9:
            return 6.29;
        case 10:
            return 4.89;
        case 11:
            return 11.99;
        case 12:
            return 79.99;
        case 13:
            return 49.99;
        case 14:
            return 79.99;
        default:
            return 0;
    }
}

void FoodAndDrinks::connectAllButtonToSlot()
{


    QPushButton *button = ui->pushButton_traditional;
    ui->pushButton_traditional->setProperty("myId",0);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_kidsPacks;
    ui->pushButton_kidsPacks->setProperty("myId",1);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_coke;
    ui->pushButton_coke->setProperty("myId",2);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_ICEE;
    ui->pushButton_ICEE->setProperty("myId",3);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_bottledDrinks;
    ui->pushButton_bottledDrinks->setProperty("myId",4);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_costaCoffee;
    ui->pushButton_costaCoffee->setProperty("myId",5);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_chickenTenders;
    ui->pushButton_chickenTenders->setProperty("myId",6);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_curlyFries;
    ui->pushButton_curlyFries->setProperty("myId",7);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_iceCream;
    ui->pushButton_iceCream->setProperty("myId",8);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_glutenFreeSnacks;
    ui->pushButton_glutenFreeSnacks->setProperty("myId",9);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_candy;
    ui->pushButton_candy->setProperty("myId",10);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_wonderWoman;
    ui->pushButton_wonderWoman->setProperty("myId",11);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_cameoPartyPack;
    ui->pushButton_cameoPartyPack->setProperty("myId",12);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_kidsPartyPack;
    ui->pushButton_kidsPartyPack->setProperty("myId",13);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });

    button = ui->pushButton_tendersFriesPack;
    ui->pushButton_tendersFriesPack->setProperty("myId",14);
    connect(button, &QPushButton::clicked, [this, button](){
        chooseItem(button->property("myId").toInt());
    });
}



void FoodAndDrinks::on_pushButton_clearAll_clicked()
{
    clearAll();
}

void FoodAndDrinks::on_pushButton_checkOut_clicked()
{
    checkOut();
}
