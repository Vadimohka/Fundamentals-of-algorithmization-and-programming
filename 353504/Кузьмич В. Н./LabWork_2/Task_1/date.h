#ifndef DATE_H
#define DATE_H
#include <QDate>
#include <QString>

class Date
{
private:
    int list_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
public:
    int day = 0, month = 0, year = 0;
    Date();
    Date(int, int, int);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short weekNumber();
    int Duration (Date date);
    int DaysTillYourBithday(Date bithdaydate);
    int NowDay = (QDate::currentDate().toString("dd")).toInt();
    int NowMonth = (QDate::currentDate().toString("MM")).toInt();
    int NowYear = (QDate::currentDate().toString("yyyy")).toInt();
};

#endif // DATE_H
