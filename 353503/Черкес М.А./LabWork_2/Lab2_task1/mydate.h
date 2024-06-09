#ifndef MYDATE_H
#define MYDATE_H
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include "QDate"

class MyDate {

 public:
  QDate date;

  MyDate(int year, int month, int day);

  MyDate NextDay();

  MyDate PreviousDay();

  bool IsLeap();

  int WeekNumber();

  int DaysTillYourBirthday(MyDate birthdayDate);

  int Duration(MyDate otherDate);

  QString GetDateAsString() const;

};

#endif  // MYDATE_H
