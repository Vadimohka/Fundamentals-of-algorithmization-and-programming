#include "my_date.h"

My_Date::My_Date() {}

bool My_Date::isCorrectDate(int year, int month, int day)
{
    if (month < 1 || month > 12) return false;
    else if (!isLeapYear(year) && month == 2 && (day < 1 || day > 28)) return false;
    else if (isLeapYear(year) && month == 2 && (day < 1 || day > 29)) return false;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) return false;
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31)) return false;
    return true;
}

int My_Date::getYear()
{
    return year;
}

int My_Date::getMonth()
{
    return month;
}

int My_Date::getDay()
{
    return day;
}

bool My_Date::setDate(const QString &dateString) {
    QStringList parts = dateString.split(".");
    if (parts.size() != 3) {
        return false;
    }
    bool ok;
    int day = parts[0].toInt(&ok);
    if (!ok) {
        return false;
    }
    int month = parts[1].toInt(&ok);
    if (!ok) {
        return false;
    }

    int year = parts[2].toInt(&ok);
    if (!ok) {
        return false;
    }
    if (isCorrectDate(year, month, day)) {
        setDate(year, month, day);
        return true;
    }
    else {
        setDate(0,0,0);
        return false;
    }
}

void My_Date::setDate(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

QString My_Date::toString()
{
    QString formattedDate;
    if (day < 10)
        formattedDate += "0";
    formattedDate += QString::number(day);
    formattedDate += ".";
    if (month < 10)
        formattedDate += "0";
    formattedDate += QString::number(month);
    formattedDate += ".";
    if (year < 10)
        formattedDate += "000";
    else if (year < 100)
        formattedDate += "00";
    else if (year < 1000)
        formattedDate += "0";
    formattedDate += QString::number(year);
    if (year < 0) {
        setDate(-year, month, day);
        formattedDate += " BC";
        return formattedDate;
    }
    return formattedDate;
}

bool My_Date::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int My_Date::DaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

short My_Date::WeekNumber()
{
    int totalDays = 365 * (year - 1) + (year - 1) / 4 - (year - 1)/ 100 + (year - 1) / 400;
    int dayofweek = totalDays % 7;
    int cnt = 0;
    for (int i = 1; i < month; ++i) {
        cnt += DaysInMonth(i, year);
    }
    return ((cnt + day - ((dayofweek == 0)? 0:(7 - dayofweek)) - 1)/7 + ((dayofweek == 0)? 1:2));
}

void My_Date::addDays(int numDays)
{
    day += numDays;
}

int My_Date::TotalDays()
{
    int totalDays = 365 * (year - 1) + (year - 1) / 4 - (year - 1)/ 100 + (year - 1) / 400;
    int cnt = 0;
    for (int i = 1; i < month; ++i) {
        cnt += DaysInMonth(i, year);
    }
    return totalDays + cnt + day;
}
