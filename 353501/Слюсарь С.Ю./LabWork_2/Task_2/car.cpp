#include "car.h"
Car::Car() {}


//Geters
QString Car::getCountry() const
{
    return country;
}
QString Car::getMark() const
{
    return mark;
}
QString Car::getEngineType() const
{
    return engineType;
}
int Car::getPrice() const
{
    return price;
}
int Car::getGasolineSpend() const
{
    return gasolineSpend;
}
int Car::getReliability() const
{
    return reliability;
}
int Car::getComfortability() const
{
    return comfortability;
}


//Seters
void Car::setCountry(const QString &newCountry)
{
    country = newCountry;
}
void Car::setMark(const QString &newMark)
{
    mark = newMark;
}
void Car::setEngineType(const QString &newEngineType)
{
    engineType = newEngineType;
}
void Car::setPrice(int newPrice)
{
    price = newPrice;
}
void Car::setGasolineSpend(int newGasolineSpend)
{
    gasolineSpend = newGasolineSpend;
}
void Car::setReliability(int newReliability)
{
    reliability = newReliability;
}
void Car::setComfortability(int newComfortability)
{
    comfortability = newComfortability;
}

QString Car::getModel() const
{
    return model;
}

void Car::setModel(const QString &newModel)
{
    model = newModel;
}
