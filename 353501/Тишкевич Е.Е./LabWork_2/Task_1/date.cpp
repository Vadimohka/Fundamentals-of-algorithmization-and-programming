#include "date.h"


QString Date::nextDate(int a) {
    return fromDateToString(datesList[a].addDays(1));
}

bool Date::isLeap(int a) {
    return QDate::isLeapYear(datesList[a].year());
}

QString Date::prevDate(int a) {
    return fromDateToString(datesList[a].addDays(-1));
}

QString Date::fromDateToString(QDate date) {
    if (date.year() < 0) {
        date.setDate(date.year() * -1, date.month(), date.day());
        return date.toString("dd.MM.yyyy BC");
    }
    return date.toString("dd.MM.yyyy");
}

long long Date::getDefWithPrev(int a) {
    return a ? qAbs(datesList[a].daysTo(datesList[a - 1])) : 0;
}

long long Date::getDiff(int a, QDate bdDate) {
    return qAbs(datesList[a].daysTo(bdDate));
}




long long Date::getWeekNumber(int a) {
    return datesList[a].weekNumber();
}

int Date::changeDate(QDate wasDate, QDate newDate) {
    int ret = -1;
    for(int i = 0; i < datesList.size(); i++) {
        if(datesList[i] == wasDate) datesList[i] = newDate;
        if(ret == -1) ret = i;
    }
    return ret;
}
