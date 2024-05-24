#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
public:
    Date();
    Date(QString s);
    Date(int day, int month, int year);
    Date NextDay();
    Date PreviusDay();
    bool IsLeep();
    bool IsLeep(int yearq);
    short WeekNumber();
    int DaysTillYourBithday(Date bithdaydate);
    int Duration (Date date);
    QString print();
    int dayq;
    int monthq;
    int yearq;
    int maxDay(int monthq);
};

#endif // DATE_H
