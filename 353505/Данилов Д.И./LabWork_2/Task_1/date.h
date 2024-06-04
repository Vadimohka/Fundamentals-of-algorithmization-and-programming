#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QString>

class Date
{
public:
    Date(int = 0, int = 0, int = 0);
    ~Date();
    Date nextDay();
    Date previousDay();
    bool isLeap();
    static bool isLeap(int);
    int weekNumber();
    static Date todayDate();
    int daysBeforeYourBithday(const Date&);
    int daysFromYearTo(int, const Date&);
    int duration();
    static Date fromString(const QString&);
    QString toString();
    static QString boolToString(bool);
    static QString intToString(int);
    static int getDaysInMonth(int, int);
private:
    int year;
    int month;
    int day;
    int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // DATE_H
