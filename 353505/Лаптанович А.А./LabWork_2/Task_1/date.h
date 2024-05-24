#ifndef DATE_H
#define DATE_H

#include <QString>
class Date
{
public:
    Date(short, short, short);
    short GetDay();
    short GetMonth();
    short GetYear();
    void SetYear(short);
    void SetMonth(short);
    void SetDay(short);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBithday(Date);
    int Duration(Date);
    QString ToQString();

private:
    short day;
    short month;
    short year;
    short dayOfWeekOfYearBegin(short);
    bool isLeap(short);
    int duration(Date, Date);
};

#endif // DATE_H
