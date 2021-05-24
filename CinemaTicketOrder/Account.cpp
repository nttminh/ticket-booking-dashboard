#include "Account.h"


Account::Account(QString username, QString password)
{
    this->username = username;
    this->password = password;
}

QString Account::getUsername()
{
    return this->username;
}

void Account::setUsername(QString username)
{
    this->username = username;
}

QString Account::getPassword()
{
    return this->password;
}

void Account::setPassword(QString password)
{
    this->password = password;
}

bool Account::isAdmin()
{
    if (accessLevel == 0) {
        return true;
    } else {
        return false;
    }
}


