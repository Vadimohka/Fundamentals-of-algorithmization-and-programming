#ifndef DATE_H
#define DATE_H

#include <QtMath>
#include <QString>
#include <QList>

class Date{
public:
    Date();
    Date(const QString &datestr);
    Date(short d, short m, long y);

    int getYear() const;
    int getDay() const;
    int getMonth() const;
    int getMaxDaysInMonth(int m);

    bool isLeap();
    bool isValid();

    Date Today();
    Date NextDay();
    Date PreviousDay();
    short DayOfWeek();
    int DayOfYear();
    short WeekNumber();
    long long Duration(Date date);
    int DaysTillYourBiryhday(Date bithdaydate);

    QString ToString() const;
    Date StringInDate(QString DateString);

private:
    short day, month;
    long year;
};

#endif // DATE_H
