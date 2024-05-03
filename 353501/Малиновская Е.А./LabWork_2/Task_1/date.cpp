#include "date.h"

Date::Date(int day, int month, int year)
    : day(day), month(month), year(year)
{
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}



Date Date::NextDay() const
{
    QDate currentDate(year, month, day);
    QDate nextDate = currentDate.addDays(1);
    return Date(nextDate.day(), nextDate.month(), nextDate.year());
}

Date Date::PreviousDay() const
{
    QDate currentDate(year, month, day);
    QDate previousDate = currentDate.addDays(-1);
    return Date(previousDate.day(), previousDate.month(), previousDate.year());
}


bool Date::IsLeap() const
{
    return QDate::isLeapYear(year);
}

short Date::WeekNumber() const
{
    QDate currentDate(year, month, day);
    return currentDate.weekNumber();
}

int Date::DaysTillYourBithday(const Date& birthdayDate) const
{
    QDate current(year, month, day);
    QDate birthday(birthdayDate.getYear(), birthdayDate.getMonth(), birthdayDate.getDay());
    if ((current.month() < birthday.month() || (current.month()) == birthday.month() && current.day() <= birthday.day())) {
        QDate nextBirthday(current.year(), birthday.month(), birthday.day());
        return current.daysTo(nextBirthday);
    } else {
        QDate nextBirthday(current.year() + 1, birthday.month(), birthday.day());
        return current.daysTo(nextBirthday);
    }
}

int Date::Duration(const Date& date) const
{
    QDate currentDate(year, month, day);
    QDate otherDate(date.getYear(), date.getMonth(), date.getDay());
    return qAbs(currentDate.daysTo(otherDate));
}

QString Date::toString() const
{
    return QString("%1.%2.%3").arg(day, 2, 10, QChar('0')).arg(month, 2, 10, QChar('0')).arg(year);
}
