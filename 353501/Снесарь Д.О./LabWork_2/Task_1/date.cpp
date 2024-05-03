#include "date.h"

Date::Date()
{
    daysInMonth[1] = isLeap() ? 29 : 28;
}

int Date::daysInYear(const int y) const
{

   if ((y % 4 == 0) && (!(y % 100 == 0) || (y % 100 == 0 && y % 400)))
        return 366;
   else
        return 365;
}


Date::Date (const Date &date)
{
    day = date.day;
    month = date.month;
    year = date.year;

    for(int i = 0; i < 12; i++)
        daysInMonth [i] = date.daysInMonth[i];
}


Date::Date(const QString date)
{
    day = (date.mid(0, 2)).toInt();
    month = (date.mid(3, 2)).toInt();
    year = (date.mid(6, 4)).toInt();
    daysInMonth[1] = isLeap() ? 29 : 28;
}

Date::Date(const time_t time)
{
    std::tm* currentDate = std::localtime(&time);
    day = currentDate->tm_mday;
    month = currentDate->tm_mon + 1;
    year = currentDate->tm_year + 1900;
    daysInMonth[1] = isLeap() ? 29 : 28;
}



bool Date::isLeap() const
{
    return ((year % 4 == 0) && (!(year % 100 == 0) || (year % 100 == 0 && year % 400)));
}



int Date::weekNumber() const
{
    int daySum = 0;
    for(int i = 0; i < month - 1; i++)
        daySum += daysInMonth[i];

    daySum += day;

    if (daySum % 7 == 0)
        return daySum / 7;
    else
        return ((daySum / 7) + 1);
}

Date Date::nextDay() const
{
    Date nextD = *this;

    nextD.day++;

    if(nextD.day > daysInMonth[nextD.month - 1]){
        nextD.day = 1;
        nextD.month++;
        if(nextD.month > 12){
            nextD.month = 1;
            nextD.year++;
            nextD.daysInMonth[1] = nextD.isLeap() ? 29 : 28;
        }
    }

    return nextD;
}

Date Date::previousDay() const
{
    Date prevD = *this;

    prevD.day--;
    if(prevD.day == 0){
        prevD.day = prevD.daysInMonth[month - 1];
        prevD.month--;
        if(prevD.month == 0){
            prevD.month = 12;
            prevD.year--;
            prevD.daysInMonth[1] = prevD.isLeap() ? 29 : 28;
        }
    }

    return prevD;
}

QString Date::getDateStr() const
{
    QString str = "";
    str += (day <= 9) ? ("0" + QString::number(day) + ".") : (QString::number(day) + ".");
    str += (month <= 9) ? ("0" + QString::number(month) + ".") : (QString::number(month) + ".");

    QString temp = QString::number(year);
    for(int i = 0; i < 4 - temp.size(); i++)
    {
        str += "0";
    }

    str += temp;


    return str;
}


int Date::difference(const Date &date) const
{
    int minYear = (year <= date.year) ? year : date.year;

    int dayF = 0;
    int dayS = 0;
    //qDebug() << year << "  " << date.year << "  "<< minYear;


    for (int i = minYear; i < year; i++)
    {
        dayF += this->daysInYear(i);
    }

    for(int i = 0; i < month - 1; i++)
    {
        dayF += daysInMonth[i];
    }

    dayF += day;

    ///////

    for (int i = minYear; i < date.year; i++)
    {
        dayS += this->daysInYear(i);

    }


    for(int i = 0; i < date.month - 1; i++)
    {
        dayS += date.daysInMonth[i];
    }

    dayS += date.day;

    return std::abs(dayF - dayS);
}

int Date::daysTillYourBirthday(const Date &date) const
{
    Date newDate = date;
    newDate.year = year;
    if(date.month < month || (date.month == month && date.day < day)){
        newDate.year = year + 1;
    }
    else
        newDate.year = year;

    return this->difference(newDate);
}


