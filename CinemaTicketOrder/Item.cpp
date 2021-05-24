#include "Item.h"

Item::Item(){
    this->name = "Unknown";
    this->price = 0;
}

Item::Item(QString name, double price){
    this->name = name;
    this->price = price;
}

QString Item::getName() const
{
    return name;
}

void Item::setName(const QString &value)
{
    name = value;
}

double Item::getPrice() const
{
    return price;
}

void Item::setPrice(double value)
{
    price = value;
}


bool Item::operator!=(const Item &item)
{
    if(this->price!=item.price){
        return true;
    }
    else
        return false;
}

bool Item::operator==(const Item &item)
{
    if(this->price==item.price){
        return true;
    }
    else
        return false;
}
