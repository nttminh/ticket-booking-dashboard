#ifndef FINISH_H
#define FINISH_H

#include <QDialog>
#include <QDateTime>
#include "Cart.h"

namespace Ui {
class Finish;
}

class Finish : public QDialog
{
    Q_OBJECT

public:
    explicit Finish(QWidget *parent = nullptr);
    ~Finish();

private:
    Ui::Finish *ui;
};

#endif // FINISH_H
