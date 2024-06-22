#ifndef MYDATE_H
#define MYDATE_H

#include <QDebug>
#include <QDate>
#include <cmath>
#include <QString>

class MyDate: public QDate
{
private:
    int day;
    int month;
    int year;

public:
    static QDate NextDay(QDate date);
    static QDate PreviousDay(QDate date);
    bool IsLeap(QDate date);
    short WeekNumber();
    int DaysTillYourBirthday(QDate birthdayDate);
    int Duration(QDate date);
    QDate nowDate = QDate::currentDate();
    QDate date;
    MyDate(int day, int month, int year);
    MyDate(QDate);
    MyDate();
};

#endif // MYDATE_H
