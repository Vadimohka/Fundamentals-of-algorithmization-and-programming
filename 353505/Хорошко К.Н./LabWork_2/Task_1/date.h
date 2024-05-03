#ifndef DATE_H
#define DATE_H

#include <QDate>

class Date
{
public:
    Date();

    void setDay(int d);

    void setMonth(int m);

    void setYear(int y);

    Date NextDay();

    Date PreviousDay();

    bool ISLeap();

    short WeekNumber();

    int DaysTillYourBithday(Date bithDayDate);

    int Duration(Date date);

    int day;
    int month;
    int year;
};

#endif // DATE_H
