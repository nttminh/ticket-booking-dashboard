#include "Login.h"
#include "ui_Login.h"
#include "Showtime.h"
#include "ShowtimeAdmin.h"
#include "QMessageBox"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QDir>
#include "Admin.h"
#include "Customer.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix(":/img/cinema.png");
    int w = ui->label_picture->width();
    int h = ui->label_picture->height();
    ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    connect(ui->lineEdit_password, SIGNAL(returnPressed()),ui->pushButton_login,SIGNAL(clicked()));

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString db_path = QDir::currentPath();
    db_path =  db_path + QString("/database.db");
    mydb.setDatabaseName(db_path);

    // code below to test run the database connection
    mydb.open();
    if (!mydb.isOpen()) {
        qDebug()<<"setup stage: failed to connect to database";
    } else {
        qDebug() <<"Successfully connect to database";
    }
    mydb.close();
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    mydb.open();

    QSqlQuery query;
    if (query.exec("SELECT * FROM accounts WHERE username ='" + username + "' and password ='" + password + "'")) {
        int count = 0;
        int accessLevel = -1;
        while (query.next()) {
            count++;
            QSqlRecord accountRecord = query.record();
            accessLevel = accountRecord.value(3).toInt();
        }

        if(count != 0){
            if (accessLevel == 0){
                hide();
                ShowtimeAdmin* showtimeAdmin = new ShowtimeAdmin();
                showtimeAdmin->show();
            } else {
                hide();
                Showtime* showtime = new Showtime();
                showtime->show();
            }
        } else {
            QMessageBox::warning(this, "Wrong credentials", "Username or password is incorrect");
        }
    } else {
        qDebug()<< "SQL Query Error: " << query.lastError().text();
    }


    mydb.close();
}


void Login::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    Customer customer(username, password);
    customer.addToDatabase(mydb);
}

void Login::on_pushButton_register_admin_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    Admin admin(username, password);
    admin.addToDatabase(mydb);
}
