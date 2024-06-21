#ifndef DATE_H
#define DATE_H

#include <QString>
#include <ctime>
#include <QException>

class Date
{
private:
    QString date;
    qint16 day;
    qint16 month;
    qint16 year;

public:
    explicit Date(QString d);
    Date(qint16 d, qint16 m, qint16 y);

    ~Date() = default;

    bool isLeapYear();
    static qint16 WeekNumber();
    Date* NextDay();
    Date* PreviousDay();
    static int DaysTillYourBithday(Date bithdayDate);
    static int DaysBetweenDates(Date firstDate, Date secondDate);
    static int DaysBetweenDates(Date firstDate);
    static bool CheckFormat(QString input);

    QString GetDateStr() { return date; }
    void setDateStr(QString date) { this->date = date; }

    QString ToStr();
    qint16 getMonth();
    qint16 getDay();
    qint16 getYear();
};

#endif // DATE_H
