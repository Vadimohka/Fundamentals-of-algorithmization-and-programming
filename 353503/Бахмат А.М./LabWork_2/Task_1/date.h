#ifndef DATE_H
#define DATE_H

#include <cmath>
#include <QDate>

class Date
{
public:
    Date();
    Date(int year, int month, int day);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date birthdaydate);
    int Duration(Date date);
    QString FromDateToString();
    Date FromQDatetoDate(QDate qdate);
    QString FromIntToString(int num);
    QString FromShortToString(short num);
    QString FromBoolToString(bool flag);
private:
    int _day = 0, _month = 0, _year= 0;
    short _daysSinceBeggingOfYear = 0;
    const short _monthsInYear = 12, _daysInYear = 365, _day31 = 31, _day28 = 28, _day30 = 30, _day29 = 29, _monthFebruary = 2;
    const short _oneHundreed = 100, _fourHundreed = 400;
    const short _daysInPerMonth[12] = {_day31, _day28, _day31, _day30, _day31, _day30, _day31, _day31, _day30, _day31, _day30, _day31};
};

#endif // DATE_H
