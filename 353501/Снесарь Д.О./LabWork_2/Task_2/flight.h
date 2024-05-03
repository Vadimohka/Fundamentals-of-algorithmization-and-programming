#ifndef FLIGHT_H
#define FLIGHT_H


#include <QString>
#include <QDateTime>

class Flight
{
private:
    int flightNumber;
    QString destination;
    double distance;
    QString type;
    QDateTime arriveTime;
    QDateTime departureTime;
public:
    Flight(int flightNumber,  QString destination, double distance,    QString type, QDateTime arriveTime, QDateTime departureTime);
    double getFuel(double fuelCons) const;
    QString getFullInfo() const;
    QString getInfo() const;

    QString getDestination () const;
    double getDistance() const;
    QDateTime getDepartureTime() const;
    QDateTime getArriveTime () const;
    int getFlightNumber() const;
    QString getType() const;

};

#endif // FLIGHT_H
