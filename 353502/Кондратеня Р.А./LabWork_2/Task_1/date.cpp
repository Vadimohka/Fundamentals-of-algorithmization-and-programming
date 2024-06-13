#include "date.h"

Date::Date()
{
    currentDate = QDate::currentDate();
}

void Date::setDate(QDate date)
{
    currentDate = date;
}

QDate Date::getDate()
{
    return currentDate;
}

QString Date::NextDay()
{
    return FormatDate(currentDate.addDays(1));
}

QString Date::PreviousDay()
{
    return FormatDate(currentDate.addDays(-1));
}

bool Date::isLeap()
{
    return QDate::isLeapYear(currentDate.year());
}

int Date::DaysTillYourBirthday()
{
    QDate date = birthDayDate;
    if(birthDayDate.month() < currentDate.month())
    {
        date = date.addYears(currentDate.year() - date.year() + 1);
    }
    if(birthDayDate.month() == currentDate.month())
    {
        if(birthDayDate.day() < currentDate.day())
        {
            date = date.addYears(currentDate.year() - date.year() + 1);
        }
    }
    else
    {
        date = date.addYears(currentDate.year() - date.year());
    }
    return currentDate.daysTo(date);
}

int Date::Duration(QDate date)
{
    return abs(currentDate.daysTo(date));
}

QString Date::FormatDate(QDate date)
{
    if (date.year() < 0) {
        date.setDate(date.year() * -1, date.month(), date.day());
        return date.toString("dd.MM.yyyy BC");
    }
    return date.toString("dd.MM.yyyy");
}

int Date::WeekNumber()
{
    return currentDate.weekNumber();
}
