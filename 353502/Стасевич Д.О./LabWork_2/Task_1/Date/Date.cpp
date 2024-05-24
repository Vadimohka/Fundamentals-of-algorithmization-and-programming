//
// Created by darina on 3/30/24.
//

#include "Date.h"

#include<QDebug>

Date::Date(short d, short m, short yer) {
    if (yer > 9999) {
        throw "Calendar ended :(";
    }
    if (yer < 1) {
        throw "Calendar not started :(";
    }
    if (m > 12) {
        throw "There is no such a month";
    }
    if (m < 1) {
        throw "There is no such a month";
    }
    if (d < 1) {
        throw "There is no such a day";
    }
    leap = IsLeap(yer);
    short cur_max_day = y[m];
    if (m == 2) {
        cur_max_day += leap;
    }
    if (d > cur_max_day) {
        throw "There is no such a day";
    }
    day = d;
    month = m;
    year = yer;
}

Date Date::NextDay() const {
    short cur_max_days = y[month];
    if(month == 2)
        cur_max_days += leap;
    if(day + 1 <= cur_max_days)
    {
        return {short(day + 1), month, year};
    }
    if(month + 1 <= 12)
    {
        return {1, short(month + 1), year};
    }
    return {1, 1, short(year + 1)};
}

Date Date::PreviousDay() const{
    if(day - 1 >= 1)
        return {short(day - 1), month, year};
    if(month - 1 >= 1)
    {
        if(month - 1 == 2 && leap)
        {
            return {29, 2, year};
        }
        return {y[month - 1], short(month - 1), year};
    }
    return {31, 12, short(year - 1)};
}

bool Date::IsLeap() const {
    if(year % 400 == 0)
        return true;
    if(year % 100 == 0)
        return false;
    if(year % 4 == 0)
        return true;
    return false;
}

bool Date::IsLeap(short y) {
    if(y % 400 == 0)
        return true;
    if(y % 100 == 0)
        return false;
    if(y % 4 == 0)
        return true;
    return false;
}

short Date::WeekNumber(Date d) {
    short dayNumber = 0;
    for(short i = 1; i < d.month; i ++)
    {
        dayNumber += y[d.month];
    }
    if(d.month > 2)
        dayNumber += IsLeap(d.year);
    dayNumber += d.day;
    int ret = dayNumber / 7;
    if(dayNumber % 7 != 0)
        ret ++;
    return ret;
}

int Date::DaysTillYourBirthday(Date birthdaydate) const {
    Date today = GetToday();
    int nowadays = DayFromBeginning(today);
    if(birthdaydate.day == 29 && birthdaydate.month == 2)
    {
        if(IsLeap(today.year))
        {
            int birthdayThisYear = DayFromBeginning(Date(birthdaydate.day, birthdaydate.month, today.year));
            if(birthdayThisYear >= nowadays)
                return birthdayThisYear - nowadays;
        }
        int nextLeap = today.year + 1;
        while(!IsLeap(nextLeap))
            nextLeap ++;
        if(nextLeap > 9999)
            throw "Calendar is ended :(";
        int birthdayNextYear = DayFromBeginning(Date(birthdaydate.day, birthdaydate.month, nextLeap));
        return birthdayNextYear - nowadays;
    }
    int birthdayThisYear = DayFromBeginning(Date(birthdaydate.day, birthdaydate.month, today.year));
    if(birthdayThisYear >= nowadays)
        return birthdayThisYear - nowadays;
    if(year == 9999)
        throw "Calendar is ended :(";
    int birthdayNextYear = DayFromBeginning(Date(birthdaydate.day, birthdaydate.month, today.year + 1));
    return birthdayNextYear - nowadays;
}

int Date::Duration(Date date) {
    Date today = GetToday();
    int nowadays = DayFromBeginning(today);
    int givenDate = DayFromBeginning(date);
    return std::abs(nowadays - givenDate);
}

int Date::Duration(Date date1, Date date2) {
    return std::abs(DayFromBeginning(date1) - DayFromBeginning(date2));
}

QString Date::DayToString(Date date) {
    QString ret;
    if(date.day < 10)
        ret.append('0');

    QString forConvert;
    forConvert = QString::number(date.day);
    ret += forConvert;
    ret += ".";
    if(date.month < 10)
        ret += "0";
    forConvert = QString::number(date.month);
    ret += forConvert;
    ret += ".";
    int t = 1000;
    while(date.year / t == 0)
    {
        ret += "0";
        t /= 10;
    }
    forConvert = QString::number(date.year);
    ret += forConvert;
    return ret;
}

Date Date::GetToday() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return Date(timeinfo->tm_mday, timeinfo->tm_mon + 1, 1900 + timeinfo->tm_year);
}

short Date::LeapTillNow(short yy) {
    return yy / 4 - yy / 100 + yy / 400;
}

int Date::DayFromBeginning(Date date) {
    int ret = 365 * (date.year - 1) + LeapTillNow(date.year - 1);
    for(int i = 0; i < date.month; i ++)
    {
        ret += y[i];
    }
    if(IsLeap(date.year) && date.month > 2)
        ret ++;
    ret += date.day;
    return ret;
}

Date Date::StringToDate(const QString& s){

    auto *ar = new short (3);
    ar[0] = ar[1] = ar[2] = 0;
    int pos = 0;
    qDebug() << s;
    if(s.size() != 10)
        return {-1, -1, -1};
    int i = 0;
    for(auto x : s) {
        if(x == '.') {
            if(i == 2 || i == 5) {
                i++;
                pos ++;
                if(pos > 2)
                    return {-1, -1, -1};
                continue;
            }
            else {
                return {-1, -1, -1};
            }
        }
        if(x.isDigit()) {
            if(i == 2 || i == 5)
                return {-1, -1, -1};
            i ++;
            ar[pos] *= 10;
            ar[pos] += x.digitValue();
            continue;
        }
        return {-1, -1, -1};
    }
    return {ar[0], ar[1], ar[2]};
}

