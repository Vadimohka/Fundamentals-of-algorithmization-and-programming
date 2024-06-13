#include "date.h"
Date::Date()
{
    day_ = 0;
    month_ = 0;
    year_ = 0;
}

Date::Date(QString s)
{
    QString sub1 = s.mid(0, 2);
    day_ = sub1.toInt();
    QString sub2 = s.mid(3, 2);
    month_ = sub2.toInt();
    QString sub3 = s.mid(6, 4);
    year_ = sub3.toInt();
}

Date::Date(int day, int month, int year)
{
    day_ = day;
    month_ = month;
    year_ = year;
}

Date Date::NextDay()
{
    Date d(day_, month_, year_);
    if (d.day_ < d.maxDay(month_))
    {
        ++d.day_;
    }
    else if (d.day_ == d.maxDay(month_) && d.month_ == 12)
    {
        d.day_ = 1;
        d.month_ = 1;
        ++d.year_;
    }
    else
    {
        d.day_ = 1;
        ++d.month_;
    }

    return d;
}

Date Date::PreviusDay()
{
    Date d(day_, month_, year_);

    if (d.day_ > 1)
    {
        --d.day_;
    }
    else if (d.day_ == 1 && d.month_ == 1)
    {
        d.day_ = 31;
        d.month_ = 12;
        --d.year_;
    }
    else
    {
        d.day_ = 31;
        --d.month_;
    }

    return d;
}

short Date::WeekNumber()
{
    short days = 0;
    for (int i = 1; i < month_; ++i)
    {
        days += maxDay(i);
    }
    days += day_;
    int week = days / 7 + 1;
    return week;
}

int Date::DaysTillYourBithday(Date bithdaydate)
{
    int days = 0;
    if (month_ < bithdaydate.month_)
    {
        days = maxDay(month_) - day_ + bithdaydate.day_;
        for (int i = month_ + 1; i < bithdaydate.month_; ++i)
        {
            days += maxDay(i);
        }
    }
    else if (month_ == bithdaydate.month_)
    {
        if (day_ > bithdaydate.day_)
        {
            days = 365 - (day_ -bithdaydate.day_);
        }
        else if (day_ == bithdaydate.day_)
        {
            return 0;
        }
        else
        {
            days = bithdaydate.day_ - day_;
        }
    }
    else
    {
        for(int i = 1; i < bithdaydate.month_; ++i)
        {
            days += maxDay(i);
        }
        days += bithdaydate.day_;

        for(int i = month_ + 1; i <= 12; ++i)
        {
            days += maxDay(i);
        }
        days += maxDay(month_) - day_;
    }

    return days;
}

int Date::Duration(Date date)
{
    int days = 0;

    if (year_ < date.year_)
    {
        for (int i = year_ + 1; i < date.year_; ++i)
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
        for(int i = month_ + 1; i <= 12; ++i)
        {
            days += maxDay(i);
        }
        days += maxDay(month_) - day_;

        for(int i = 1; i < date.month_; ++i)
        {
            days += maxDay(i);
        }
        days += date.day_;
    }
    else if (year_ == date.year_)
    {
        if (month_ == date.month_)
        {
            days = maxDay(month_) - date.day_;
        }
        else if (month_ < date.month_)
        {
            for(int i = month_ + 1; i < date.month_; ++i)
            {
                days += maxDay(i);
            }
            days += maxDay(month_) - day_ + date.day_;
        }
        else
        {
            for(int i = date.month_ + 1; i < month_; ++i)
            {
                days += maxDay(i);
            }
            days += maxDay(date.month_) - date.day_ + day_;
        }
    }
    else
    {
        for (int i = date.year_ + 1; i < year_; ++i)
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
        for(int i = date.month_ + 1; i <= 12; ++i)
        {
            days += maxDay(i);
        }
        days += maxDay(month_) - date.day_;

        for(int i = 1; i < month_; ++i)
        {
            days += maxDay(i);
        }
        days += day_;
    }

    return abs(days);
}

QString Date::print()
{
    QString sDate;
    QString sDay = QString::number(day_);
    QString sMonth = QString::number(month_);
    QString sYear = QString::number(year_);

    if(day_ < 10)
    {
        sDate += '0';
    }
    sDate += sDay;
    sDate += '.';

    if(month_ < 10)
    {
        sDate += '0';
    }
    sDate += sMonth;
    sDate += '.';

    if(year_ < 10)
    {
        sDate += "000";
    }
    else if (year_ < 100)
    {
        sDate += "00";
    }
    else if (year_ < 1000)
    {
        sDate += '0';
    }
    sDate += sYear;

    return sDate;
}


bool Date::IsLeep()
{
    if ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::IsLeep(int year_)
{
    if ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Date::maxDay(int month_)
{
    switch (month_)
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
