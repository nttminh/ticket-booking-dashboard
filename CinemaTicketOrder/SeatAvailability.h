#ifndef SEATAVAILABILITY_H
#define SEATAVAILABILITY_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include "Cart.h"

namespace Ui {
class SeatAvailability;
}

class SeatAvailability : public QDialog
{
    Q_OBJECT

public:
    explicit SeatAvailability(QWidget *parent = nullptr);
    ~SeatAvailability();

private slots:
    void chooseSeat();
    void on_pushButton_clicked();
    void updateSeatAvailable(int movieIndex, int timeSlot);
    void updateDisableSeats(QVector<bool> &vector);
    QVector<bool> toVectorBool(const QByteArray& buffer);
    void connectAllButtonToFunction();

private:
    Ui::SeatAvailability *ui;
    std::vector<QString> moviesId;
    std::vector<QString> moviesName;
    std::vector<QString> moviesPath;
    QSqlDatabase mydb;
};

#endif // SEATAVAILABILITY_H
