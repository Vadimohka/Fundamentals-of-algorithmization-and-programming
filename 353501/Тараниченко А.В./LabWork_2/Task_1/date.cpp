#include "date.h"

Date::Date(int valueYear,int valueMonth,int valueDay)
{
    Date::year = valueYear;
    Date::month = valueMonth;
    Date::day = valueDay;
    days = 0;

    for(int i = 0; i < month-1; i++)
    {
        days = countDays[i];
    }

    if((isLeap()) && (month == 2))
    {
        days++;
    }
}

QString Date::str()
{
    return QDate(year,month,day).toString("dd.MM.yyyy");
}

QString Date::boolToString(bool ans)
{
    if(ans)
    {
        return "Yes";
    }

    return "No";
}

QString Date::shortToString(short a)
{
    QString str;
    return str.setNum(a);
}

QString Date::intToString(int a)
{
    QString str;
    return str.setNum(a);
}

void Date::input(QString text)
{
    int sz = dates->length();
    QString* arr2 = new QString[sz + 1];
    for (int i = 0; i < sz; i++)
    {
        arr2[i] = dates[i];
    }
    dates[sz] = text;
    dates = arr2;
}

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
    days = 0;
}

Date Date::nextDay()
{
    if((month % 12 == 0) && (day == 31))
    {
        return Date(year+1, 1, 1);
    }

    if((day == 29) && (month == 2))
    {
        return Date(year, 3, 1);
    }

    if(day==countDays[month-1])
    {
        return Date(year, month+1, 1);
    }

    return Date(year, month, day+1);
}

bool Date::isLeap()
{
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }

    return false;
}

Date Date::previousDay()
{
    if((month == 1)&&(day == 1))
    {
        return Date(year - 1, 12, 31);
    }

    if (day == 1)
    {
        if (month == 3 && isLeap())
        {
            return Date(year, 2, 29);
        }

        return Date(year, month - 1, countDays[month-2]);
    }

    return Date(year, month, day-1);
}

short Date::weekNumber()
{
    return day / 7 + 1;
}

int Date::daysTillYourBithday(Date birthdaydate)
{
    QString str1, str2;
    QString str = QDate::currentDate().toString("dd.MM.yyyy");

    for (int i = 0; i< str.size();i++)
    {
        if(i > -1 && i < 2)
        {
            str1=str1+str[i];
        }

        if(i < 5 && i > 2)
        {
            str2 = str2 + str[i];
        }
    }

    int curDay = str1.toInt();
    int curMonth = str2.toInt();

    if (isLeap() && curMonth > birthdaydate.month)
    {
       return 366 - duration(Date(this->year, birthdaydate.month, birthdaydate.day));
    }

    else if(isLeap() && curMonth == birthdaydate.month)
    {
        if(curDay>birthdaydate.day)
        {
            return 366 - duration(Date(this->year, birthdaydate.month, birthdaydate.day));
        }
    }

    else if (curMonth > birthdaydate.month)
    {
       return 365 - duration(Date(this->year, birthdaydate.month, birthdaydate.day));
    }

    else if(curMonth == birthdaydate.month)
    {
        if(curDay>birthdaydate.day)
        {
            return 365 - duration(Date(this->year, birthdaydate.month, birthdaydate.day));
        }
    }

    return duration(Date(this->year, birthdaydate.month, birthdaydate.day));
}

int Date::duration(Date date)
{
    QString str1,str2, str3;
    QString str = QDate::currentDate().toString("dd.MM.yyyy");

    for (int i = 0; i< str.size();i++)
    {
        if(i > -1 && i < 2)
        {
            str1=str1+str[i];
        }

        if(i < 5 && i > 2)
        {
            str2 = str2 + str[i];
        }

        if(i > 5)
        {
            str3 = str3 + str[i];
        }
    }

    int curDay = str1.toInt();
    int curMonth = str2.toInt();
    int curYear = str3.toInt();

    QDate dt1 = QDate(date.year,date.month,date.day);

    QDate dt2 = QDate(curYear,curMonth,curDay);

    int diff1 = dt1.toJulianDay();

    int diff2 = dt2.toJulianDay();

    int result = qAbs(diff1-diff2);

    return result;
}


