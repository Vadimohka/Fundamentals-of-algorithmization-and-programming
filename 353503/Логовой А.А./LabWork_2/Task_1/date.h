#ifndef DATE_H
#define DATE_H

#include <QString>
#include <magicNumbers.h>

class Date{

public:

    Date(short day = 0 , short month = 0, short year = 0);

    ~Date();

    void setDay(short day);

    void setMonth(short month);

    void setYear(short year);

    bool isLeap(int year) const;

    bool isLeap() const;

    short getDay() const;

    short getMonth() const;

    short getYear() const;

    short dayOnMonth(short month);

    short WeekNumber();

    short dayOfWeek();

    int DaysTillYourBithday(Date bithdaydate);

    int Duration (Date date);

    Date NextDay();

    Date PreviousDay() const;

    QString dayOfWeeks();

    QString dateToString();

private:

    short day;
    short month;
    short year;
};

#endif // DATE_H
