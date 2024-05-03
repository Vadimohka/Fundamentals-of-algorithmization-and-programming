#ifndef ORDER_H
#define ORDER_H

#include <QVector>
#include <QString>
#include <QPair>

class Order
{
public:
    Order();

public:

    long long TableNumber;
    QVector < QString > Dishes;
    QVector < long long > Ammount;
    QVector < long long > Price;
    long long TotalPrice = 0;

public:

    void setValue( long long newTable , QString newDish , long long newAmmount , long long newPrice );
    QString getDishes();
    long long getTable();
    long long getTotalPrice();


};

#endif // ORDER_H
