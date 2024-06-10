#include "dateHandler.h"

QString Date::previousDay(int a)
{
    return fromDateToString(dateSet[a].addDays(-1));
}

QString Date::nextDate(int a)
{
    return fromDateToString(dateSet[a].addDays(1));
}

bool Date::isLeapYear(int a)
{
    return QDate::isLeapYear(dateSet[a].year());
}

long long Date::dayUntilYourBirthday(QDate birthdayDate, int a)
{
    QDate date = QDate::currentDate();
    int year = date.year();
    if (birthdayDate.day() == 29 && birthdayDate.month() == 12){
        while (!QDate::isLeapYear(year))
        {
            year++;
        }
    }
    birthdayDate.setDate(year, birthdayDate.month(), birthdayDate.day());
    long long result = date.daysTo(birthdayDate);
    if (result < 0)
    {
        if (birthdayDate.day() == 29 && birthdayDate.month() == 12)
        {
            do
            {
                birthdayDate = birthdayDate.addYears(1);
            } while (!QDate::isLeapYear(birthdayDate.year()));
        } else
        {
            birthdayDate = birthdayDate.addYears(1);
        }
    }
    result = date.daysTo(birthdayDate);
    return result;
}

QString Date::fromDateToString(QDate date)
{
    if (date.year() < 0)
    {
        date.setDate(date.year() * -1, date.month(), date.day());
        return date.toString("dd.MM.yyyy BC");
    }
    return date.toString("dd.MM.yyyy");
}

long long Date::getDefWithPrev(int a)
{
    QDate currentDate = QDate::currentDate();
    QDate date = dateSet[a];

    // Используем метод daysTo() для вычисления разницы в днях между текущей датой и dateSet[a]
    return qAbs(currentDate.daysTo(date));
}

long long Date::getWeekNumber(int a)
{
    return dateSet[a].weekNumber();
}

int Date::changeDate(QDate wasDate, QDate newDate)
{
    int result = -1;
    for (int i = 0; i < dateSet.size(); i++)
    {
        if (dateSet[i] == wasDate)
        {
            dateSet[i] = newDate;
        }
        if (result == -1)
        {
            result = i;
        }
    }
    return result;
}