#include "date.h"

extern QMap <int, int> monthMap;

Date::Date(QString dateTransfer, bool leapYear, int dayTransfer, int monthTransfer, int yearTransfer) : QString() {
    dateUsed = dateTransfer;
    IsLeap = leapYear;
    day = dayTransfer;
    month = monthTransfer;
    year = yearTransfer;
}

QString Date::DateOutput() {
    return dateUsed;
}

QString Date::NextDate() {
    int TDay = day;
    int TMonth = month;
    int TYear = year;
    QString DateNextDay = "";

    if (month == 12 && day == 31) {
        TMonth = 1;
        TYear++;
        TDay = 1;
    }
    else if (month == 2 && monthMap[month] + int(IsLeap) == day) {
        TMonth++;
        TDay = 1;
    }
    else if (monthMap[month] == day) {
        TMonth++;
        TDay = 1;
    }
    else {
        TDay++;
    }

    if (TDay < 10) {
        DateNextDay += '0' + QString::number(TDay);
    }
    else {
        DateNextDay += QString::number(TDay);
    }

    DateNextDay += '.';

    if (TMonth < 10) {
        DateNextDay += '0' + QString::number(TMonth);
    }
    else {
        DateNextDay += QString::number(TMonth);
    }

    DateNextDay += '.';

    if (TYear < 10) {
        DateNextDay += "000" + QString::number(TYear);
    }
    else if (TYear < 100) {
        DateNextDay += "00" + QString::number(TYear);
    }
    else if (TYear < 1000) {
        DateNextDay += "0" + QString::number(TYear);
    }
    else {
        DateNextDay += QString::number(TYear);
    }

    return DateNextDay;
}

QString Date::PreviousDate() {
    int TDay = day;
    int TMonth = month;
    int TYear = year;
    QString DatePreviousDay = "";

    if (month == 1 && day == 1) {
        TMonth = 12;
        TYear--;
        TDay = 31;
    }
    else if (day == 1 && month == 3) {
        TMonth--;
        TDay = monthMap[month - 1] + int(IsLeap);
    }
    else if (day == 1) {
        TMonth--;
        TDay = monthMap[month - 1];
    }
    else {
        TDay--;
    }

    if (TDay < 10) {
        DatePreviousDay += '0' + QString::number(TDay);
    }
    else {
        DatePreviousDay += QString::number(TDay);
    }

    DatePreviousDay += '.';

    if (TMonth < 10) {
        DatePreviousDay += '0' + QString::number(TMonth);
    }
    else {
        DatePreviousDay += QString::number(TMonth);
    }

    DatePreviousDay += '.';

    if (TYear < 10) {
        DatePreviousDay += "000" + QString::number(TYear);
    }
    else if (TYear < 100) {
        DatePreviousDay += "00" + QString::number(TYear);
    }
    else if (TYear < 1000) {
        DatePreviousDay += "0" + QString::number(TYear);
    }
    else {
        DatePreviousDay += QString::number(TYear);
    }

    return DatePreviousDay;
}

int Date::TransferDateToDay() {
    int resultTransfing = 0;
    int leapYear = (year) % 4 - (year) % 100 + (year) % 400;
    resultTransfing += (year - leapYear) * 365 + leapYear * 366;
    for (int i = 1; i <= month - 1; ++i) {
        resultTransfing += monthMap[i];
        if (i == 2) {
            resultTransfing += int(IsLeap);
        }
    }
    resultTransfing += day;
    return resultTransfing;
}

int Date::DaysTillYourBirthday(Date birthdaydate) {
    int result = 0;
    int daysBirthday = 0;
    int daysToday = 0;

    for (int i = 1; i < month; ++i) {
        daysToday += monthMap[i];
    }
    daysToday += day;
    for (int i = 1; i < birthdaydate.month; ++i) {
        daysBirthday += monthMap[i];
    }
    daysBirthday += birthdaydate.day;
    if (daysBirthday - daysToday < 0) {
        return daysBirthday - daysToday + 365;
    }
    else {
        return daysBirthday - daysToday;
    }
}

int Date::Duration(Date dateSecond) {
    return abs(TransferDateToDay() - dateSecond.TransferDateToDay());
}

bool Date::IsLeapYear() {
    return IsLeap;
}

int Date::WeekNumber() {

    int dayQuanity = 0;
    for (int i = 1; i < month; ++i) {
        dayQuanity += monthMap[i];
        if (month == 2) {
            dayQuanity += int(IsLeap);
        }
    }
    dayQuanity += day;

    return dayQuanity / 7;
}

