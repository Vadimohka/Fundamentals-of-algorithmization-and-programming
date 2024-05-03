#include <QString>

#ifndef DISH_H
#define DISH_H

class Dish
{
private:
    QString dishName;
    QString discription;
    double price;
public:
    Dish(QString name, QString discription, double price);

    QString getName();
    QString getDiscription();
    double getPrice();

};


#endif // DISH_H