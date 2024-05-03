#include "date.h"

QString workWithDate::  getPrevDate(int a) {
    return fromDateToString(datesList[a].addDays(-1));
}

QString workWithDate::getNextDate(int a) {
    return fromDateToString(datesList[a].addDays(1));
}

bool workWithDate::getIsYearLeap(int a) {
    return QDate::isLeapYear(datesList[a].year());
}

long long workWithDate::cntDaysToBD(QDate bdDate, int a) {
    QDate date = datesList[a];
    int year = date.year();
    if (bdDate.day() == 29 && bdDate.month() == 12)
        while (!QDate::isLeapYear(year)) year++;
    bdDate.setDate(year, bdDate.month(), bdDate.day());
    long long res = date.daysTo(bdDate);
    if (res < 0) {
        if (bdDate.day() == 29 && bdDate.month() == 12) {
            do {
                bdDate = bdDate.addYears(1);
            } while (!QDate::isLeapYear(bdDate.year()));
        } else {
            bdDate = bdDate.addYears(1);
        }
    }
    res = date.daysTo(bdDate);
    return res;
}

QString workWithDate::fromDateToString(QDate date) {
    if (date.year() < 0) {
        date.setDate(date.year() * -1, date.month(), date.day());
        return date.toString("dd.MM.yyyy BC");
    }
    return date.toString("dd.MM.yyyy");
}

long long workWithDate::getDefWithPrev(int a) {
    return a ? qAbs(datesList[a].daysTo(datesList[a - 1])) : 0;
}

long long workWithDate::getWeekNumber(int a) {
    return datesList[a].weekNumber();
}

int workWithDate::changeDate(QDate wasDate, QDate newDate) {
    int ret = -1;
    for(int i = 0; i < datesList.size(); i++) {
        if(datesList[i] == wasDate) datesList[i] = newDate;
        if(ret == -1) ret = i;
    }
    return ret;
}


