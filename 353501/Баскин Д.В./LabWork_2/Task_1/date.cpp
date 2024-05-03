#include "date.h"

Date::Date(int year, int month,int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
    daysInMonth[1] = isLeap() ? 29 : 28;
}

Date::~Date()
{

}

int Date::getDaysInMonth(int month, int year)
{
    Date date(year, month, 1);

    return date.daysInMonth[month - 1];
}

Date Date::fromString(const QString& str)
{
    if (str[2] != '.' || str[5] != '.' || str.length() != 10)
    {
        throw std::invalid_argument("Invalid Format");
    }

    QString Day, Month, Year;
    for (int i = 0; i < 10; ++i)
    {
        if (i == 2 || i == 5)
        {
            continue;
        }

        if (str[i] < '0' || str[i] > '9')
        {
            throw std::invalid_argument("Invalid Format");
        }

        if (i < 2)
        {
            Day += str[i];
        }
        else if (i > 2 && i < 5)
        {
            Month += str[i];
        }
        else if (i > 5)
        {
            Year += str[i];
        }
    }

    int day = Day.toInt();
    int month = Month.toInt();
    int year = Year.toInt();

    if (month > 12 || day > 31 || month < 0 || day < 0 || year > 9999 || year < 0)
    {
        throw std::invalid_argument("Invalid Format");
    }

    if (!isLeap(year) && month == 2 && day > 28)
    {
        throw std::invalid_argument("Invalid Format");
    }

    if (isLeap(year) && month == 2 && day > 29)
    {
        throw std::invalid_argument("Invalid Format");
    }

    if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        throw std::invalid_argument("Invalid Format");
    }

    return Date(year, month, day);
}

QString Date::toString()
{
    QString str = "";

    str += day > 9 ? QString::number(day) + "." : "0" + QString::number(day) + ".";
    str += month > 9 ? QString::number(month) + "." : "0" + QString::number(month) + ".";
    for (int i = 0; i < 4 - QString::number(year).size(); i++)
    {
        str += "0";
    }
    str += QString::number(year);
    return str;
}

QString Date::boolToString(bool from)
{
    return from ? "Yes" : "No";
}

QString Date::intToString(int from)
{
    QString str;
    return str.setNum(from);
}

Date Date::nextDay()
{
    if (month == 12 && day == 31)
    {
        return Date(year + 1, 1, 1);
    }
    else if (day == 29 && month == 2)
    {
        return Date(year, 3, 1);
    }
    else if (day == daysInMonth[month - 1])
    {
        return Date(year, month + 1, 1);
    }
    return Date(year, month, day + 1);
}

Date Date::previousDay()
{
    if (month == 1 && day == 1)
    {
        return Date(year - 1, 12, 31);
    }
    else if (day == 1)
    {
        if (month == 3 && isLeap())
        {
            return Date(year, 2, 29);
        }
        return Date(year, month - 1, daysInMonth[month - 2]);
    }
    return Date(year, month, day - 1);
}

bool Date::isLeap()
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool Date::isLeap(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int Date::weekNumber()
{
    int sum = 0;
    for (int i = 0; i < month - 1; ++i)
    {
        sum += daysInMonth[i];
    }
    sum += day;

    if (sum % 7 == 0)
    {
        return sum / 7;
    }
    return (sum / 7) + 1;
}

Date Date::todayDate()
{
    time_t rawTime = time(NULL);
    tm* timeStruct = localtime(&rawTime);
    return Date(timeStruct->tm_year + 1900, timeStruct->tm_mon + 1, timeStruct->tm_mday);
}

int Date::daysBeforeYourBithday(const Date& birthdayDate)
{
    int sum = 0;

    if (birthdayDate.month >= this->month)
    {
        for (int i = this->month - 1; i < birthdayDate.month - 1; ++i)
        {
            sum += this->daysInMonth[i];
        }
        sum -= this->day;
        sum += birthdayDate.day;
    }
    else
    {
        for (int i = this->month - 1; i < 12; ++i)
        {
            sum += this->daysInMonth[i];
        }
        sum-= this->day;

        for (int i = 0; i < birthdayDate.month - 1; ++i)
        {
            sum += this->daysInMonth[i];
        }
        sum += birthdayDate.day;
    }
    if (sum < 0)
    {
        sum = (isLeap(birthdayDate.year || isLeap(this->year)) ? 366 : 365) + sum;
    }

    if (sum == 0)
    {
        sum = (isLeap(this->year) ? 366 : 365);
    }
    return sum;
}

int Date::duration()
{
    Date current = Date::todayDate();
    int leastYear = (current.year <= this->year ? current.year : this->year);
    int daysCurrentDate = daysFromYearTo(leastYear, current);
    int daysNextDate = daysFromYearTo(leastYear, *this);
    return abs(daysCurrentDate - daysNextDate);
}

int Date::daysFromYearTo(int year, const Date& date)
{
    int sum = 0;
    for (int i = year; i < date.year; i++)
    {
        sum += date.isLeap(i) ? 366 : 365;
    }
    for (int i = 0; i < date.month - 1; i++)
    {
        sum += date.daysInMonth[i];
    }
    sum += date.day;
    return sum;
}
