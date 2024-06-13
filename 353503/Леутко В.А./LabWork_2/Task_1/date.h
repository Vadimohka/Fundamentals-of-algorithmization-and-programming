#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QString>

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
    bool IsLeap();
    Date NextDay();
    Date PreviousDay();
    QString str();
    qint16 WeekNumber();
    int Duration(Date date);
    QString boolToString(bool);
    QString qint16ToString(qint16);
    QString intToString(int);
    int DaysTillYourBirthday(Date birthdaydate);
};

#endif // DATE_H
