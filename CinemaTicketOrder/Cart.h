#ifndef CART_H
#define CART_H

#include <QObject>
#include <QDebug>

class Cart
{
public:
    Cart(const Cart&) = delete;

    static Cart& getInstance();

    QVector<bool> vectorSeats; // will sync with vector seats in seatAvalibility > updateSeatAvailable
    int getTimeSlot();
    bool setTimeSlot(int tS);



    int getMovieIDChosen() const;
    double getFoodCost() const;
    void setFoodCost(double value);
    int getTicketSold();

    int getMovieIDInDatabase() const;
    void setMovieIDInDatabase(int value);

    int getTicketSoldInDataBase() const;
    void setTicketSoldInDataBase(int value);

    double getFoodSoldInDataBase() const;
    void setFoodSoldInDataBase(double value);

private:
    Cart();

    int movieIDInDatabase;
    int ticketSoldInDataBase;
    double foodSoldInDataBase;

    int timeSlot;
    int movieIDChosen;
    double foodCost = 0;

public slots:
    void setMovieIDChosen(int value);

};

#endif // CART_H
