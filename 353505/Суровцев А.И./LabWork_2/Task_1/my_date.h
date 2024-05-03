#ifndef MY_DATE_H
#define MY_DATE_H
#include <QString>
#include <QStringList>
class My_Date
{
private:
    int year;
    int month;
    int day;
public:
    My_Date();
    My_Date(int year, int month, int day) : year(year), month(month), day(day) {}
    bool isCorrectDate(int year, int month, int day);
    int getYear();
    int getMonth();
    int getDay();
    bool setDate(const QString &dateString);
    void setDate(int year, int month, int day);
    QString toString();
    bool isLeapYear(int year);
    int DaysInMonth(int month, int year);
    short WeekNumber();
    void addDays(int numDays);
    int TotalDays();
};

#endif // MY_DATE_H
