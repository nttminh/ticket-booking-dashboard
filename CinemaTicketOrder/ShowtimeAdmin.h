#ifndef SHOWTIMEADMIN_H
#define SHOWTIMEADMIN_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class ShowtimeAdmin;
}

class ShowtimeAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit ShowtimeAdmin(QWidget *parent = nullptr);
    ~ShowtimeAdmin();
    void updateTable();
    void removeMovie();
    void addImageToDatabase();
    QByteArray toByteArray(const QVector<bool>& data);
    QByteArray toByteArray(const QPixmap &data);

private slots:
    void on_btn_choosePhoto_clicked();

    void on_btn_addMovie_clicked();

    void on_btn_removeMovie_clicked();

    void on_pushButton_export_clicked();

private:
    Ui::ShowtimeAdmin *ui;
    QSqlDatabase mydb;
    QPixmap moviePhoto;
};

#endif // SHOWTIMEADMIN_H
