#include <QDate>
#include <QString>

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    qint16 day;
    qint16 month;
    qint16 year;
    qint16 daysAmount;
    qint16 daysMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
public:
    Date()=default;
    Date(qint16,qint16,qint16);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    qint16 WeekNumber();
    int DaysTillYourBirthday(Date birthdaydate);
    int Duration(Date date);
    QString str();
    QString boolToString(bool);
    QString qint16ToString(qint16);
    QString intToString(int);
};
#endif // DATE_H
