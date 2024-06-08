#include "menu.h"

Menu::Menu(QString name, QString discription, double price) : dishName(name), discription(discription), price(price) {

      };

QString Menu::getDishName(){
    return dishName;
}

QString Menu::getDiscription(){
    return discription;
}

double Menu::getPrice(){
    return price;
}
