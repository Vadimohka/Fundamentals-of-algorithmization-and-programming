#ifndef MYDATECLASS_H
#define MYDATECLASS_H

#include <QtWidgets>

class MyDateClass
{
    QVector<QDate> dateList;

public:
    MyDateClass() = default;

    void addDate(QDate date);

    QString getDate(int num);

    QString getNextDate(int num);

    QString getPreviousDate(int num);

    bool isLeapYear(int num);

    int daysTillBirthday(QDate birthdayDate, int num);

    int weekNumber(int num);

    int duration(int num);

    int changeDate(QDate oldDate, QDate newDate);

    static QString dateToString(QDate date);
};

#endif // MYDATECLASS_H
