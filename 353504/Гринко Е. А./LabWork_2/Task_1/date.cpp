#include "date.h"

Date::Date()
{
    dayq = 0;
    monthq = 0;
    yearq = 0;
}

Date::Date(QString s)
{
    QString sub1 = s.mid(0, 2);
    dayq = sub1.toInt();
    QString sub2 = s.mid(3, 2);
    monthq = sub2.toInt();
    QString sub3 = s.mid(6, 4);
    yearq = sub3.toInt();
}

Date::Date(int day, int month, int year)
{
    dayq = day;
    monthq = month;
    yearq = year;
}

Date Date::NextDay()
{
    Date d(dayq, monthq, yearq);
    if (d.dayq < d.maxDay(monthq))
    {
        ++d.dayq;
    }
    else if (d.dayq == d.maxDay(monthq) && d.monthq == 12)
    {
        d.dayq = 1;
        d.monthq = 1;
        ++d.yearq;
    }
    else
    {
        d.dayq = 1;
        ++d.monthq;
    }

    return d;
}

Date Date::PreviusDay()
{
    Date d(dayq, monthq, yearq);

    if (d.dayq > 1)
    {
        --d.dayq;
    }
    else if (d.dayq == 1 && d.monthq == 1)
    {
        d.dayq = 31;
        d.monthq = 12;
        --d.yearq;
    }
    else
    {
        d.dayq = 31;
        --d.monthq;
    }

    return d;
}

short Date::WeekNumber()
{
    short days = 0;
    for (int i = 1; i < monthq; ++i)
    {
        days += maxDay(i);
    }
    days += dayq;
    int week = days / 7 + 1;
    return week;
}

int Date::DaysTillYourBithday(Date bithdaydate)
{
    int days = 0;
    if (monthq < bithdaydate.monthq)
    {
        days = maxDay(monthq) - dayq + bithdaydate.dayq;
        for (int i = monthq + 1; i < bithdaydate.monthq; ++i)
        {
            days += maxDay(i);
        }
    }
    else if (monthq == bithdaydate.monthq)
    {
        if (dayq > bithdaydate.dayq)
        {
            days = 365 - (dayq - bithdaydate.dayq);
        }
        else if (dayq == bithdaydate.dayq)
        {
            return 0;
        }
        else
        {
            days = bithdaydate.dayq - dayq;
        }
    }
    else
    {
        for(int i = 1; i < bithdaydate.monthq; ++i)
        {
            days += maxDay(i);
        }
        days += bithdaydate.dayq;

        for(int i = monthq + 1; i <= 12; ++i)
        {
            days += maxDay(i);
        }
        days += maxDay(monthq) - dayq;
    }

    return days;
}

int Date::Duration(Date date)
{
    int days = 0;

    if (yearq < date.yearq)
    {
        for (int i = yearq + 1; i < date.yearq; ++i)
        {
            if (IsLeep(i))
            {
                days += 366;
            }
            else
            {
                days += 365;
            }
        }
        for(int i = monthq + 1; i <= 12; ++i)
        {
            days += maxDay(i);
        }
        days += maxDay(monthq) - dayq;

        for(int i = 1; i < date.monthq; ++i)
        {
            days += maxDay(i);
        }
        days += date.dayq;
    }
    else if (yearq == date.yearq)
    {
        if (monthq == date.monthq)
        {
            days = maxDay(monthq) - date.dayq;
        }
        else if (monthq < date.monthq)
        {
            for(int i = monthq + 1; i < date.monthq; ++i)
            {
                days += maxDay(i);
            }
            days += maxDay(monthq) - dayq + date.dayq;
        }
        else
        {
            for(int i = date.monthq + 1; i < monthq; ++i)
            {
                days += maxDay(i);
            }
            days += maxDay(date.monthq) - date.dayq + dayq;
        }
    }
    else
    {
        for (int i = date.yearq + 1; i < yearq; ++i)
        {
            if (IsLeep(i))
            {
                days += 366;
            }
            else
            {
                days += 365;
            }
        }
        for(int i = date.monthq + 1; i <= 12; ++i)
        {
            days += maxDay(i);
        }
        days += maxDay(monthq) - date.dayq;

        for(int i = 1; i < monthq; ++i)
        {
            days += maxDay(i);
        }
        days += dayq;
    }

    return abs(days);
}

QString Date::print()
{
    QString sDate;
    QString sDay = QString::number(dayq);
    QString sMonth = QString::number(monthq);
    QString sYear = QString::number(yearq);

    if(dayq < 10)
    {
        sDate += '0';
    }
    sDate += sDay;
    sDate += '.';

    if(monthq < 10)
    {
        sDate += '0';
    }
    sDate += sMonth;
    sDate += '.';

    if(yearq < 10)
    {
        sDate += "000";
    }
    else if (yearq < 100)
    {
        sDate += "00";
    }
    else if (yearq < 1000)
    {
        sDate += '0';
    }
    sDate += sYear;

    return sDate;
}


bool Date::IsLeep()
{
    if ((yearq % 4 == 0 && yearq % 100 != 0) || yearq % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::IsLeep(int yearq)
{
    if ((yearq % 4 == 0 && yearq % 100 != 0) || yearq % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Date::maxDay(int monthq)
{
    switch (monthq)
    {
    case 2:
        if (IsLeep())
        {
            return 29;
        }
        else
        {
            return 28;
        }
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    default:
        return 31;
    }
}
