#include "date.h"

Date::Date(int _day, int _month, int _year)
    : day(_day)
    , month(_month)
    , year(_year)
{
    init(IsLeap());
}

Date::Date() = default;

void Date::setDate(int _day, int _month, int _year)
{
    day = _day;
    month = _month;
    year = _year;
    init(IsLeap());
}

void Date::setDate(Date date)
{
    day = date.getDay();
    month = date.getMonth();
    year = date.getYear();
    init(IsLeap());
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

QString Date::getStrDate()
{
    QString res = "";
    if (day / TWO_DIGIT_NUM == 0) {
        res.append('0' + QString::number(day));
    } else {
        res.append(QString::number(day));
    }

    res.append('.');

    if (month / TWO_DIGIT_NUM == 0) {
        res.append('0' + QString::number(month));
    } else {
        res.append(QString::number(month));
    }

    res.append('.');

    if (year / TWO_DIGIT_NUM == 0) {
        res.append("000" + QString::number(year));
    } else if (year / THREE_DIGIT_NUM == 0) {
        res.append("00" + QString::number(year));
    } else if (year / FOUR_DIGIT_NUM == 0) {
        res.append("0" + QString::number(year));
    } else {
        res.append(QString::number(year));
    }
    return res;
}

void Date::init(bool isLeap)
{
    calendar = new int[DEC];
    calendar[JAN - 1] = DAYS31;
    if (isLeap) {
        calendar[FEB - 1] = FEB_DAYS_LEAP;
        calendarYear = YEAR_LEAP;
    } else {
        calendar[FEB - 1] = FEB_DAYS;
        calendarYear = YEAR;
    }

    calendar[MAR - 1] = DAYS31;
    calendar[APR - 1] = DAYS30;
    calendar[MAY - 1] = DAYS31;
    calendar[JUN - 1] = DAYS30;
    calendar[JUL - 1] = DAYS31;
    calendar[AUG - 1] = DAYS31;
    calendar[SEP - 1] = DAYS30;
    calendar[OCT - 1] = DAYS31;
    calendar[NOV - 1] = DAYS30;
    calendar[DEC - 1] = DAYS31;
}

Date Date::NextDay()
{
    Date nextDay;
    if (day == calendar[month - 1]) {
        if (month == DEC) {
            nextDay.setDate(1, 1, year + 1);
        } else {
            nextDay.setDate(1, month + 1, year);
        }
    } else {
        nextDay.setDate(day + 1, month, year);
    }
    return nextDay;
}

Date Date::PreviousDay()
{
    Date prev;
    if (day == 1) {
        if (month == JAN) {
            prev.setDate(calendar[DEC - 1], DEC, year - 1);
        } else {
            prev.setDate(calendar[month - 2], month - 1, year);
        }
    } else {
        prev.setDate(day - 1, month, year);
    }
    return prev;
}

bool Date::IsLeap()
{
    if (!(year % LEAP_CONST1)) {
        return true;
    } else if (!(year % NONE_LEAP_CONST)) {
        return false;
    } else if (!(year % LEAP_CONST2)) {
        return true;
    } else {
        return false;
    }
}

short Date::WeekNumber()
{
    int week = 0;
    int *monthCode = new int[DEC];
    if (IsLeap()) {
        monthCode[JAN - 1] = 0;
        monthCode[FEB - 1] = 3;
    } else {
        monthCode[JAN - 1] = 1;
        monthCode[FEB - 1] = 4;
    }
    monthCode[MAR - 1] = CODE4;
    monthCode[APR - 1] = CODE0;
    monthCode[MAY - 1] = CODE2;
    monthCode[JUN - 1] = CODE5;
    monthCode[JUL - 1] = CODE0;
    monthCode[AUG - 1] = CODE3;
    monthCode[SEP - 1] = CODE6;
    monthCode[OCT - 1] = CODE1;
    monthCode[NOV - 1] = CODE4;
    monthCode[DEC - 1] = CODE6;

    int yearCode = 0;
    if (!(year / THREE_DIGIT_NUM % 4)) {
        yearCode = (CODE6 + year % THREE_DIGIT_NUM + (year % THREE_DIGIT_NUM) / 4) % WEEK;
    } else if (year % 4 == 1) {
        yearCode = (CODE4 + year % THREE_DIGIT_NUM + (year % THREE_DIGIT_NUM) / 4) % WEEK;
    } else if (year % 4 == 2) {
        yearCode = (CODE2 + year % THREE_DIGIT_NUM + (year % THREE_DIGIT_NUM) / 4) % WEEK;
    } else if (year % 4 == 3) {
        yearCode = (CODE0 + year % THREE_DIGIT_NUM + (year % THREE_DIGIT_NUM) / 4) % WEEK;
    }

    int firstJan = day + monthCode[month - 1] + yearCode;
    firstJan = (firstJan + CODE5) % WEEK;

    int days = day;
    for (int i = 0; i < month - 1; i++) {
        days += calendar[i];
    }

    week = (days + firstJan) / WEEK;
    week += (days + firstJan) % WEEK != 0 ? 1 : 0;
    delete[] monthCode;
    return week;
}

int Date::DaysTillYourBirthday(Date birthdaydate)
{
    int days = 0;
    int daysNow = 0, daysBirth = 0;
    daysNow = day;
    for (int i = 0; i < month - 1; i++) {
        daysNow += calendar[i];
    }
    daysBirth = birthdaydate.day;
    for (int i = 0; i < birthdaydate.month - 1; i++) {
        daysBirth += calendar[i];
    }
    if (daysBirth >= daysNow) {
        days = daysBirth - daysNow;
    } else {
        Date nextYear(birthdaydate.day, birthdaydate.month, year + 1);
        days = calendarYear - daysNow;
        for (int i = 0; i < birthdaydate.month - 1; i++) {
            days += nextYear.calendar[i];
        }
        days += birthdaydate.day;
        delete[] nextYear.calendar;
    }
    return days;
}

int Date::Duration(Date date)
{
    qint64 days = 0;
    Date lateYear, pastYear;
    if (year != date.year) {
        if (date.year > year) {
            pastYear.setDate(day, month, year);
            lateYear.setDate(date);
        } else {
            lateYear.setDate(day, month, year);
            pastYear.setDate(date);
        }
        Date temp;
        for (int i = pastYear.year + 1; i < lateYear.year; i++) {
            temp.year = i;
            if (temp.IsLeap()) {
                days += YEAR_LEAP;
            } else {
                days += YEAR;
            }
        }
        for (int i = 0; i < lateYear.month - 1; i++) {
            days += lateYear.calendar[i];
        }
        days += lateYear.day;
        for (int i = pastYear.month; i < DEC; i++) {
            days += pastYear.calendar[i];
        }
        days += pastYear.calendar[pastYear.month - 1] - pastYear.day;

        delete[] pastYear.calendar;
        delete[] lateYear.calendar;
    } else {
        int days1 = 0, days2 = 0;
        for (int i = 0; i < month - 1; i++) {
            days1 += calendar[i];
        }
        for (int i = 0; i < date.month - 1; i++) {
            days2 += date.calendar[i];
        }
        days1 += day;
        days2 += date.day;
        days = qAbs(days1 - days2);
    }

    return days;
}
