#ifndef DATE_H
#define DATE_H


#include <QString>
#include <cmath>
#include <QDebug>
#include <ctime>

class Date
{
private:
    int day;
    int month;
    int year;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date();
    Date (const Date &date);
    Date (const QString date);
    Date (const std::time_t time);
    bool isLeap() const;
    int weekNumber() const;
    Date nextDay() const;
    Date previousDay() const;
    QString getDateStr() const;
    int difference(const Date& date) const;
    int daysTillYourBirthday(const Date& date) const;
    bool checkDateFormat(const QString input) const;
    int daysInYear(const int y) const;


};

#endif // DATE_H
