#ifndef TRAINS_H
#define TRAINS_H
#include <QDateTime>
#include <QString>

class Trains
{
 private:
  QDate departureDate;
  int trainNumber;
  QString destination;
  QTime departureTime;
  int totalSeats;
  int freeSeats;

 public:
  Trains();

  // Функции чтения
  QDate getDepartureDate() const;

  int getTrainNumber() const;

  QString getDestination() const;

  QTime getDepartureTime() const;

  int getTotalSeats() const;

  int getFreeSeats() const;

  // Функции записи
  void setDepartureDate(const QDate& date);

  void setTrainNumber(const int number);

  void setDestination(const QString& dest);

  void setDepartureTime(const QTime& time);

  void setTotalSeats(int seats);

  void setFreeSeats(int seats);
};

#endif  // TRAINS_H
