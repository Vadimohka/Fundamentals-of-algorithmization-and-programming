#include "date.h"

Date::Date(const QDate &date)
{
    setDate(date.year(), date.month(), date.day());
}

Date Date::NextDay()
{
    return addDays(1);
}

Date Date::PreviousDay()
{
    return addDays(-1);
}

bool Date::IsLeap()
{
    return isLeapYear(year());
}

int16_t Date::WeekNumber()
{
    return weekNumber();
}

int Date::DaysTillYourBithday(Date bithdayDate)
{
    bithdayDate.setDate(year(), bithdayDate.month(), bithdayDate.day());
    qDebug() << bithdayDate.ConvertToString();
    while (!bithdayDate.isValid())
    {
        bithdayDate.setDate(year()+1, bithdayDate.month(), bithdayDate.day());
    }
    if (daysTo(bithdayDate) < 0) {
        bithdayDate.setDate(year()+1, bithdayDate.month(), bithdayDate.day());
        while (!bithdayDate.isValid())
        {
            bithdayDate.setDate(year()+1, bithdayDate.month(), bithdayDate.day());
        }
    }
    return daysTo(bithdayDate);
}

int Date::Duration(Date date)
{
    return qAbs(daysTo(date));
}

void Date::ConvertToDate(const QString &str)
{
    if (str.size() < 10)
    {
        setDate(0, 0, 0);
        return;
    }
    const QString stringDay = str.mid(0, 2), stringMonth = str.mid(3, 2), stringYear = str.mid(6, 4);
    bool ok = true;
    int day = stringDay.toInt(&ok);
    if (!ok)
    {
        setDate(0, 0, 0);
        return;
    }
    int month = stringMonth.toInt(&ok);
    if (!ok)
    {
        setDate(0, 0, 0);
        return;
    }
    int year = stringYear.toInt(&ok);
    if (!ok)
    {
        setDate(0, 0, 0);
        return;
    }
    setDate(year, month, day);
}

QString Date::ConvertToString()
{
    if (!isValid())
    {
        return "-";
    }
    return toString("dd.MM.yyyy");
}
