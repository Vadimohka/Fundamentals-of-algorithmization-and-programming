#include "mydate.h"
#include "QDebug"

MyDate::MyDate(int year, int month, int day) : date(day, month, year) {}

MyDate MyDate::NextDay() {
  return {date.addDays(1).day(), date.addDays(1).month(),
          date.addDays(1).year()};
}

MyDate MyDate::PreviousDay() {
  return {date.addDays(-1).day(), date.addDays(-1).month(),
          date.addDays(-1).year()};
}

bool MyDate::IsLeap() {
  return QDate::isLeapYear(date.year());
}

int MyDate::WeekNumber() {
  return date.weekNumber();
}

int MyDate::DaysTillYourBirthday(MyDate birthdayDate) {
  return date.daysTo(QDate(birthdayDate.date.day(), birthdayDate.date.month(),
                           birthdayDate.date.year()));
}

int MyDate::Duration(MyDate otherDate) {
  if (otherDate.date.month() < date.month() ||
      (otherDate.date.month() == date.month() &&
       otherDate.date.day() < date.day())) {
    return date.daysTo(otherDate.date.addYears(1));
  }
  return date.daysTo(otherDate.date);
}

QString MyDate::GetDateAsString() const{
  return date.toString("dd.MM.yyyy");
}

