#ifndef FOODANDDRINKS_H
#define FOODANDDRINKS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDir>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "Cart.h"
#include "Item.h"

namespace Ui {
class FoodAndDrinks;
}

class FoodAndDrinks : public QDialog
{
    Q_OBJECT

public:
    explicit FoodAndDrinks(QWidget *parent = nullptr);
    ~FoodAndDrinks();

private slots:
    void on_pushButton_clicked();
    void chooseItem(int item);
    QString indexToName(int index);
    double indexToPrice(int index);
    void connectAllButtonToSlot();
    void clearAll();
    void checkOut();
    QByteArray toByteArray(const QVector<bool> &data);

    void on_pushButton_clearAll_clicked();

    void on_pushButton_checkOut_clicked();

private:
    Ui::FoodAndDrinks *ui;
    QSqlDatabase mydb;
};

#endif // FOODANDDRINKS_H
