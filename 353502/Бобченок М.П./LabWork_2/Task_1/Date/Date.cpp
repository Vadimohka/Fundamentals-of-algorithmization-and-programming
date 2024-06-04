//
// Created by u on 02.04.24.
//

#include "Date.h"

bool Date::isLeap(date dt)
{
    if (dt.year % 4 == 0 && (dt.year % 100 != 0 || dt.year % 400 == 0))
        return true;
    else
        return false;
}

date Date::secToDate(long long sec)
{
    date dt;
    int numOfDays = sec / secsInMinute / minutesInHour / hoursInDay + daysInYear;
    numOfDays--;
    dt.year = numOfDays / daysInYear;

    numOfDays -= dt.year * daysInYear;

    numOfDays -= dt.year / 4;
    numOfDays += dt.year / 100;
    numOfDays -= dt.year / 400;
    while (numOfDays < 0)
    {
        dt.year--;
        numOfDays += daysInYear + isLeap(dt);
    }

    for (int i = 0; i < 12; i++)
    {
        if (numOfDays >= daysInMonths[i] && (i != 1 || numOfDays >= daysInMonths[i] + isLeap(dt)))
        {
            numOfDays -= daysInMonths[i] + (i == 1 ? isLeap(dt) : 0);
            dt.month++;
        }
        else
            break;
    }

    dt.day += numOfDays;
    return dt;
}

long long Date::dateToSec(date dt)
{
    dt.year--;
    dt.day += dt.year * daysInYear;
    dt.day += dt.year / 4;
    dt.day -= dt.year / 100;
    dt.day += dt.year / 400;
    dt.year++;

    for (int i = 0; i < dt.month - 1; i++)
    {
        dt.day += daysInMonths[i] + (i == 1 ? isLeap(dt) : 0);
    }

    return (long long)dt.day * hoursInDay * minutesInHour * secsInMinute;
}

date Date::getDate() const
{
    return curDate;
}

int Date::getDay() const
{
    return curDate.day;
}

int Date::getMonth() const
{
    return curDate.month;
}

int Date::getYear() const
{
    return curDate.year;
}

void Date::setDate(int day, int month, int year)
{
    curDate.day = day;
    curDate.month = month;
    curDate.year = year;
}

date Date::nextDay()
{
    long long sec = dateToSec(curDate);
    sec += secsInMinute * minutesInHour * hoursInDay;
    return secToDate(sec);
}

date Date::previousDay()
{
    long long sec = dateToSec(curDate);
    sec -= secsInMinute * minutesInHour * hoursInDay;
    return secToDate(sec);
}

int Date::weekNumber(date dt)
{
    long long sec = dateToSec(dt);
    int days = (int)(sec / secsInMinute / minutesInHour / hoursInDay);
    days--;

    return days % 7;
}

int Date::duration(int day, int month, int year)
{
    date dt = {day, month, year};
    long long sec = dateToSec(dt) - dateToSec(curDate);
    return (int)(sec / secsInMinute / minutesInHour / hoursInDay);
}

int Date::daysTilYourBirthday(int day, int month)
{
    date dt = {day, month, curDate.year};
    long long sec = dateToSec(dt) - dateToSec(curDate);
    if (sec < 0)
    {
        dt.year++;
        sec = dateToSec(dt) - dateToSec(curDate);
    }
    return (int)(sec / secsInMinute / minutesInHour / hoursInDay);
}

Date::Date(int day, int month, int year)
{
    setDate(day, month, year);
}

Date::Date()
{
    long long timeInSec = time(nullptr);
    curDate = secToDate(timeInSec);
    curDate.year += 1969;
}


