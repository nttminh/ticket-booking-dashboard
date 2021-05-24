#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.h"
#include <QObject>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtWidgets>
#include <QSqlError>


class Customer : public Account
{
public:
    Customer();
    Customer(QString username, QString password);
    void addToDatabase(QSqlDatabase) override;
private:
    int accessLevel = 1;
};

#endif // CUSTOMER_H
