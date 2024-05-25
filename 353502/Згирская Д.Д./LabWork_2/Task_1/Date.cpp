//
// Created by zgdarya on 4/10/24.
//

#include "Date.h"

Date::Date(uint day, uint month, uint year) {
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

void Date::setDay(uint day) {
    _day = day;
}

void Date::setMonth(uint month) {
    _month = month;
}

void Date::setYear(uint year) {
    _year = year;
}

Date Date::NextDay() {
    uint newDay = _day + 1;
    uint newMonth = _month;
    uint newYear = _year;
    if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
        if (newDay == 32) {
            newDay = 1;
            newMonth += 1;
        }
    }
    else if (_month == 2) {
        if (isLeap() == 0 && newDay == 29) {
            newDay = 1;
            newMonth += 1;
            qDebug() << newDay << " " << newMonth;
        }
        else if (isLeap() == 1 && newDay == 30) {
            newDay = 1;
            newMonth += 1;
        }
    }
    else if (newDay == 31) {
        if (_month == 1) qDebug() << newDay;
        newDay = 1;
        if (_month == 1) qDebug() << newDay;
        newMonth += 1;
    }
    if (newMonth == 13) {
        newMonth = 1;
        newYear += 1;
    }
    return Date(newDay, newMonth, newYear);
}

Date Date::PreviousDay() {
    uint newDay = _day - 1;
    uint newMonth = _month;
    uint newYear = _year;
    if (newDay == 0) {
        newMonth -= 1;
        if (newMonth == 0) {
            newYear -= 1;
            newMonth = 12;
        }
        else if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10) {
            newDay = 31;
        }
        else if (newMonth == 2) {
            if (isLeap() == 0) {
                newDay = 28;
            }
            else if (isLeap() == 1) {
                newDay = 29;
            }
        }
        else {
            newDay = 30;
        }
    }
    return Date(newDay, newMonth, newYear);
}

bool Date::isLeap() {
    return _isLeap;
}

short Date::WeekNumber() {
    Date firstDayOfThisYear(1, 1, _year);
    int weekNumber = 0;
    if (firstDayOfThisYear.dayInWeek() <= 3) {
        weekNumber++;
    }
    weekNumber += (Duration(Date(1, 1, 1)) - firstDayOfThisYear.Duration(Date(1, 1, 1)) + firstDayOfThisYear.dayInWeek() - 1) / 7;
    if (weekNumber == 0) {
        Date *lastDayInPreviousYear = new Date(31, 12, _year - 1);
        weekNumber = lastDayInPreviousYear->WeekNumber();
    }
    return weekNumber;
}

uint Date::getDay() {
    return _day;
}

uint Date::getMonth() {
    return _month;
}

uint Date::getYear() {
    return _year;
}

uint Date::dayInWeek() {
    return qAbs(Duration(Date(1, 1, 1))) % 7;
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

    return qAbs(dayCount);
}

int Date::DaysTillYourBirthday(Date birthday) {
    return Duration(birthday);
}

void Date::checkLeap() {
    _isLeap = _year % 4 ? 0 :
              _year % 100 ? 1 :
              _year % 400 ? 0 : 1;
}
