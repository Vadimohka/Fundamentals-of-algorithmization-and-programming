#include "date.h"
#include <QDebug>

Date::Date(short day, short month, short year) : day(day), month(month), year(year){
}

Date::~Date(){

}

void Date::setDay(short day){
    this->day = day;
}

void Date::setMonth(short month){
    this->month = month;
}

void Date::setYear(short year){
    this->year = year;
}

short Date::getDay() const{
    return this->day;
}

short Date::getMonth() const{
    return this->month;
}

short Date::getYear() const{
    return this->year;
}

bool Date::isLeap() const{
    return ((this->year % 4 == 0 && this->year % HUNDRED !=0) || this->year % FOUR_HUNDRED == 0);
}

bool Date::isLeap(int year) const{
    return ((year % 4 == 0 && year % HUNDRED != 0) || year % FOUR_HUNDRED == 0);
}

short Date::dayOnMonth(short month){

    short days = 31;
    short new_month = month;

    if (new_month == 2)
        days = isLeap() ? 29 : 28;

    else if (new_month == 4 || new_month == 6 || new_month == 9 || new_month == 11)
        days = 30;

    return days;
}

Date Date::NextDay() {

    short new_day = this->day;
    short new_month = this->month;
    short new_year = this->year;
    short days = 31;

    if (this->month == 2)
        days = isLeap() ? 29 : 28;
    else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
        days = 30;

    new_day++;
    if (new_day > days) {
        new_day = 1;
        new_month++;
        if (new_month > 12) {
            new_month = 1;
            new_year++;
        }
    }

    return Date(new_day, new_month, new_year);
}

Date Date::PreviousDay() const{

    short new_day = this->day;
    short new_month = this->month;
    short new_year = this->year;
    short days = 31;

    new_day--;

    if (new_month == 2)
        days = isLeap() ? 29 : 28;

    else if (new_month == FOUR || new_month == SIX || new_month == NINE || new_month == 11)
        days = 30;

    if(new_day == 0){
        new_month--;
        if(new_month == 0){
            new_month = TWELVE;
            new_year--;
        }
        new_day = days;
    }

    return Date(new_day, new_month, new_year);
}

QString Date::dayOfWeeks(){

    short days = dayOfWeek();
    switch (days) {

    case ONE:
        return "Monday";
        break;

    case TWO:
        return "Tuesday";
        break;

    case THREE:
        return "Wensday";
        break;

    case FOUR:
        return "Thursday";
        break;

    case FIVE:
        return "Friday";
        break;

    case SIX:
        return "Saturday";
        break;

    case SEVEN:
        return "Sunday";
        break;

    default:
        return "";
        break;
    }
}

QString Date::dateToString(){

    QString str_date = QString("%1.%2.%3").arg(this->day, TWO, TEN, QChar('0'))
                           .arg(this->month, TWO, TEN, QChar('0'))
                           .arg(this->year, FOUR, TEN, QChar('0'));

    return str_date;
}

short Date::WeekNumber(){

    short days = this->day;

    for(short i = 1; i < this->month; i++){
        days += dayOnMonth(i);
    }

    Date first_day(01, 01, this->year);

    short firstDayOfYear = first_day.dayOfWeek();

    days += firstDayOfYear - 1;

    return (days % SEVEN == 0) ? days / SEVEN : days / SEVEN + ONE;
}

short Date::dayOfWeek() {

    short new_month = this->month;
    short new_year = this->year;
    short new_day = this->day;
    short week_day;
    short days_week[SEVEN] = {SIX, SEVEN, ONE, TWO, THREE, FOUR, FIVE};

    if (new_month < THREE) {
        new_month += TWELVE;
        new_year--;
    }

    short z_year = new_year / HUNDRED;
    short d_year = new_year % HUNDRED;

    week_day = (new_day + ((THIRTEEN * (new_month + ONE)) / FIVE) + d_year + (d_year / FOUR) + (z_year / FOUR) - (TWO * z_year)) % SEVEN;

    return days_week[week_day];
}



int Date::DaysTillYourBithday(Date bithdaydate){

    Date nextBithday(bithdaydate.getDay(), bithdaydate.getMonth(), this->year);
    if (bithdaydate.getYear() > this->year)
        return Duration(bithdaydate);

    else if (Duration(nextBithday) < 0)
        return this->Duration(Date(bithdaydate.getDay(), bithdaydate.getMonth(), this->year+1));

    else
        return Duration(Date(bithdaydate.getDay(), bithdaydate.getMonth(), this->year));

}

int Date::Duration(Date date){

    int date_day = date.getDay();
    short date_year = date.getYear();
    short new_year = this->year;
    int new_day = this->day;


    for(short i = 1; i < this->month; ++i){
        new_day += dayOnMonth(i);
    }
    for(short i = 1; i < date.getMonth(); ++i){
        date_day += dayOnMonth(i);
    }
    for(short i = 0; i < this->year % 4; ++i){
        new_day += isLeap(new_year)?DAYS_IN_LEAP_YEAR:DAYS_IN_YEAR;
        new_year--;
    }
    for(short i = 0; i < date.getYear() % 4; ++i){
        date_day += isLeap(date_year)?DAYS_IN_LEAP_YEAR:DAYS_IN_YEAR;
        date_year--;
    }

    new_day += new_year/ FOUR * DAYS_IN_LEAP_YEAR + new_year / FOUR * THREE * DAYS_IN_YEAR - new_year / FOUR_HUNDRED * THREE;
    date_day += date_year / FOUR*DAYS_IN_LEAP_YEAR + date_year / FOUR * DAYS_IN_YEAR * THREE - date_year / FOUR_HUNDRED * THREE;

    return date_day - new_day;
}

