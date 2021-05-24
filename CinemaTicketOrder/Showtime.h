#ifndef SHOWTIME_H
#define SHOWTIME_H

#include <QDialog>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHash>
#include <QFile>
#include <QSqlDatabase>
#include <QPushButton>
#include <QButtonGroup>
#include <QSqlQuery>
#include <QDir>
#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include "Customer.h"
#include "Cart.h"


namespace Ui {
class Showtime;
}

class Showtime : public QDialog
{
    Q_OBJECT

private:
    QHash<QGroupBox*, QHBoxLayout*> mButtonToLayoutMap;

public:
    explicit Showtime(QWidget *parent = nullptr);
    ~Showtime();
    void setAllPosters(int index);
    void setPoster(int posterNumber, QString path);
    void getMovies();
    void onAddWidgets(int movieID, QString name, int length, int timeSlot, QPixmap img);
    void updateShowtime();
    QString toHourMinute(int minute);
    QPixmap toPixmap(const QByteArray& buffer);

private slots:
    void implementButton();
    void setMovieIDChosen(int id);
private:
    Ui::Showtime *ui;
    QSqlDatabase mydb;

};

#endif // SHOWTIME_H
