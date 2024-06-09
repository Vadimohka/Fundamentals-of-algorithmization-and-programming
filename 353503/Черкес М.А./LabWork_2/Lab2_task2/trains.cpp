#include "trains.h"

Trains::Trains() = default;

QDate Trains::getDepartureDate() const {
  return departureDate;
}

int Trains::getTrainNumber() const {
  return trainNumber;
}

QString Trains::getDestination() const {
  return destination;
}

QTime Trains::getDepartureTime() const {
  return departureTime;
}

int Trains::getTotalSeats() const {
  return totalSeats;
}

int Trains::getFreeSeats() const {
  return freeSeats;
}

void Trains::setDepartureDate(const QDate& date) {
  departureDate = date;
}

void Trains::setTrainNumber(const int number) {
  trainNumber = number;
}

void Trains::setDestination(const QString& dest) {
  destination = dest;
}

void Trains::setDepartureTime(const QTime& time) {
  departureTime = time;
}

void Trains::setTotalSeats(int seats) {
  totalSeats = seats;
}

void Trains::setFreeSeats(int seats) {
  freeSeats = seats;
}
