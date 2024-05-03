#define MAX_COUNT_OF_YEARS 9999u
#define MAX_COUNT_OF_MONTH 12u
#define MONTH_COUNT_31 31u
#define MONTH_COUNT_30 30u
#define MONTH_COUNT_29 29u
#define MONTH_COUNT_28 28u

#define LEAP_T _isLeap = true
#define LEAP_F _isLeap = false

#include "../../Headers/Date.h"

#define DEBUG

/*Date::Date(QString date) {
    uint day = 0;
    uint month = 0;
    uint year = 0;
    int i = 0;
    for (; date[i] != '.'; i++) {
        day *= 10;
        day += date[i].digitValue();
    }
    for (; date[i] != '.'; i++) {
        month *= 10;
        month += date[i].digitValue();
    }
    for (; date[i] != '\0'; i++) {
        year *= 10;
        year += date[i].digitValue();
    }
    Date(day, month, year);
}*/

Date::Date(uint day, uint month, uint year) {
    if (year && year <= MAX_COUNT_OF_YEARS) { this->_year = year; }
    else {
        _year = 0;
        return;
    }
    checkLeap();

    if (month && month <= MAX_COUNT_OF_MONTH) { this->_month = month; }
    else {
        _year = 0;
        return;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day && day <= MONTH_COUNT_31) { this->_day = day; }
        else {
            _year = 0;
            return;
        }
    } else {
        if (month == 2) {
            if (_isLeap) {
                if (day && day <= MONTH_COUNT_29) { this->_day = day; }
                else {
                    _year = 0;
                    return;
                }
            } else {
                if (day && day <= MONTH_COUNT_28) { this->_day = day; }
                else {
                    _year = 0;
                    return;
                }
            }
        } else {
            if (day && day <= MONTH_COUNT_30) { this->_day = day; }
            else {
                _year = 0;
                return;
            }
        }
    }
}

Date::Date() {
    time_t thisTime = time(nullptr);
    this->_year = localtime(&thisTime)->tm_year + 1900;
    this->_month = localtime(&thisTime)->tm_mon + 1;
    this->_day = localtime(&thisTime)->tm_mday;
    checkLeap();
}

void Date::checkLeap() {
    _year % 4
    ? LEAP_F
    : _year % 100
      ? LEAP_T
      : _year % 400
        ? LEAP_F
        : LEAP_T;
}

uint Date::day() {
    return this->_day;
}

uint Date::month() {
    return this->_month;
}

uint Date::year() {
    return this->_year;
}

bool Date::isLeap() {
    return this->_isLeap;
}

Date Date::nextDay() {
    Date temp = Date(this->day(), this->month(), this->year());
    if (temp.day() == MONTH_COUNT_31 && temp.month() == MAX_COUNT_OF_MONTH) {
        temp._day = 1;
        temp._month = 1;
        temp._year++;
    } else if (temp.month() == 2) {
        if (temp.isLeap()) {
            if (temp.day() == MONTH_COUNT_29) {
                temp._day = 1;
                temp._month++;
            } else { temp._day++; }
        } else {
            if (temp.day() == MONTH_COUNT_28) {
                temp._day = 1;
                temp._month++;
            } else { temp._day++; }
        }
    } else if (temp._month == 1 || temp._month == 3 || temp._month == 5 || temp._month == 7 || temp._month == 8 ||
               temp._month == 10) {
        if (temp.day() == MONTH_COUNT_31) {
            temp._day = 1;
            temp._month++;
        } else { temp._day++; }
    } else {
        if (temp.day() == MONTH_COUNT_30) {
            temp._day = 1;
            temp._month++;
        } else { temp._day++; }

    }
    temp.checkLeap();
    return temp;
}

Date Date::previousDay() {
    Date temp = Date(this->day(), this->month(), this->year());
    if (temp.day() != 1) {
        temp._day--;
    } else {
        if (temp.month() == 3) {
            if (temp.isLeap()) {
                temp._day = MONTH_COUNT_29;
                temp._month--;
            } else { temp._day = MONTH_COUNT_28; }
        } else if (temp.month() == 1) {
            temp._day = MONTH_COUNT_31;
            temp._month = MAX_COUNT_OF_MONTH;
            temp._year--;
        } else if (temp.month() == 4 || temp.month() == 6 || temp.month() == 8 || temp.month() == 9 ||
                   temp.month() == 11 || temp.month() == 2) {
            temp._day = MONTH_COUNT_31;
            temp._month--;
        }
    }
    temp.checkLeap();
    return temp;
}

