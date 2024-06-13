#ifndef MYDATE_H
#define MYDATE_H

#include <QString>
#include <QRegularExpression>


class MyDate{
private:
    bool vaild;
    short day;
    short month;
    long long year;
    static bool validate(short day, short month, long long year);
    static short daysInMonth(short month, long long year);
public:
    bool operator<(MyDate another);
    bool isValid();
    MyDate();
    MyDate(short day, short month, long long year);
    MyDate(QString base);
    static bool isLeap(int year);
    const QString toString();
    MyDate nextDay();
    MyDate PreviousDay();
    static MyDate current();
    qint64 daysBetween(MyDate compare);
    qint64 daysFromBegin();
    qint64 daysTillBirthday(MyDate birthday);
};
#endif // MYDATE_H
