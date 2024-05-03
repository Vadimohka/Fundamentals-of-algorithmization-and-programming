#include <QString>

#ifndef ORDER_H
#define ORDER_H

class Order
{
private:
    QString dishName;
    int orderNumber;
    int tableNumber;
    int dishNumber;
public:
    Order(QString name, int orderNumber, int tableNumber, int dishNumber);

    QString getName();
    int getOrderNumber();
    int getTableNumber();
    int getDishNumber();

};


#endif // ORDER_H