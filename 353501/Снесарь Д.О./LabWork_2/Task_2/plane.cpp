#include "plane.h"

Plane::Plane(QString type, int productionYear, double fuelCons)
{
    this->type = type;
    this->productionYear = productionYear;
    this->fuelCons = fuelCons;
}

QString Plane::getFullInfo() const
{
    QString resultS;
    resultS = "Plane type: " + type + "\n" +
              "Year of producrion: " + QString::number(productionYear) + "\n" +
              "Fuel cons: " + QString::number(fuelCons) + "\n" ;

    return resultS;
}

QString Plane::getTypeString() const
{
    return type;
}

double Plane::getFuelCons() const
{
    return fuelCons;
}
