#include "date.h"
#include "QDebug"

Date::Date() {
    _day = 0;
    _month = 0;
    _year = 0;
}

Date::Date(int year, int month, int day)
{
    _day = day;
    _month = month;
    _year = year;

    _daysSinceBeggingOfYear = 0;
    for(short i  = 0; i < _month - 1; i++)
    {
        _daysSinceBeggingOfYear += _daysInPerMonth[i];
    }
    if(_month > 2 && IsLeap())
    {
        _daysSinceBeggingOfYear++;
    }
    _daysSinceBeggingOfYear += _day;
}

Date Date::NextDay()
{
    if(_day == _day29 && _month == _monthFebruary)
    {
        return Date(_year, 3, 1);
    }
    if(_month == _monthsInYear && _day == _day31)
    {
        return Date(_year + 1, 1, 1);
    }
    if(_day == _daysInPerMonth[_month - 1])
    {
        return Date(_year, _month + 1, 1);
    }
    return Date(_year, _month, _day + 1);
}

Date Date::PreviousDay()
{
    if(_day == 1)
    {
        if(_month == 1)
            return Date(_year - 1, _monthsInYear, _day31);
        if(_month == 3 && IsLeap())
            return Date(_year, _monthFebruary, _day29);
        return Date(_year, _month, _daysInPerMonth[_month - 1]);
    }
    return Date(_year, _month, _day - 1);
}

bool Date::IsLeap()
{
    if((_year % 4 == 0) && (_year % _oneHundreed != 0 || _year % _fourHundreed == 0))
    {
        return true;
    }
    return false;
}

short Date::WeekNumber()
{
    return _daysSinceBeggingOfYear / 7 + ((_daysSinceBeggingOfYear % 7 == 0) ? 0 : 1);
}

int Date::Duration(Date date)
{
    int myDays = _year * _daysInYear + _day;
    for(short i = 0; i < _month - 1; ++i)
    {
        myDays += _daysInPerMonth[i];
    }
    int tempYear = _year;
    if(_month <= 2)
    {
        tempYear--;
    }
    myDays += tempYear / 4 - tempYear / _oneHundreed + tempYear / _fourHundreed;

    int dateDays = date._year * _daysInYear + date._day;
    for(short i = 0; i < date._month - 1; ++i)
    {
        dateDays += _daysInPerMonth[i];
    }
    tempYear = date._year;
    if(date._month <= 2)
    {
        tempYear--;
    }
    dateDays += tempYear / 4 - tempYear / _oneHundreed + tempYear / _fourHundreed;

    return (abs(myDays - dateDays));
}



int Date::DaysTillYourBirthday(Date birthdaydate)
{
    int birthdaydate_year = _year;
    if(birthdaydate._day == _day && birthdaydate._month == _month)
    {
        return 0;
    }

    if(birthdaydate._day < _day && birthdaydate._month < _month)
    {
        birthdaydate_year++;
    }

    return Date::Duration(Date(birthdaydate_year, birthdaydate._month, birthdaydate._day));
}

QString Date::FromDateToString()
{
    return QDate(_year, _month, _day).toString("dd.MM.yyyy");
}

Date Date::FromQDatetoDate(QDate qdate)
{
    QString formattedQDate = QDate::currentDate().toString("dd.MM.yyyy");
    //qDebug() << formattedQDate;
    QString strDay = "", strMonth = "", strYear = "";
    for(int i = 0; i < 10; i++)
    {
        if(i >= 0 && i <= 1)
        {
            strDay += formattedQDate.at(i);
        }

        if(i >= 3 && i <= 4)
        {
            strMonth += formattedQDate.at(i);
        }

        if(i >= 6)
        {
            strYear += formattedQDate.at(i);
        }
    }

    int day = strDay.toInt(), month = strMonth.toInt(), year = strYear.toInt();
    return Date(year, month, day);
}

QString Date::FromIntToString(int num)
{
    return QString::number(num);
}

QString Date::FromShortToString(short num)
{
    return QString::number(num);
}

QString Date::FromBoolToString(bool flag)
{
    if(flag)
    {
        return "Yes";
    }
    return "No";
}
