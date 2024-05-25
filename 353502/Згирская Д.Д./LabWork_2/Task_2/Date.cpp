//
// Created by zgdarya on 4/20/24.
//

#include "Date.h"

Date::Date(int day, int month, int year) {
    if (day >= 1) {
        if (year >= 1 && year <= 9999) _year = year;
        else {
            _year = 0;
            return;
        }
        checkLeap();
        if (month >= 1 && month <= 12) _month = month;
        else {
            _year = 0;
            return;
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day <= 31) _day = day;
            else {
                _year = 0;
                return;
            }
        }
        else if (month == 2) {
            if (isLeap() == 0 && day <= 28) {
                _day = day;
            }
            else if (isLeap() == 1 && day <= 29) _day = day;
            else {
                _year = 0;
                return;
            }
        }
        else if (day <= 30) _day = day;
        else {
            _year = 0;
            return;
        }
    }
    else _year = 0;
}

Date::Date() {
    time_t currentTime = time(nullptr);
    _day = localtime(&currentTime)->tm_mday;
    _month = localtime(&currentTime)->tm_mon + 1;
    _year = localtime(&currentTime)->tm_year + 1900;
}

void Date::setDay(int day) {
    _day = day;
}

void Date::setMonth(int month) {
    _month = month;
}

void Date::setYear(int year) {
    _year = year;
}

bool Date::isLeap() {
    return _isLeap;
}

int Date::getDay() {
    return _day;
}

int Date::getMonth() {
    return _month;
}

int Date::getYear() {
    return _year;
}

int Date::Duration(Date date) {
    int dayCount = 0;
    while (date._year != _year) {
        if (_year > date._year) {
            dayCount += 365;
            if (date.getMonth() > 2) { date._year++; }
            date.checkLeap();
            if (date.isLeap()) { dayCount++; }
            if (date.getMonth() <= 2) { date._year++; }
        } else {
            dayCount -= 365;
            if (date.getMonth() <= 2) { date._year--; }
            date.checkLeap();
            if (date.isLeap()) { dayCount--; }
            if (date.getMonth() > 2) { date._year--; }
        }
    }
    date.checkLeap();

    while (this->_month != date._month) {
        if (this->_month > date._month) {
            if (date._month == 2) {
                if (date.isLeap()) {
                    dayCount += 29;
                } else {
                    dayCount += 28;
                }
            } else if (date._month == 1 || date._month == 3 || date._month == 5 ||
                       date._month == 7 || date._month == 8 ||
                       date._month == 10) {
                dayCount += 31;
            } else {
                dayCount += 30;
            }
            date._month++;
        } else if (this->_month < date._month) {
            if (date._month == 3) {
                if (date.isLeap()) {
                    dayCount -= 29;
                } else {
                    dayCount -= 28;
                }
            } else if (date._month == 2 || date._month == 4 || date._month == 6 ||
                       date._month == 9 || date._month == 8 ||
                       date._month == 11) {
                dayCount -= 31;
            } else {
                dayCount -= 30;
            }
            date._month--;
        }
    }

    while (this->_day != date._day) {
        if (this->_day > date._day) {
            date._day++;
            dayCount++;
        } else {
            date._day--;
            dayCount--;
        }
    }

    return dayCount;
}

void Date::checkLeap() {
    _isLeap = _year % 4 ? 0 :
              _year % 100 ? 1 :
              _year % 400 ? 0 : 1;
}

