//
// Created by volodya-petarda on 4/2/24.
//

#include "Date.h"

bool Date::IsLeap() {
    return IsLeap(this->year);
}

int Date::InDays() {
    int ans = 0;
    for(int y = 1; y < this->year; y++){
        if(IsLeap(y)) {
            ans += 366;
        }
        else
            ans += 365;
    }
    for(int m = 1; m < this->month; m++){
        if(m == 2 && this->IsLeap()){
            ans++;
        }
        ans += DAYS_IN_MONTH[m];
    }
    ans += this->day - 1;
    return ans;
}

bool Date::IsLeap(int year) {
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}

Date::Date(short day, short month, short year) {
    this->day = day;
    this->month = month;
    this->year = year;
    if(this->ToString() != this->NextDay().PreviousDay().ToString()){
        throw "loh";
    }
}

short Date::DayOfWeek() {
    return InDays() % 7;
}

Date::Date(int days) {
    this->year = 1;
    this->month = 1;
    this->day = 1;

    while(days >= 365){
        if(IsLeap()){
            if(days >= 366){
                days -= 366;
                year++;
            }
            else{
                break;
            }
        }
        else{
            days-= 365;
            year++;
        }
    }

    for(int m = 1; m <= 11; m++){
        int val = DAYS_IN_MONTH[m];
        if(m == 2 && IsLeap()){
            val++;
        }
        if(days >= val){
            this->month = m + 1;
            days -= val;
        }
        else{
            break;
        }
    }
    this->day = days + 1;
}

std::string Date::ToString() {
    std::string res = "00.00.0000";
    res[0] = ('0' + this->day % 100 / 10);
    res[1] = ('0' + this->day % 10 / 1);

    res[3] = ('0' + this->month % 100 / 10);
    res[4] = ('0' + this->month % 10 / 1);

    res[6] = ('0' + this->year % 10000 / 1000);
    res[7] = ('0' + this->year % 1000 / 100);
    res[8] = ('0' + this->year % 100 / 10);
    res[9] = ('0' + this->year % 10 / 1);
    return res;
}

Date Date::NextDay() {
    return Date(this->InDays() + 1);
}

Date Date::PreviousDay() {
    return Date(this->InDays() - 1);
}

short Date::WeekNumber() {
    return (Date(1, 1, this->year).Duration(*this) + Date(1, 1, this->year).DayOfWeek()) / 7 + 1;
}

int Date::Duration(Date date) {
    return date.InDays() - InDays();
}

Date::Date(std::string s) {
    short day, month, year;
    day = (s[0] - '0') * 10 + (s[1] - '0');
    month = (s[3] - '0') * 10 + (s[4] - '0');
    year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
    this->day = day;
    this->month = month;
    this->year = year;
    new Date(day, month, year);
}

int Date::DaysTillYourBirthday(Date birthdayDate) {
    if(birthdayDate.day == 29 && birthdayDate.month == 2){
        int ans = 0;
        if(IsLeap(year)){
            Date d1(day, month, year);
            Date d2(birthdayDate.day, birthdayDate.month, year);
            int d = d1.Duration(d2);
            if(d >= 0)
                return d;
        }
        int tyear = year;
        while(true){
            ans += 365;
            if(IsLeap(year))
                ans++;
            tyear++;
            if(IsLeap(tyear)){
                Date d1(day, month, tyear);
                Date d2(birthdayDate.day, birthdayDate.month, tyear);
                int d = d1.Duration(d2);
                ans += d;
                return ans;
            }
        }

    }
    Date d1(day, month, year);
    Date d2(birthdayDate.day, birthdayDate.month, year);
    int d = d1.Duration(d2);
    if(d < 0){
        d2 = Date(birthdayDate.day, birthdayDate.month, year + 1);
        d = d1.Duration(d2);
    }
    return d;
}

