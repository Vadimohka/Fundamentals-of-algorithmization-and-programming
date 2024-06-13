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
    bool IsLeep(int year_);
    short WeekNumber();
    int DaysTillYourBithday(Date bithdaydate);
    int Duration (Date date);
    QString print();
    int day_;
    int month_;
    int year_;
    int maxDay(int month_);
};

#endif // DATE_H
