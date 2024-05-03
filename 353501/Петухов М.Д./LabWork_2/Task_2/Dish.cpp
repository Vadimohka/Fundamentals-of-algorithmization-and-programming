#include "Dish.h"

Dish::Dish(QString name, QString discription, double price) : dishName(name), discription(discription), price(price) {

};

QString Dish::getName(){
    return dishName;
}

QString Dish::getDiscription(){
    return discription;
}

double Dish::getPrice(){
    return price;
}
