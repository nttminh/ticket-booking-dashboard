#include "Customer.h"

Customer::Customer(QString username, QString password) : Account(username, password)
{

}


void Customer::addToDatabase(QSqlDatabase mydb)
{
    mydb.open();
    QSqlQuery query;
    query.prepare("INSERT INTO accounts(username, password, accessLevel) VALUES(?, ?, " + QString::number(accessLevel) + ")");
    query.addBindValue(getUsername());
    query.addBindValue(getPassword());
    QMessageBox msgBox;
    if (query.exec()){
        msgBox.setText("Account created successfully");
        msgBox.exec();
    } else {
        msgBox.setText("Failed to create account. " + query.lastError().text());
        msgBox.exec();
    }
    mydb.close();
}
