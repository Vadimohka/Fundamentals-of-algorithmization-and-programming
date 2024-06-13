#ifndef DATE_H
#define DATE_H

#include <math.h>
#include <QDate>
#include <QDebug>
#include <QString>

class Date
{
public:
    int day = 0;
    int month = 0;
    int year = 0;
    int duration(Date date1, Date date2);

public:
    Date(int day, int month, int year);
    ~Date() = default;

    int getDay() const;
    void setDay(int newDay);
    int getMonth() const;
    void setMonth(int newMonth);
    int getYear() const;
    void setYear(int newYear);

    Date NextDay();
    bool IsLeap();
    bool IsLeap(int year);
    Date PreviousDay();
    short WeekNumber();
    short theFirstDay();
    int Duration(Date date);
    int DaysTillYourBirthday(Date birthdayDate);
    QString DateInStringFormat();

};

#endif // DATE_H
