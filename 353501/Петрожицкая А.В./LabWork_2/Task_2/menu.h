#include <QString>

#ifndef DISH_H
#define DISH_H

class Menu
{
private:
    QString dishName;
    QString discription;
    double price;
public:
    Menu(QString name, QString discription, double price);

    QString getDishName();
    QString getDiscription();
    double getPrice();

};


#endif // DISH_H
