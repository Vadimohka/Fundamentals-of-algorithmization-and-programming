#include "date.h"

Date::Date()
{

}


void Date::setDay(int d){
    day = d;
}

void Date::setMonth(int m){
    month = m;
}

void Date::setYear(int y){
    year = y;
}

Date Date::NextDay(){
    QDate currentDate(year, month, day);
    QDate nextDay = currentDate.addDays(1);
    Date newDate;
    newDate.setDay(nextDay.day());
    newDate.setMonth(nextDay.month());
    newDate.setYear(nextDay.year());
    return newDate;
}

Date Date::PreviousDay(){
    QDate currentDate(year, month, day);
    QDate previousDay = currentDate.addDays(-1);
    Date newDate;
    newDate.setDay(previousDay.day());
    newDate.setMonth(previousDay.month());
    newDate.setYear(previousDay.year());
    return newDate;
}

bool Date::ISLeap(){
    QDate currentDate(year, month, day);

    if (QDate::isLeapYear(currentDate.year())){
        return true;
    }
    else
    {
        return false;
    }
}


short Date::WeekNumber(){
    QDate currentDate(year, month, day);

    return currentDate.weekNumber();
}


int Date::DaysTillYourBithday(Date bithDayDate){
    QDate currentDate(year, month, day);
    QDate userDate;
    if (bithDayDate.year < year){
        userDate = QDate (year, bithDayDate.month, bithDayDate.day);
    }
    else
    {
        userDate = QDate (bithDayDate.year, bithDayDate.month, bithDayDate.day);
    }

    int buf = currentDate.daysTo(userDate);

    if (buf < 0){
         userDate = QDate (year+1, bithDayDate.month, bithDayDate.day);
    }

    return currentDate.daysTo(userDate);
}


int Date::Duration(Date date){
    QDate currentDate(year, month, day);
    QDate userDate = QDate (date.year, date.month, date.day);

    int buf = currentDate.daysTo(userDate);

    if (buf < 0){
        buf = -buf;
    }

    return buf;
}
