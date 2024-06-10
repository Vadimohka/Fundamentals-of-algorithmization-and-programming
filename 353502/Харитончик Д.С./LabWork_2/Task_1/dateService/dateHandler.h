#pragma once

#include <QtWidgets>

class Date
{
    QVector<QDate> dateSet;

public:
    Date() = default;

    void addDate(QDate date)
    {
        dateSet.push_back(date);
    }

    QString getDate(int a)
    {
        if (a < dateSet.size() && a >= 0) return fromDateToString(dateSet[a]);
    }

    QString previousDay(int a);
    QString nextDate(int a);
    bool isLeapYear(int a);
    static long long dayUntilYourBirthday(QDate birthdayDate, int a);
    long long getWeekNumber(int a);
    long long getDefWithPrev(int a);
    int changeDate(QDate wasDate, QDate newDate);
    static QString fromDateToString(QDate date);
};
