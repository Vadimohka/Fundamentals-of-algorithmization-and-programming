#include "date.h"

std::string Date::to_str() {
    if(IsCorrectInput())
    {
    if(day<10&&month<10)
        return '0'+std::to_string(day) + "." +'0'+ std::to_string(month) + "." + std::to_string(year);
    else if(day<10)
        return '0'+std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    else if(month<10)
        return std::to_string(day) + "." + '0'+std::to_string(month) + "." + std::to_string(year);
    else
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    }
    else
        return "-";

}
bool Date::IsCorrectInput() {
    if ((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (day<1 || day>31)) {
        return false;
    } else if ((month==4 || month==6 || month==9 || month==11) && (day<1 || day>30)) {
        return false;
    } else if (month==2 && year==IsLeap() && (day<1 || day>29)) {
        return false;
    } else if (month==2 && year!=IsLeap() && (day<1 || day>28)) {
        return false;
    } else if (month<1 || month>12) {
        return false;
    } else if (year<0) {
        return false;
    }
    return true;
}
bool Date::IsLeap() {
    if ((year%100==0 && year%400==0) || (year%4==0 && year%100!=0)) {
        return true;
    } else {
        return false;
    }
}
Date Date::NextDay () {
    int next_day=day+1;
    int next_month=month;
    int next_year=year;
    if (month==2 && day==28) {
        if (IsLeap()) {
            next_day=29;
            next_month=month;
            next_year=year;
        } else {
            next_day=1;
            next_month=month+1;
            next_year=year;
        }
    }
    else if (month==2 && day==29) {
        next_day=1;
        next_month=month+1;
        next_year=year;
    }
    else if (((month==1 || month==3 || month==5 || month==7 || month==8 || month==10) && day==31) || ((month==4 || month==6 || month==9 || month==11) && day==30)) {
        next_day=1;
        next_month=month+1;
        next_year=year;
    } else if (month==12 && day==31) {
        next_day=1;
        next_month=1;
        next_year=year+1;
    }
    return Date(next_day, next_month, next_year);
}
Date Date::PreviousDay() {
    int previous_day=day-1;
    int previous_month=month;
    int previous_year=year;
    if (month==3 && day==1) {
        if (IsLeap()) {
            previous_day=29;
            previous_month=month-1;
            previous_year=year;
        } else {
            previous_day=28;
            previous_month=month-1;
            previous_year=year;
        }
    }
    else if ((month==2 || month==4 || month==6 || month==9 || month==11) && day==1) {
        previous_day=31;
        previous_month=month-1;
        previous_year=year;
    } else if ((month==5 || month==7 || month==8 || month==10 || month==12) && day==1) {
        previous_day=30;
        previous_month=month-1;
        previous_year=year;
    } else if (month==1 && day==1) {
        previous_day=31;
        previous_month=12;
        previous_year=year-1;
    }
    return Date(previous_day, previous_month, previous_year);
}

int Date::GetNumberDaysInMonth(int i) {
    if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) {
        return 31;
    } else if (i==4 || i==6 || i==9 || i==11) {
        return 30;
    } else if (i==2) {
        if(IsLeap()) {
            return 29;
        } else {
            return 28;
        }
    }
}

int Date::GetNumberDaysFromBegin() {
    int years_day = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    int month_day=0;
    for (int i=1;i<month;i++) {
        month_day+=GetNumberDaysInMonth(i);
    }
    return years_day+month_day+day;
}

short Date::WeekNumber () {
    int sum_day=0;
    for (int i=1;i<month;i++) {
        sum_day += GetNumberDaysInMonth(i);
    }
    return my_ceil((sum_day/7));
}

int Date::GetDay() {
    return day;
}
int Date::GetMonth() {
    return month;
}
int Date::GetYear() {
    return year;
}
int Date::GetN() {
    return n;
}
void Date::SetN(int _n) {
    n = _n;
}
