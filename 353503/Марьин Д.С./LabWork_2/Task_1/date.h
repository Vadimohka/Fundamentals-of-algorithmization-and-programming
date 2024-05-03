#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QVector>

enum Month
{
    January = 0,
    February ,
    March ,
    April,
    May ,
    June ,
    July ,
    August ,
    September ,
    October ,
    November,
    December
};
class Date
{
public:

    Date(int day,int month,int year);
    Date(QDate date);

    QDate getDate();
    Date NextDay();
    Date PreviousDay();

    QString toString();
    bool isLeap();

    int getDayInMonth(int month);
    int getDay();
    int getMonth();
    int getYear();
    int DaysTillYourBithday(Date bithdaydate);
    long long Duration (Date date);
    short WeekNumber();

private:
    QDate *_qDate;
    QVector<int> _monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int _day, _month, _year;
    bool _isLeap;
};
#endif // DATE_H
