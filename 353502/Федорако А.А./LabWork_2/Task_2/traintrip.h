#ifndef TRAINTRIP_H
#define TRAINTRIP_H
#include <QString>
#include <QDateTime>

class TrainTrip
{
public:
    TrainTrip();
    void setFlightNumber(QString newFlightNumber);
    QString getFlightNumber();
    void setTimeDeparture(QDateTime newTimeDeparture);
    QDateTime getTimeDeparture();
    void setTimeArrival(QDateTime newTimeArrival);
    QDateTime getTimeArrival();

    void setFinalDestination(QString newFinalDestination);
    QString getFinalDestination();

    void setNumberOfCompartmentsSeats(int newNumberOfCompartmentSeats);
    int getNumberOfCompartmentSeats();

    void setNumberOfReservedSeats(int newNumberOfReservedSeats);
    int getNumberOfReservedSeats();

    void setNumberOfFreeCompartmentsSeats(int newNumberOfFreeCompartmentsSeats);
    int getNumberOfFreeCompartmentSeats();

    void setNumberOfFreeReservedSeats(int newNumberOfFreeReservedSeats);
    int getNumberOfFreeReservedSeats();
private:
    QString flightNumber;
    QDateTime timeDeparture;
    QDateTime timeArrival;
    QString finalDestination;
    int numberOfCompartmentsSeats;
    int numberOfReservedSeats;
    int numberOfFreeCompartmentsSeats;
    int numberOfFreeReservedSeats;
};

#endif // TRAINTRIP_H
