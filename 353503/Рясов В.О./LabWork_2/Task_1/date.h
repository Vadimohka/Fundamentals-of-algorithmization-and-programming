#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
    int _day, _month, _year;
public:
    bool isLeap(int year);
    int getDay() {return this -> _day;}
    int getMonth(){return this -> _month;}
    int getYear(){return this -> _year;}
    QString weekNumber();
    static QString daysTillYourBirthday(Date birthday);
    int duration(Date date);
    QString nextDay();
    QString previousDay();
    QString toQString();
    Date(int day, int month, int year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
};

#endif // DATE_H
