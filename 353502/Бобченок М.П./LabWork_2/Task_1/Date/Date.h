//
// Created by u on 02.04.24.
//

#ifndef LAB2_DATE_H
#define LAB2_DATE_H

#include <ctime>
#include "../Date/date.h"

class Date
{
private:
    const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int secsInMinute = 60;
    const int minutesInHour = 60;
    const int hoursInDay = 24;
    const int daysInYear = 365;

    date curDate;

    date secToDate(long long sec);
    long long dateToSec(date dt);

public:
    static bool isLeap(date dt);
    date getDate() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDate(int day, int month, int year);

    date nextDay();
    date previousDay();
    int weekNumber(date dt);
    int duration(int day, int month, int year);
    int daysTilYourBirthday(int day, int month);

    Date(int day, int month, int year);
    Date();
};


#endif //LAB2_DATE_H
