#include "date.h"

std::string Date::to_str() {
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}

bool Date::IsLeap() {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::GetNumberDaysInMonth(int i) {
    switch(i) {
    case 2: return IsLeap() ? 29 : 28;
    case 4: case 6: case 9: case 11: return 30;
    default: return 31;
    }
}

bool Date::IsCorrectInput() {
    if (day < 1 || day > GetNumberDaysInMonth(month) || month < 1 || month > 12 || year < 1) {
        return false;
    }
    return true;
}

Date Date::NextDay () {
    int next_day = day + 1;
    int next_month = month;
    int next_year = year;

    if (next_day > GetNumberDaysInMonth(month)) {
        next_day = 1;
        next_month++;
    }

    if (next_month > 12) {
        next_month = 1;
        next_year++;
    }

    return Date(next_day, next_month, next_year);
}

Date Date::PreviousDay() {
    int previous_day = day - 1;
    int previous_month = month;
    int previous_year = year;

    if (previous_day < 1) {
        previous_month--;
        if (previous_month < 1) {
            previous_month = 12;
            previous_year--;
        }
        previous_day = GetNumberDaysInMonth(previous_month);
    }

    return Date(previous_day, previous_month, previous_year);
}

int Date::GetNumberDaysFromBegin() {
    int years_day = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    int month_day = 0;
    for (int i = 1; i < month; i++) {
        month_day += GetNumberDaysInMonth(i);
    }
    return years_day + month_day + day;
}

short Date::WeekNumber () {
    int sum_day = 0;
    for (int i = 1; i < month; i++) {
        sum_day += GetNumberDaysInMonth(i);
    }
    return my_ceil((sum_day / 7.0));
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