int Date::difference(Date compareDate) const {
    int dayCount = 0;
    while (compareDate._year != this->_year) {
        if (this->_year > compareDate._year) {
            dayCount += 365;
            if (compareDate.month() > 2) { compareDate._year++; }
            compareDate.checkLeap();
            if (compareDate.isLeap()) { dayCount++; }
            if (compareDate.month() <= 2) { compareDate._year++; }
        } else {
            dayCount -= 365;
            if (compareDate.month() <= 2) { compareDate._year--; }
            compareDate.checkLeap();
            if (compareDate.isLeap()) { dayCount--; }
            if (compareDate.month() > 2) { compareDate._year--; }
        }
    }
    compareDate.checkLeap();

    while (this->_month != compareDate._month) {
        if (this->_month > compareDate._month) {
            if (compareDate._month == 2) {
                if (compareDate.isLeap()) {
                    dayCount += MONTH_COUNT_29;
                } else {
                    dayCount += MONTH_COUNT_28;
                }
            } else if (compareDate._month == 1 || compareDate._month == 3 || compareDate._month == 5 ||
                       compareDate._month == 7 || compareDate._month == 8 ||
                       compareDate._month == 10) {
                dayCount += MONTH_COUNT_31;
            } else {
                dayCount += MONTH_COUNT_30;
            }
            compareDate._month++;
        } else if (this->_month < compareDate._month) {
            if (compareDate._month == 3) {
                if (compareDate.isLeap()) {
                    dayCount -= MONTH_COUNT_29;
                } else {
                    dayCount -= MONTH_COUNT_28;
                }
            } else if (compareDate._month == 2 || compareDate._month == 4 || compareDate._month == 6 ||
                       compareDate._month == 9 || compareDate._month == 8 ||
                       compareDate._month == 11) {
                dayCount -= MONTH_COUNT_31;
            } else {
                dayCount -= MONTH_COUNT_30;
            }
            compareDate._month--;
        }
    }

    while (this->_day != compareDate._day) {
        if (this->_day > compareDate._day) {
            compareDate._day++;
            dayCount++;
        } else {
            compareDate._day--;
            dayCount--;
        }
    }

    return dayCount;
}

uint Date::dayOfWeek() const {
    int temp = qAbs((this->difference(Date(1, 1, 1))) + 1) % 7;
    //qDebug() <<  temp;
    if (temp == 0) { temp = 7; }
    //qDebug() <<  temp;
    return temp;
}

uint Date::numberOfWeek() const {
    Date firstOfYear(1, 1, this->_year);
    Date firstDate(1, 1, 1);
    uint weekNumber = 0;
    if (firstOfYear.dayOfWeek() <= 4) {
        weekNumber++;
    }
    weekNumber += (this->difference(firstDate) - firstOfYear.difference(firstDate) + firstOfYear.dayOfWeek() - 1) / 7;
    if (weekNumber == 0) {
        Date *LastDayInPreviousYear = new Date(31, 12, this->_year - 1);
        weekNumber = LastDayInPreviousYear->numberOfWeek();
    }
    return weekNumber;
}

void Date::isBirthDay() {
    this->_day = 0;
    this->_month = 0;
    this->_year = 0;
}

/*
Date &Date::operator=(Date &date) {
    Date temp = Date(date.day(), date.month(), date.year());
    return temp;
}
*/

Date Date::nextBirthDay() {
    Date temp = *this;
    while (temp.year() < Date().year()) {
        bool check = Date(1, 1, temp.year() + 4).isLeap();
        if (temp.day() == 29 && temp.isLeap() && temp.month() == 2 && !check) {
            temp = temp.day() == 29 && temp.isLeap() && temp.month() == 2
                   ? Date(temp.day(), temp.month(), temp.year() + 8)
                   : Date(temp.day(), temp.month(), temp.year() + 1);
        } else {
            temp = temp.day() == 29 && temp.isLeap() && temp.month() == 2
                   ? Date(temp.day(), temp.month(), temp.year() + 4)
                   : Date(temp.day(), temp.month(), temp.year() + 1);
        }
    }
    if (temp.month() < Date().month() || temp.day() < Date().day()) {
        bool check = Date(1, 1, temp.year() + 4).isLeap();
        if (temp.day() == 29 && temp.isLeap() && temp.month() == 2 && !check) {
            temp = temp.day() == 29 && temp.isLeap() && temp.month() == 2
                   ? Date(temp.day(), temp.month(), temp.year() + 8)
                   : Date(temp.day(), temp.month(), temp.year() + 1);
        } else {
            temp = temp.day() == 29 && temp.isLeap() && temp.month() == 2
                   ? Date(temp.day(), temp.month(), temp.year() + 4)
                   : Date(temp.day(), temp.month(), temp.year() + 1);
        }
    }
    return temp;
}

Date Date::previousBirthDay() {
    qDebug() << "io";
    Date temp = this->nextBirthDay();
    qDebug() << "ir";
    bool check = Date(1, 1, temp.year() - 4).isLeap();
    qDebug() << "ls";
    if (temp.day() == 29 && temp.isLeap() && temp.month() == 2 && !check) {
        temp = this->day() == 29 && temp.isLeap() && temp.month() == 2
               ? Date(temp.day(), temp.month(), temp.year() - 8)
               : Date(temp.day(), temp.month(), temp.year() - 1);
    } else {
        temp = this->day() == 29 && temp.isLeap() && temp.month() == 2
               ? Date(temp.day(), temp.month(), temp.year() - 4)
               : Date(temp.day(), temp.month(), temp.year() - 1);
    }

    qDebug() << "pel";
    return temp;
}
