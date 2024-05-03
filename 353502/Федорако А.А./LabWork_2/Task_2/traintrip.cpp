#include "traintrip.h"

TrainTrip::TrainTrip()
{

}

QString TrainTrip::getFinalDestination() {
    return finalDestination;
}

QString TrainTrip::getFlightNumber() {
    return flightNumber;
}
int TrainTrip::getNumberOfCompartmentSeats() {
    return numberOfCompartmentsSeats;
}

int TrainTrip::getNumberOfFreeCompartmentSeats() {
    return numberOfFreeCompartmentsSeats;
}

int TrainTrip::getNumberOfReservedSeats() {
    return numberOfReservedSeats;
}

int TrainTrip::getNumberOfFreeReservedSeats() {
    return numberOfFreeReservedSeats;
}

QDateTime TrainTrip::getTimeArrival() {
    return timeArrival;
}

QDateTime TrainTrip::getTimeDeparture() {
    return timeDeparture;
}

void TrainTrip::setFinalDestination(QString newFinalDestination) {
    finalDestination = newFinalDestination;
}

void TrainTrip::setFlightNumber(QString newFlightNumber) {
    flightNumber = newFlightNumber;
}

void TrainTrip::setNumberOfCompartmentsSeats(int newNumberOfCompartmentSeats) {
    numberOfCompartmentsSeats = newNumberOfCompartmentSeats;
}

void TrainTrip::setNumberOfFreeCompartmentsSeats(int newNumberOfFreeCompartmentsSeats) {
    numberOfFreeCompartmentsSeats = newNumberOfFreeCompartmentsSeats;
}

void TrainTrip::setNumberOfFreeReservedSeats(int newNumberOfFreeReservedSeats) {
    numberOfFreeReservedSeats = newNumberOfFreeReservedSeats;
}

void TrainTrip::setNumberOfReservedSeats(int newNumberOfReservedSeats) {
    numberOfReservedSeats = newNumberOfReservedSeats;
}

void TrainTrip::setTimeArrival(QDateTime newTimeArrival) {
    timeArrival = newTimeArrival;
}

void TrainTrip::setTimeDeparture(QDateTime newTimeDeparture) {
    timeDeparture = newTimeDeparture;
}

