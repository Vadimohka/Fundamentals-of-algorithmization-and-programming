#include "date.h"

static bool Leap(int year)
{
    return (year % 400 == 0)||((year % 4 == 0) && (year % 100 != 0));
}

static unsigned long long DateToDays(Date d)
{
    unsigned long long day = 0;
    for (int i = 0; i < d.getYear(); ++i)
    {
        day += Leap(i) ? 366 : 365;
    }
    for (int i = 0; i < d.getMonth() - 1; ++i)
    {
        day += d.getDayInMonth(i);
    }
    day += d.getDay();
    return day;
}


Date::Date(int day, int month, int year) :_day(day),_month(month),_year(year)
{
    this->_isLeap = Leap(year);
    if(&Leap)
        _monthDays[2]++;
    _qDate = new QDate(day,month,year);
}

Date::Date(QDate d)
{
    _qDate = &d;
    this->_isLeap = Leap(_year);
    if(&Leap)
        _monthDays[Month::February]++;
    this->_day = d.day();
    this->_month = d.month();
    this->_year = d.year();
}

QDate Date::getDate()
{
    return *_qDate;
}

int Date::getDayInMonth(int m_month)
{
    int dayInMonth = _monthDays.at(m_month - 1);
    return dayInMonth;
}

int Date::getDay()
{
    return _day;
}
int Date::getMonth()
{
    return _month;
}

int Date::getYear()
{
    return _year;
}

Date Date::NextDay()
{
    int m_day = _day + 1;
    int m_month = _month,m_year = _year;
    if (m_day > getDayInMonth(m_month))
    {
        m_day = 1;
        m_month++;
        if(m_month > 12)
        {
            m_month = 1;
            m_year++;
        }
    }
    return Date(m_day,m_month,m_year);
}

Date Date::PreviousDay()
{
    int m_day = this->_day - 1;
    int m_month = this->_month,m_year = this->_year;
    if (m_day == 0)
    {
        m_month--;
        if(m_month == 0)
        {
            m_month = 12;
            m_year--;
        }
       m_day = getDayInMonth(m_month);
    }
    return Date(m_day,m_month,m_year);
}

QString Date::toString()
{
    QString str = (this->_day <= 9 ? "0" : "") + QString::number(this->_day) + "." + (this->_month <= 9 ? "0" : "") + QString::number(this->_month) + "." +
                  (this->_year <= 9 ? "0" : "") + (this->_year <= 99 ? "0" : "") + (this->_year <= 999 ? "0" : "") + QString::number(this->_year);
    return str;
}

bool Date::isLeap()
{
    return Leap(_year);
}

int Date::DaysTillYourBithday(Date birthdayDate)
{
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    Date current(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);

    int sum = 0;

    if (birthdayDate._month >= current._month)
    {
        for (int i = current._month - 1; i < birthdayDate._month - 1; i++)
            sum += getDayInMonth(i);

        sum -= current._day;
        sum += birthdayDate._day;
    }
    else
    {
        for (int i = current._month - 1; i < 12; i++)
            sum += getDayInMonth(i);
        sum-= current._day;

        for (int i = 0; i < birthdayDate._month - 1; i++)
            sum += getDayInMonth(i);
        sum += birthdayDate._day;
    }
    if (sum < 0) sum = 365 - sum;

    return sum;
}
long long Date::Duration(Date m_date)
{
    int sum_1 = 0,sum_2 = 0;
    Date current = *this;
    bool wasSwap = false;
    unsigned long long day = 0;
    if(current.getYear() > m_date.getYear())
    {
        wasSwap = true;
        std::swap(current,m_date);
    }
    for (int i = current.getYear(); i < m_date.getYear(); ++i)
    {
        sum_2 += Leap(i) ? 366 : 365;
    }
    for (int i = 0; i < current.getMonth(); ++i)
    {
        sum_1 += current.getDayInMonth(i+1);
    }
    for (int i = 0; i < m_date.getMonth(); ++i)
    {
        sum_2 += m_date.getDayInMonth(i+1);
    }
    sum_1 += current.getDay();
    sum_2 += m_date.getDay();

    return (sum_2 - sum_1) * (wasSwap ? -1 : 1);
}

short Date::WeekNumber()
{
    int sum = 0;
    for (int i = 1; i < this->_month; i++)
        sum += getDayInMonth(i);
    sum += _day;

    if (sum % 7 == 0)
        return sum / 7;

    return (sum / 7) + 1;
}
