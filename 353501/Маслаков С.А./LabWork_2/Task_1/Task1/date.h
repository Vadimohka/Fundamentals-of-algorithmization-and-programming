#ifndef DATE_H
#define DATE_H
#include<QVector>
#include<QDate>
class Date
{
    int year;
    int month;
    int day;
    int daysofyear;
    QVector<short> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};
public:
    QString fromDateToString();
    Date();
    bool is_Leap();
    Date(int,int,int);
    Date nextDay();
    Date previousDay();
    short WeekNumber();
    QString booltostr(bool);
    QString shorttostr(short);
    QString duration(Date date);
    QString durationnextandthis(Date);
    int count_days(Date);
    int daysTillYourBithday(Date birthdaydate);
};

#endif // DATE_H
