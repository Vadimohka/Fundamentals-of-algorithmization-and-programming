#include "date.h"

Date::Date()
{

}

void Date::setDay(int dd)
{
    d = dd;
}

void Date::setMonth(int mm)
{
    m = mm;
}

void Date::setYear(int yy)
{
    y = yy;
}

bool Date::checkDate()
{
    bool leap = false;

    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        leap = true;

    if(d > 31 || d < 1)
        return false;

    if(m > 12 || m < 1)
        return false;

    if((y < 0) || (y > 9999))
        return false;

    if((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30))
        return false;

    if(m == 2)
    {
        if(d > 29)
            return false;
        else if(d > 28 && leap == false)
            return false;
    }

    return true;
}

QString Date::getString()
{
    QString ret = "";

    if(d < 10)
        ret = '0';

    ret = ret + QString::number(d) + '.';

    if(m < 10)
        ret = ret + '0';

    ret = ret + QString::number(m) + '.';

    if(y < 1000)
        ret = ret + '0';
    if(y < 100)
        ret = ret + '0';
    if(y < 10)
        ret = ret + '0';

    ret = ret + QString::number(y);

    return ret;
}

Date Date::NextDay()
{
    Date ret;
    ret.d = d;
    ret.m = m;
    ret.y = y;

    ret.d++;
    if (ret.checkDate() == false)
    {
        ret.d = 1;
        ret.m++;

        if (ret.checkDate() == false)
        {
            ret.m = 1;
            ret.y++;

            if (ret.checkDate() == false)
            {
                ret.y = 0;
            }
        }
    }

    return ret;
}

Date Date::PreviousDay()
{
    Date ret;
    ret.d = d;
    ret.m = m;
    ret.y = y;

    ret.d--;
    if (ret.checkDate() == false)
    {
        if(m == 5 || m == 7 || m == 10 || m == 12)
            ret.d = 30;
        else if(m == 3)
        {
            if ((ret.y % 4 == 0 && ret.y % 100 != 0) || (ret.y % 400 == 0))
                ret.d = 29;
            else
                ret.d = 28;
        }
        else
            ret.d = 31;

        ret.m--;

        if (ret.checkDate() == false)
        {
            ret.m = 12;
            ret.y--;

            if (ret.checkDate() == false)
            {
                ret.y = 9999;
            }
        }
    }

    return ret;
}

bool Date::IsLeap()
{
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
       return true;

    return false;
}

short Date::WeekNumber()
{
    Date ret;
    ret.d = d;
    ret.m = m;
    ret.y = y;

    int days = ret.d;

    for (int i = ret.m - 1; i >= 1; i--)
    {
        if(i == 4 || i == 6 || i == 9 || i == 11)
            days += 30;
        else if (i == 2)
        {
            if ((ret.y % 4 == 0 && ret.y % 100 != 0) || (ret.y % 400 == 0))
                days += 29;
            else
                days += 28;
        }
        else
            days += 31;
    }

    return days / 7 + 1;
}

int Date::Duration(Date dute)
{
    Date date = dute;
    Date ret;
    ret.d = d;
    ret.m = m;
    ret.y = y;

    if(ret.y > date.y)
    {
        int dd = ret.d, mm = ret.m, yy = ret.y;
        ret.d = date.d; ret.m = date.m; ret.y = date.y;
        date.d = dd; date.m = mm; date.y = yy;
    }
    else if(ret.y == date.y)
    {
        if(ret.m > date.m)
        {
            int dd = ret.d, mm = ret.m;
            ret.d = date.d; ret.m = date.m;
            date.d = dd; date.m = mm;
        }
        else if(ret.m == date.m)
        {
            if(ret.d > date.d)
            {
                int dd = ret.d;
                ret.d = date.d;
                date.d = dd;
            }
        }
    }

    //ret always lower

    int days = 0;

    while(ret.d != date.d || ret.m != date.m || ret.y != date.y)
    {
        ret = ret.NextDay();
        days++;
    }

    return days;
}

int Date::DaysTillYourBirthday(Date birthdaydate)
{
    Date birth = birthdaydate;

    birth.y = y;

    if(birth.m < m || (birth.m == m && birth.d < d))
    {
        if(m < 2 || (m == 2 && d < 29))
            return 366 - Duration(birth) + IsLeap();
        else
            return 366 - Duration(birth);
    }
    else
        return Duration(birth);
}
