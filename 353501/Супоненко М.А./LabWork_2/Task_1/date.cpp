#include "date.h"
#include <iostream>
#include <QString>

// Constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Determine if a year is a leap year
bool Date::IsLeap() {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return true;
  return false;
}

// Calculate the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
short Date::WeekNumber() {
  short ned = 4*(month-1) + day/7;
  return ned+1;
}

// Calculate the date of the next day
Date Date::NextDay() {
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (IsLeap())
    daysInMonth[2] = 29;

  int nextDay = day + 1;
  int nextMonth = month;
  int nextYear = year;

  if (nextDay > daysInMonth[month]) {
    nextDay = 1;
    nextMonth++;
    if (nextMonth > 12) {
      nextMonth = 1;
      nextYear++;
    }
  }

  return Date(nextDay, nextMonth, nextYear);
}

// Calculate the date of the previous day
Date Date::PreviousDay() {
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (IsLeap())
    daysInMonth[2] = 29;

  int prevDay = day - 1;
  int prevMonth = month;
  int prevYear = year;

  if (prevDay == 0) {
    prevMonth--;
    if (prevMonth == 0) {
      prevMonth = 12;
      prevYear--;
    }
    prevDay = daysInMonth[prevMonth];
  }

  return Date(prevDay, prevMonth, prevYear);
}

bool Date::isLess(Date n) {
  if (year < n.year)
    return true;
  if (year > n.year)
    return false;

  if (month < n.month)
    return true;
  if (month > n.month)
    return false;

  return day < n.day;
}

// Calculate the number of days until a given birthday
int Date::DaysTillYourBithday(const Date &birthday) {
  Date nextBirthday = birthday;\
  nextBirthday.year = year;
  if (nextBirthday.isLess(*this))
    nextBirthday = Date(birthday.day, birthday.month, year + 1);

  return Duration(nextBirthday);
}

// Calculate the duration between two dates
int Date::Duration(const Date &other) {
  Date start = *this;
  Date end = other;
  if (end.isLess(start)) {
    Date s = end;
    end = start;
    start = s;
  }

  int days = 0;
  while (start.isLess(end)) {
    start = start.NextDay();
    days++;
  }

  return days;
}

// Function to validate user input for date
Date GetValidDateInput() {
  int d, m, y;
  std::cout << "Enter day (1-31): ";
  std::cin >> d;
  std::cout << "Enter month (1-12): ";
  std::cin >> m;
  std::cout << "Enter year: ";
  std::cin >> y;

  if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0) {
    throw std::invalid_argument(
        "Invalid date input. Please enter valid day, month, and year.");
  }

  return Date(d, m, y);
}

QString Date::ToString() {

  char date[11];
  snprintf(date, 11, "%02d.%02d.%04d", day, month, year);

  return QString(date);
}