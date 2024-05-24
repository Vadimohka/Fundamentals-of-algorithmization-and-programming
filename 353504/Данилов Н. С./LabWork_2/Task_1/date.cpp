#include "date.h"
#include <QDebug>

Date::Date(short d, short m, short y) {
    day = d;
    month = m;
    year = y;
}

short Date::GetYear(){
    return year;
}

short Date::GetMonth(){
    return month;
}

short Date::GetDay(){
    return day;
}

void Date::SetYear(short a){
    year = a;
}

void Date::SetMonth(short a){
    month = a;
}

void Date::SetDay(short a){
    day = a;
}

Date Date::NextDay() {
    int daysInMonth;
    switch (month) {
    case 2:
        daysInMonth = (this->IsLeap() ? 29 : 28);
        break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
        break;
    }

    if (day < daysInMonth)
        return Date(day + 1, month, year);
    else {
        if (month < 12)
            return Date(1, month + 1, year);
        else
            return Date(1, 1, year + 1);
    }
}

Date Date::PreviousDay(){
    if (day > 1)
        return Date(day - 1, month, year);
    else {
        if (month > 1)
            return Date(31, month - 1, year);
        else
            return Date(31, 12, year - 1);
    }
}

bool Date::IsLeap() {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool Date::isLeap(short y) {
    if (y % 400 == 0)
        return true;
    if (y % 100 == 0)
        return false;
    if (y % 4 == 0)
        return true;
    return false;
}

short Date::WeekNumber() {
    short sum = dayOfWeekOfYearBegin(year);
    switch (month) {
    case 2:
        sum += 31;
        break;
    case 3:
        sum += (this->IsLeap() ? 60 : 59);
        break;
    case 4:
        sum += (this->IsLeap() ? 91 : 90);
        break;
    case 5:
        sum += (this->IsLeap() ? 121 : 120);
        break;
    case 6:
        sum += (this->IsLeap() ? 152 : 151);
        break;
    case 7:
        sum += (this->IsLeap() ? 182 : 181);
        break;
    case 8:
        sum += (this->IsLeap() ? 213 : 212);
        break;
    case 9:
        sum += (this->IsLeap() ? 244 : 243);
        break;
    case 10:
        sum += (this->IsLeap() ? 274 : 273);
        break;
    case 11:
        sum += (this->IsLeap() ? 305 : 304);
        break;
    case 12:
        sum += (this->IsLeap() ? 335 : 334);
        break;
    }
    sum += day - 2;
    return (sum / 7) + 1;
}

short Date::dayOfWeekOfYearBegin(short y){
    short totalDays = 4, totalYears = 1582;
    while (totalYears < y)
    {
        if (isLeap(totalYears))
        {
            ++totalYears;
            totalDays += 366;
        }
        else
        {
            ++totalYears;
            totalDays += 365;
        }

        totalDays %= 7;
    }
    return totalDays + 1;
};

int Date::DaysTillYourBithday(Date birth){
    auto a = birth;
    if (!this->IsLeap() && (a.GetMonth() == 2 && a.GetDay() == 29)){
        a.SetMonth(3);
        a.SetDay(1);
    }
    if ((month < a.GetMonth()) || (month == a.GetMonth() && day < a.GetDay())){
        return duration(Date(day, month, year), Date(a.GetDay(), a.GetMonth(), year));
    } else {
        return duration(Date(day, month, year), Date(a.GetDay(), a.GetMonth(), year));
    }
}

int Date::Duration(Date dur){
    auto a = dur;
    // if (!this->IsLeap() && (a.GetMonth() == 2 && a.GetDay() == 29)){
    //     a.SetMonth(3);
    //     a.SetDay(1);
    // }
    if (year < a.GetYear() || (year == a.GetYear() && month < a.GetMonth()) || (year == a.GetYear() && month == a.GetMonth() && day < a.GetDay())){
        return duration(Date(day, month, year), Date(a.GetDay(), a.GetMonth(), a.GetYear()));
    } else {
        return duration(Date(a.GetDay(), a.GetMonth(), a.GetYear()), Date(day, month, year));
    }
}

int Date::duration(Date f, Date s){
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int daysFirst = f.day;
    for (int m = 1; m < month; ++m)
        daysFirst += daysInMonth[m - 1];
    daysFirst += (f.year - 1) * 365 + (f.year - 1) / 4 - (f.year - 1) / 100 + (f.year - 1) / 400;


    int daysSecond = s.day;
    for (int m = 1; m < s.month; ++m)
        daysSecond += daysInMonth[m - 1];
    daysSecond += (s.year - 1) * 365 + (s.year - 1) / 4 - (s.year - 1) / 100 + (s.year - 1) / 400;

    return abs(daysSecond - daysFirst);
}

QString Date::ToQString(){
    QString ans = "";
    if (day<10){
        ans.push_back('0');
    }
    ans.push_back(QString::number(day));
    ans.push_back('.');
    if (month<10){
        ans.push_back('0');
    }
    ans.push_back(QString::number(month));
    ans.push_back('.');
    ans.push_back(QString::number(year));
    return ans;
}




