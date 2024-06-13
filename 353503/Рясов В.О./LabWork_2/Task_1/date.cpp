#include "date.h"

#include <ctime>

constexpr int FIRST_DAY =     1;
constexpr int LAST_MONTH =    12;
constexpr int FIRST_MONTH =   1;
constexpr int FIRST_YEAR =   1;
constexpr int DAYS_IN_WEEK =  7;
constexpr int START_OF_CENTURY =       1900;
constexpr int DAYS_IN_NON_LEAP_YEAR =  365;
constexpr int DAYS_IN_LEAP_YEAR =  366;
constexpr int DAYS_IN_THIRTY_DAY_MONTH =      30;
constexpr int DAYS_IN_LEAP_FEBRUARY =         29;
constexpr int DAYS_IN_NON_LEAP_FEBRUARY =     28;
constexpr int DAYS_IN_THIRTY_ONE_DAY_MONTH =  31;
constexpr int daysInMonth[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

QString Date::nextDay()
{
    Date newdate(*this);
    if (newdate.getDay() == DAYS_IN_NON_LEAP_FEBRUARY and newdate.getMonth()==2 and !newdate.isLeap(getYear())
        or newdate.getDay() == DAYS_IN_LEAP_FEBRUARY and newdate.getMonth()==2 and newdate.isLeap(getYear())){
        newdate._day = FIRST_DAY;
        newdate._month++;
    }

    else if((newdate.getDay() <= DAYS_IN_THIRTY_DAY_MONTH and newdate.getMonth() <= 7 and newdate.getMonth() % 2 == 1) or
        (newdate.getDay() <= DAYS_IN_THIRTY_DAY_MONTH and newdate.getMonth() >= 8 and newdate.getMonth() % 2 == 0)
        or (newdate.getDay() <= DAYS_IN_NON_LEAP_FEBRUARY and newdate.getMonth()==2 and newdate.isLeap(getYear()))
        or (newdate.getDay() < DAYS_IN_THIRTY_DAY_MONTH and newdate.getMonth() <= 7
         and newdate.getMonth() % 2 == 0) or (newdate.getDay() < DAYS_IN_THIRTY_DAY_MONTH and newdate.getMonth() >= 8 and newdate.getMonth() % 2 == 1)){
        newdate._day++;
    }

    else if (newdate.getMonth() != LAST_MONTH){
        newdate._day = FIRST_DAY;
        newdate._month++;
    }

    else {
        newdate._day = FIRST_DAY;
        newdate._month = FIRST_MONTH;
        newdate._year++;
    }

    return newdate.toQString();
}

QString Date::previousDay()
{
    Date newdate(*this);

    if(newdate.getDay() == FIRST_DAY and newdate.getMonth() == FIRST_MONTH and newdate.getYear() == FIRST_YEAR){
        return "Error";
    }

    if(newdate.getDay()>FIRST_DAY){
        newdate._day--;
    }

    else if(newdate.getMonth() == 3 and newdate.getDay()==FIRST_DAY and newdate.isLeap(getYear())){
        newdate._day = DAYS_IN_LEAP_FEBRUARY;
    }

    else if(newdate.getMonth() == 3 and newdate.getDay()==FIRST_DAY and !newdate.isLeap(getYear())){
        newdate._day = DAYS_IN_NON_LEAP_FEBRUARY;
    }

    else if (newdate.getDay() == FIRST_DAY and newdate.getMonth() == FIRST_MONTH){
        newdate._day = DAYS_IN_THIRTY_ONE_DAY_MONTH;
        newdate._month = LAST_MONTH;
        newdate._year--;
    }

    else if (newdate.getDay() == FIRST_DAY and newdate.getMonth() <= 7 and newdate.getMonth() % 2 == 1
             or newdate.getDay() == FIRST_DAY and newdate.getMonth() >= 8 and newdate.getMonth() % 2 == 0){
        newdate._day = DAYS_IN_THIRTY_ONE_DAY_MONTH;
        newdate._month--;
    }

    else{
        newdate._day = DAYS_IN_THIRTY_DAY_MONTH;
        newdate._month--;
    }

    return newdate.toQString();
}

QString Date::daysTillYourBirthday(Date birthday)
{
    int days = 0;
    time_t t = std::time(nullptr);
    std::tm * now = std::localtime(&t);

    /* Создаем объект Date для текущей даты */
    Date currentDate(now->tm_mday, now->tm_mon + 1, now->tm_year + START_OF_CENTURY);

    /* Создаем объект Date для следующего дня рождения */
    Date nextBirthday(birthday._day, birthday._month, currentDate._year);

    /* Вычисляем количество дней между текущей датой и следующим днем рождения */
    days += currentDate.duration(nextBirthday);

    if(nextBirthday._month < currentDate._month or nextBirthday._month == currentDate._month and
                                                        nextBirthday._day < currentDate._day){
        days = currentDate.isLeap(currentDate._year)? DAYS_IN_LEAP_YEAR - days : DAYS_IN_NON_LEAP_YEAR - days;
    }

    if (nextBirthday._day == DAYS_IN_LEAP_FEBRUARY and nextBirthday._month == 2) {
        days += DAYS_IN_NON_LEAP_YEAR * 3;
    }

    QString line = QString::number(days);

    return line;
}

int Date::duration(Date date)
{
    time_t t = std::time(nullptr);
    std::tm * now = std::localtime(&t);
    Date currentDate(now->tm_mday, now->tm_mon + 1, now->tm_year + START_OF_CENTURY);
    /* Создаем копии дат, которые будем изменять */
    //Date startDate(*this);
    Date endDate(date);

    /* Вычисляем разницу в годах и количество високосных лет */
    int yearsDifference = endDate._year - currentDate._year;
    int leapYears = yearsDifference / 4 - yearsDifference / 100 + yearsDifference / 400;

    /* Вычисляем количество дней */
    int days = 0;
    days += DAYS_IN_NON_LEAP_YEAR * yearsDifference + leapYears;
    days -= currentDate._day;
    days += endDate._day;

    /* Учитываем количество дней в каждом месяце */
    for (int i = 0; i < currentDate._month - 1; i++){
        days -= daysInMonth[currentDate.isLeap(currentDate.getYear())][i];
    }

    for (int i = 0; i < endDate._month - 1; i++){
        days += daysInMonth[endDate.isLeap(endDate.getYear())][i];
    }

    return abs(days);
}

bool Date::isLeap(int year)
{
    if(year % 100 == 0 and year % 400 != 0){
        return false;
    }
    else if(year % 4 == 0){
        return true;
    }
    return false;
}

QString Date::weekNumber()
{
    std::tm timeStruct = {};
    timeStruct.tm_mday = _day;
    timeStruct.tm_mon = _month - 1;
    timeStruct.tm_year = _year - START_OF_CENTURY;
    mktime(&timeStruct);
    QString line = QString::number((timeStruct.tm_yday / DAYS_IN_WEEK) + 1);
    return line;
}

QString Date::toQString()
{
    return QString("%1-%2-%3").arg(_day).arg(_month).arg(_year);
}


