#include "Cart.h"

Cart::Cart()
{

}

double Cart::getFoodSoldInDataBase() const
{
    return foodSoldInDataBase;
}

void Cart::setFoodSoldInDataBase(double value)
{
    foodSoldInDataBase = value;
}

int Cart::getTicketSoldInDataBase() const
{
    return ticketSoldInDataBase;
}

void Cart::setTicketSoldInDataBase(int value)
{
    ticketSoldInDataBase = value;
}

int Cart::getMovieIDInDatabase() const
{
    return movieIDInDatabase;
}

void Cart::setMovieIDInDatabase(int value)
{
    movieIDInDatabase = value;
}

double Cart::getFoodCost() const
{
    return foodCost;
}

void Cart::setFoodCost(double value)
{
    foodCost = value;
}

int Cart::getTicketSold()
{
    int ticketSold = 0;
    for (int i = 0; i < vectorSeats.size(); i++){
        if (vectorSeats.at(i)) {
            ticketSold++;
        }
    }
    return ticketSold - getTicketSoldInDataBase();
}

int Cart::getMovieIDChosen() const
{
    return movieIDChosen;
}

void Cart::setMovieIDChosen(int value)
{
    movieIDChosen = value;
    qDebug() << "Cart MovieID chosen: " << movieIDChosen;
}

Cart &Cart::getInstance()
{
    /*
    if(!instance) {
        instance = new Singleton();
        cout << "getInstance(): First instance\n";
        return instance;
    }
    else {
        cout << "getInstance(): previous instance\n";
        return instance;
    }
     */
    static Cart instance;
    return instance;
}

int Cart::getTimeSlot()
{
    return timeSlot;
}

bool Cart::setTimeSlot(int tS)
{
    timeSlot = tS;
    qDebug() << "Time slot: " << timeSlot;
    return true;
}
