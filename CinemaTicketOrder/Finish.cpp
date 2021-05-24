#include "Finish.h"
#include "ui_Finish.h"

Finish::Finish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Finish)
{
    ui->setupUi(this);
    ui->label_time->setText(QDateTime::currentDateTime().toString());
    ui->label_ticketCost->setText(QString::number(Cart::getInstance().getTicketSold() * 10));
    ui->label_foodCost->setText(QString::number(Cart::getInstance().getFoodCost()));
    ui->label_totalCost->setText(QString::number(Cart::getInstance().getTicketSold() * 10 + Cart::getInstance().getFoodCost()));
}

Finish::~Finish()
{
    delete ui;
}
