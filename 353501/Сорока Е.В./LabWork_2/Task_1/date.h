
#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QString>


class Date
{
public:
    int year;
    int month;
    int day;
    int days;
    int countDays[12];
public:
    QString *dates;
    Date();
    Date(int, int, int);
    Date nextDay();
    Date previousDay();
    bool isLeap();
    short weekNumber();
    int daysTillYourBithday(Date birthdaydate);
    int duration (Date date);
    QString str();
    QString boolToString(bool);
    QString shortToString(short);
    QString intToString(int);
    void input(QString text);
};


#endif // DATE_H
