#include "date.h"

Date::Date() {}

QDate Date::nextDay(QDate currentDate)
{
    return currentDate.addDays(1);
}
QDate Date::previousDay(const QDate &currentDate)
{
    return currentDate.addDays(-1);
}

bool Date::isLeap(const QDate &date)
{
    int year = date.year();
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short Date::weekNumber(const QDate &date)
{
    return date.weekNumber();
}
int Date::calculateBirth(QDate currentDate, QDate birthDate)
{
    int daysUntilBirthday = 0;
    QDate nextBirthday(currentDate.year(), birthDate.month(), birthDate.day());

    if (Date::isLeap(birthDate))
    {
        nextBirthday = nextBirthday.addYears(4);
    }


    if (currentDate >= nextBirthday)
    {
        nextBirthday = nextBirthday.addYears(1);
    }

    daysUntilBirthday = currentDate.daysTo(nextBirthday);

    return daysUntilBirthday;
}
