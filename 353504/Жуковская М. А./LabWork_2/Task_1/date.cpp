#include "date.h"
#include "qdebug.h"
#include "qlogging.h"
#include <QDebug>

Date::Date(int _day, int _month, int _year)
{
    day = _day;
    month = _month;
    year = _year;
}

Date::Date(std::string str)
{
    day = std::stoi(str.substr(0, 2));
    month = std::stoi(str.substr(3, 2));
    year = std::stoi(str.substr(6, 4));
}

Date::Date(QString str)
{
    day = (str.mid(0, 2)).toInt();
    month = (str.mid(3, 2)).toInt();
    year = (str.mid(6, 4)).toInt();
}

Date::Date()
{
    day = 1;
    month = 1;
    year = 1970;
}

Date Date::NextDay()
{
    int newDay, newMonth, newYear;

    newDay = day + 1;
    newMonth = month;
    newYear = year;

    if(month == 2)
    {
        if(isLeapThe(year))
        {
            if(newDay == 30)
            {
                newDay = 1;
                newMonth = month + 1;
            }
        }
        else
        {
            if(newDay == 29)
            {
                newDay = 1;
                newMonth = month + 1;
            }
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if(newDay == 32)
        {
            newDay = 1;
            newMonth = month + 1;

            if(newMonth == 13)
            {
                newMonth = 1;
                newYear = year + 1;
            }
        }
    }
    else
    {
        if(newDay == 31)
        {
            newDay = 1;
            newMonth = month + 1;
        }
    }

    return Date(newDay, newMonth, newYear);
}

Date Date::PreviousDay()
{
    int newDay, newMonth, newYear;

    newDay = day - 1;
    newMonth = month;
    newYear = year;

    if(newDay == 0)
    {
        if(month == 3)
        {
            if(isLeapThe(year))
            {
                newDay = 29;
                newMonth = month - 1;
            }
            else
            {
                newDay = 28;
                newMonth = month - 1;
            }
        }
        else if(month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11 || month == 1)
        {
            newDay = 31;
            newMonth = month - 1;

            if(newMonth == 0)
            {
                newMonth = 12;
                newYear = year - 1;
            }
        }
        else
        {
            newDay = 30;
            newMonth = month - 1;
        }
    }

    return Date(newDay, newMonth, newYear);
}

bool Date::isLeap()
{
    return isLeapThe(this->year);
}

short Date::WeekNumber()
{
    int dayNum = day, thisYear = year;
    short week = 0;

    for(int i = 1; i < month; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) dayNum += 31;
        else if(i == 2)
        {
            if(isLeapThe(thisYear)) dayNum += 29;
            else dayNum += 28;
        }
        else dayNum += 30;
    }

    while(dayNum > 7)
    {
        week++;
        dayNum -= 7;
    }

    if(dayNum > 0) week++;

    return week;
}

int Date::DaysTillYourBirthday(Date birthdayDate)
{
    if(isThisDateEarlierThan(birthdayDate))
    {
        return -1;
    }
    else
    {
        Date theNearestBirthday = Date(birthdayDate.Day(), birthdayDate.Month(), year);

        if(!isThisDateEarlierThan(theNearestBirthday))
        {
            theNearestBirthday = Date(birthdayDate.Day(), birthdayDate.Month(), year + 1);
        }

        return Duration(theNearestBirthday);
    }
}

int Date::Duration(Date date)
{
    //кол-во дней с минимального года до текущей даты
    int daysForDate = 0, daysForSecondDate = 0;

    for(int i = std::min(year, date.Year()); i < year; i++)
    {
        if(isLeapThe(i)) daysForDate += 366;
        else daysForDate += 365;
    }

    for(int i = 1; i < month; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysForDate += 31;
        else if(i == 2)
        {
            if(isLeapThe(year)) daysForDate += 29;
            else daysForDate += 28;
        }
        else daysForDate += 30;
    }

    daysForDate += day;



    //кол-во дней с минимального года до данной в параметрах даты

    for(int i = std::min(year, date.Year()); i < date.Year(); i++)
    {
        if(isLeapThe(i)) daysForSecondDate += 366;
        else daysForSecondDate += 365;
    }

    for(int i = 1; i < date.Month(); i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysForSecondDate += 31;
        else if(i == 2)
        {
            if(isLeapThe(date.Year())) daysForSecondDate += 29;
            else daysForSecondDate += 28;
        }
        else daysForSecondDate += 30;
    }

    daysForSecondDate += date.Day();

    return abs(daysForDate - daysForSecondDate);
}





