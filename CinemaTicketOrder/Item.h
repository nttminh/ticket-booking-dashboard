#ifndef ITEM_H
#define ITEM_H

#include <QObject>

class Item : QObject
{
    Q_OBJECT
public:
    Item();
    Item(QString name, double price);

    QString getName() const;
    void setName(const QString &value);

    double getPrice() const;
    void setPrice(double value);

    bool operator!=(const Item& item);
    bool operator==(const Item& item);

private:
    QString name;
    double price;
};

#endif // ITEM_H
