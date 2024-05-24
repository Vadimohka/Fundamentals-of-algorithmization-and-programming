#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QtMath>
#include "constants.h"

class Date
{
public:
    Date(int, int, int);
    Date();
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date);
    int Duration (Date);
    void init(bool);
    void setDate(int, int, int);
    void setDate(Date);
    int getMonth();
    int getDay();
    int getYear();
    QString getStrDate();

private:
    int day;
    int month;
    int year;
    int* calendar;
    int calendarYear;
};

#endif // DATE_H