Date Date::DateWithPlusThisTime(int minutes)
{
    double days = (time(nullptr) + 180 * 60 + minutes * 60) / 60.0 / 60.0 / 24.0;
    int thisYear = 1970;

    for(thisYear; days > 366; thisYear++)
    {
        if(isLeapThe(thisYear)) days -= 366;
        else days -= 365;
    }

    days = (time(nullptr) + 180 * 60 + minutes * 60) / 60.0 / 60.0 / 24.0;

    for(int i = 1970; days > 366; i++)
    {
        if(isLeapThe(i)) days -= 366;
        else days -= 365;
    }

    days++;

    int dayNum = int(days);
    int monthNum;

    for(int i = 1; dayNum > 31 && i <= 12; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) dayNum -= 31;
        else if(i == 2)
        {
            if(isLeapThe(thisYear)) dayNum -= 29;
            else dayNum -= 28;
        }
        else dayNum -= 30;

        if(dayNum <= 31) monthNum = i;
    }

    if(dayNum > 0) monthNum++;

    return Date(dayNum, monthNum, thisYear);
}

void Date::Print()
{
    qDebug() << day << '.' << month << '.' << year;
}

QString Date::ToString()
{
    QString dayString = QString::number(day), monthString = QString::number(month), yearString = QString::number(year);
    if(dayString.size() == 1) dayString = '0' + dayString;
    if(monthString.size() == 1) monthString = '0' + monthString;
    while(yearString.size() < 4) yearString = '0' + yearString;

    return dayString + '.' + monthString + '.' + yearString;
}

Date Date::Today()
{
    return DateWithPlusThisTime(0);
}

Date Date::Tomorrow()
{
    return DateWithPlusThisTime(24 * 60);
}

Date Date::Yesterday()
{
    return DateWithPlusThisTime(-24 * 60);
}

bool Date::isLeapThe(int _year)
{
    if(_year % 4 == 0)
    {
        if(_year % 100 == 0)
        {
            if(_year % 400 == 0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

bool Date::isThisDateEarlierThan(Date date)
{
    //кол-во дней с минимального года до текущей даты
    int daysForDate = 0, daysForSecondDate = 0;

    for(int i = std::min(year, date.Year()); i < year; i++)
    {
        if(isLeapThe(i)) daysForDate += 366;
        else daysForDate += 365;
    }

    for(int i = 1; i < month; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysForDate += 31;
        else if(i == 2)
        {
            if(isLeapThe(year)) daysForDate += 29;
            else daysForDate += 28;
        }
        else daysForDate += 30;
    }

    daysForDate += day;



    //кол-во дней с минимального года до данной в параметрах даты

    for(int i = std::min(year, date.Year()); i < date.Year(); i++)
    {
        if(isLeapThe(i)) daysForSecondDate += 366;
        else daysForSecondDate += 365;
    }

    for(int i = 1; i < date.Month(); i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysForSecondDate += 31;
        else if(i == 2)
        {
            if(isLeapThe(date.Year())) daysForSecondDate += 29;
            else daysForSecondDate += 28;
        }
        else daysForSecondDate += 30;
    }

    daysForSecondDate += date.Day();

    if(daysForDate - daysForSecondDate < 0) return true;
    else return false;
}

int Date::Day()
{
    return this->day;
}

int Date::Month()
{
    return this->month;
}

int Date::Year()
{
    return this->year;
}
