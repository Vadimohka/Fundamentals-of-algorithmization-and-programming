#ifndef DISH_H
#define DISH_H
#include <QString>

class Dish
{
public:
    Dish(QString, double);

    Dish(QString);

    void setName(QString);

    void setPrice(double);

    QString getName();

    double getPrice();


private:
    QString name;
    double price;




};

#endif // DISH_H
