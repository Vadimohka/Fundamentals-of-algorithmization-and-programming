#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
public:
  Date(int day, int month, int year);

  int day() const;
  int month() const;
  int year() const;

  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);

  // methods
  Date nextDay() const;
  Date previousDay() const;
  short weekNumber() const;
  short dayOfWeek() const;
  QString tillBday(Date bday) const;
  static Date today();

  // static bool isStringValid(QString word);
  bool isDateValid() const;
  static Date stringToDate(QString word);
  static QString dateToString(Date date);
  static QString weekdayToString(int weekday);
  static int duration(Date date1, Date date2);

private:
    short day_;
    short month_;
    short year_;

    int daysInMonth[12];

    int getMonthLength();
    int absDuration();
    static bool isLeapYear(int year);

};

#endif // DATE_H
