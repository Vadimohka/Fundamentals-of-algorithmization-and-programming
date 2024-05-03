#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QTableWidgetItem>

class Date
{
public:
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    Date NextDay() const;
    Date PreviousDay() const;
    bool IsLeap() const;
    short WeekNumber() const;
    int DaysTillYourBithday(const Date& birthdayDate) const;
    int Duration(const Date& date) const;
    QString toString() const;


private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
