#include "date.h"
#include <QDate>
Date::Date()
{
}
void Date::showinfo()
{
    qDebug() << this->day << "." << this->month << "." << this->year << "\n";
}
bool Date::isLeapYear(int year1) const
{
    return ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0);
}
int Date::daysInMonth(int year1, int month1) const
{
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // array of days in each month
    if (month1 == 2 && isLeapYear(year1))
    {
        return 29;
    }
    else
    {
        return days_in_month[month1 - 1];
    }
}

Date::Date(int a, int b, int c) : day(a), month(b), year(c) {}
bool Date::isleap()
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int Date::whatdayisit()
{
    int a[13];
    int na[13];
    a[1] = 0;
    na[1] = 0; // jan
    a[2] = 31; // feb
    na[2] = 31;
    na[3] = 59; // mar
    a[3] = 60;
    a[4] = 91; // apr
    na[4] = 90;
    a[5] = 121; // may
    na[5] = 120;
    na[6] = 151; // jun
    a[6] = 152;
    a[7] = 182; // jul
    na[7] = 181;
    a[8] = 213; // aug
    na[8] = 212;
    na[9] = 243; // sep
    a[9] = 244;
    a[10] = 274; // oct
    na[10] = 273;
    a[11] = 305; // nov
    na[11] = 304;
    a[12] = 335;  // dec
    na[12] = 334; // dec
    // int yourday;
    int leap = this->isleap();
    if (leap)
    {
        return (a[month] + day);
    }
    return (na[month] + day);
}
Date Date::nextday()
{
    int leap = this->isleap();
    if (month == 2 && !leap && day == 28)
    {
        return Date(1, 3, year);
    }
    if (month == 2 && leap && day == 29)
    {
        return Date(1, 3, year);
    } // 4 6 9 11
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    {
        return Date(1, month + 1, year);
    }
    if (day == 31 && month == 12)
    {
        return Date(1, 1, year + 1);
    }
    if ((month == 1 || month == 2 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31)
    {
        return Date(1, month + 1, year);
    }
    return Date(day + 1, month, year);
}
Date Date::prevday()
{
    if (day == 1 && month == 1 && year == 1) return Date(31, 12, 0);

    int leap = this->isleap();
    if (day == 1 && month == 1)
    {
        return Date(31, 12, year - 1);
    }
    if (day == 1 && (month == 5 || month == 7 || month == 10 || month == 12))
    {
        return Date(30, month - 1, year);
    }
    if (month == 3 && !leap && day == 1)
    {
        return Date(28, 2, year);
    }
    if (month == 3 && leap && day == 1)
    {
        return Date(29, 2, year);
    }
    if (day == 1)
    {
        return Date(31, month - 1, year);
    }
    return Date(day - 1, month, year);
}

short Date::weeknum()
{
    int curday = this->whatdayisit();

    short curweek = curday / 7;
    if (curday % 7 > 0)
    {
        curweek++;
    }
    return curweek;
}
int Date::daystillmybday(Date a)
{
    QDate have(year, month, day);
    if (month <= a.month)
    {
        if (day > a.day)
        {
            QDate b(year + 1, a.month, a.day);
            return have.daysTo(b);
        }
        else
        {
            QDate b(year, a.month, a.day);
            return have.daysTo(b);
        }
    }
    QDate b(year + 1, a.month, a.day);
    return have.daysTo(b);
}
long long Date::duration(Date a)
{
    return QDate(year, month, day).daysTo(QDate(a.year, a.month, a.day));
}
QDate Date::toQDate()
{
    return QDate(year, month, day);
}