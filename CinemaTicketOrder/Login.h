#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "Admin.h"
#include "Customer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_pushButton_register_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_register_admin_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase mydb;
    Customer* customer;
    Admin* admin;

};
#endif // LOGIN_H
