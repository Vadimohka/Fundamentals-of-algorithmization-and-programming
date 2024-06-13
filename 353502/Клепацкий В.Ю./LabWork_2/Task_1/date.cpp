#include "date.h"

Date::Date(int _day, int _month, int _year) {
    year = _year;
    month = _month;
    day = _day;

    setDate();
}

Date::Date(QString _date){
    QString dayStr = _date.left(2);
    QString monthStr = _date.mid(3, 2);
    QString yearStr = _date.right(4);

    year = yearStr.toInt();
    month = monthStr.toInt();
    day = dayStr.toInt();
    date = _date;
}


Date* Date::nextday()
{
    Date* next = new Date(this->day, this->month, this->year);
    if (next->date == "31.12.9999"){
        next->date = "end of times";
    }
    else{
        if(next->isLeap() && next->day == 29 && next->month == 2){
            next->day = 1;
            next->month = 3;
        }
        else if (next->day == 31 && next->month == 12){
            next->day = 1;
            next->month = 1;
            ++next->year;
        }
        else if(next->day == 30 && mon30.contains(next->month) || next->day == 31){
            next->day = 1;
            ++next->month;
        }
        else if(!next->isLeap() && next->day == 28 && next->month == 2){
            next->day = 1;
            next->month = 3;
        }


        else {
            ++next->day;
        }

        next->setDate();
    }
    return next;

}

Date* Date::previousDate(){
    Date* prev = new Date(this->day, this->month, this->year);
    if (prev->date == "01.01.0001"){
        prev->date = "begin of times";
    }
    else{
        if (prev->day == 1){
            if (prev->month == 3 && prev->isLeap()){
                prev->month = 2;
                prev->day = 29;
            }
            else if(prev->month == 3 && !prev->isLeap()){
                prev->month = 2;
                prev->day = 28;
            }
            else if(prev->month == 1){
                prev->day = 31;
                prev->month = 12;
                --prev->year;
            }
            else {
                --prev->month;
                if(mon30.contains(prev->month)){
                    prev->day = 30;
                }
                else{
                    prev->day = 31;
                }
            }
        }
        else{
            --prev->day;
        }

        prev->setDate();
    }
    return prev;
}

QString Date::getDate()
{
    return date;
}

int Date::daysTillYourBirthday(Date *birthdayDate)
{
    return this->duration(birthdayDate);
}

QString Date::getDuration(Date* current)
{
    return QString::number(this->duration(current));
}

int Date::duration(Date *current)
{

    int days1 = this->day;
    int days2 = current->day;

    int mon1 = this->month;
    int mon2 = current->month;
    --mon1;
    --mon2;

    while(mon1 > 0){
        if (mon1 == 2){
            if (this->isLeap())
                days1 += 29;
            else
                days1 += 28;
        }
        else if (mon30.contains(mon1))
            days1 += 30;
        else
            days1 += 31;
        --mon1;
    }

    while(mon2 > 0){
        if (mon2 == 2){
            if (current->isLeap())
                days2 += 29;
            else
                days2 += 28;
        }
        else if (mon30.contains(mon2))
            days2 += 30;
        else
            days2 += 31;
        --mon2;
    }
    int y1 = this->year - 1;
    int y2 = current->year - 1;
    days1 += 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400;
    days2 += 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400;
    return days1 - days2;
}

QString Date::getWeekNumber()
{
    switch(this->weekNumber()){
    case 1:{
        return "Monday";
        break;
    }
    case 2:{
        return "Tuesday";
        break;
    }
    case 3:{
        return "Wednesday";
        break;
    }
    case 4:{
        return "Thursday";
        break;
    }
    case 5:{
        return "Friday";
        break;
    }
    case 6:{
        return "Saturday";
        break;
    }
    case 0:{
        return "Sunday";
        break;
    }
    }
}

bool Date::isCorrect()
{
    if (this->year < 1 || this->year > 9999)
        return false;

    if (this->month < 1 || this->month > 12)
        return false;

    if (this->day < 1 || this->day > 31)
        return false;

    if (month == 2){
        if (this->isLeap() && day > 29)
            return false;
        else if(day > 28)
            return false;
    }
    else if (mon30.contains(month) && day == 31)
        return false;

    return true;
}


void Date::setDate()
{
    QString yearStr = QString::number(year);
    QString monthStr = QString::number(month);
    QString dayStr = QString::number(day);

    while(monthStr.size() < 2){
        monthStr = "0" + monthStr;
    }

    while(dayStr.size() < 2){
        dayStr = "0" + dayStr;
    }

    while(yearStr.size() < 4){
        yearStr = "0" + yearStr;
    }

    date = dayStr + "." + monthStr + "." + yearStr;
}


bool Date::isLeap(){
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}


short Date::weekNumber()
{
    int mon = month;
    int week = day;

    --mon;

    while(mon > 0){
        if (mon == 2){
            if (this->isLeap())
                week += 29;
            else
                week += 28;
        }
        else {
            if (mon30.contains(mon))
                week += 30;
            else
                week += 31;
        }
        --mon;
    }
    --year;
    week += year - 1 + year / 4 - year / 100 + year / 400;
    ++year;
    week += 1;
    return (week + 7) % 7;
}



