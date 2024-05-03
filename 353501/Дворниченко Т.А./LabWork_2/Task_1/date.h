#include <QString>
#include <QStringList>
#include <QDebug>
#include <QDate>

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int year;
    int month;
    int day;
    int days = 0;
    int countDaysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
public:
    Date(int year, int month, int day);

    /*static Date fromString(const QString& dateString);*/

    Date nextDay();

    Date previousDay();

    short weekNumber();

    QString str();

    bool isLeap();

    bool isLeap(int year);

    int duration(Date date1);

    int duration(Date data1, Date data2);

    int durationQDate(Date date);

    int DaysTillYourBithday(Date birthdaydate);

    int absDuration();

    int getDaysInMonth();

    bool wasFebPast();

    static bool CheckStringDate(QString date);

    static Date fromString(const QString& dateString);
};


#endif // DATE_H
