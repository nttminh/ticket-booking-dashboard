#ifndef ADMIN_H
#define ADMIN_H

#include "Account.h"


class Admin : public Account
{
public:
    Admin(QString username, QString password);
    void addToDatabase(QSqlDatabase mydb) override;
private:
    int accessLevel = 0;
};

#endif // ADMIN_H
