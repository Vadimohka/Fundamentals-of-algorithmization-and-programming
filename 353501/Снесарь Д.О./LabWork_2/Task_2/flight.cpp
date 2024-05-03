#include "flight.h"


Flight::Flight(int flightNumber, QString destination, double distance, QString type, QDateTime arriveTime, QDateTime departureTime)
{
    this->flightNumber = flightNumber;
    this->destination = destination;
    this->distance = distance;
    this->type = type;
    this->arriveTime = arriveTime;
    this->departureTime = departureTime;
}

double Flight::getFuel(double fuelCons) const
{
    return fuelCons * distance;
}

QString Flight::getFullInfo() const
{
    QString resultS;
    resultS = "Flight number: " + QString::number(flightNumber) + "\n" +
             "Destination: " + destination + "\n" +
             "Distance: " + QString::number(distance, 'f' , 2) + "\n" +
             "Plane type: " + type + "\n" +
             "Arrivie time: " + departureTime.toString("hh:mm:ss") + "\n" +
             "Arrivie time: " + arriveTime.toString("hh:mm:ss");

    return resultS;
}

QString Flight::getInfo() const
{
    QString resultS;
    resultS =  QString::number(flightNumber) + "\n" +
               destination + "\n" +
               QString::number(distance, 'f' , 2) + "\n" +
               type + "\n" +
               departureTime.toString("hh:mm:ss") + "\n" +
               arriveTime.toString("hh:mm:ss");

    return resultS;
}

QString Flight::getDestination() const
{
    return destination;
}

double Flight::getDistance() const
{
    return distance;
}

QDateTime Flight::getDepartureTime() const
{
    return departureTime;
}

QDateTime Flight::getArriveTime() const
{
    return arriveTime;
}

int Flight::getFlightNumber() const
{
    return flightNumber;
}

QString Flight::getType() const
{
    return type;
}
