#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class Account : public QObject
{
    Q_OBJECT

private:
    QString username;
    QString password;
    int accessLevel;

public:
    Account(QString username, QString password);
    QString getUsername();
    void setUsername(QString username);
    QString getPassword();
    void setPassword(QString password);
    bool isEqual(QString username, QString password);
    bool isAdmin();
    virtual void addToDatabase(QSqlDatabase mydb) = 0;

signals:

};

#endif // ACCOUNT_H
