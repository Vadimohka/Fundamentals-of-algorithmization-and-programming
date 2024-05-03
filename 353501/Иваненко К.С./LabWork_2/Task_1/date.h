#ifndef DATE_H
#define DATE_H
#include <QDate>

class Date : public QDate
{
    int day;
    int month;
    int year;
    bool isLeapYear(int year1) const;
    int daysInMonth(int year1, int month1) const;

public:
    void showinfo();
    Date();
    Date(int a, int b, int c);
    bool isleap();
    int whatdayisit();
    Date nextday();
    Date prevday();
    short weeknum();
    int daystillmybday(Date a);
    long long duration(Date a);
    QDate toQDate();
};

#endif // DATE_H