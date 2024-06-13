#include <QDate>
#include <QString>

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int year;
    int month;
    int day;
    int days;
    int countDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
public:
    QString *dates;
    QString str();
    QString boolToString(bool);
    QString shortToString(short);
    QString intToString(int);
    Date();
    Date(int, int, int);
    Date nextDay();
    Date previousDay();
    bool isLeap();
    short weekNumber();
    int daysTillYourBithday(Date birthdaydate);
    int duration (Date date);
    void input(QString text);
};


#endif // DATE_H
