#include "dish.h"

Dish::Dish(QString _name, double _price)
{
    name = _name;
    price = _price;
}

Dish::Dish(QString input)
{
    QString _name = "";
    QString _price = "";
    int i = 0;
    while(input[i] != ' '){
        _name.append(input[i]);
        i++;
    }
    i++;
    while(i < input.size()){
        _price.append(input[i]);
        i++;
    }

    name = _name;
    price = _price.toDouble();
}


void Dish::setName(QString _name)
{
    name = _name;
}

void Dish::setPrice(double _price)
{
    price = _price;
}

QString Dish::getName()
{
    return name;
}

double Dish::getPrice()
{
    return price;
}


