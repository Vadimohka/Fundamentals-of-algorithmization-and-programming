#ifndef DATE_H
#define DATE_H

#include <QString>
#include <string>
#include <sstream>

class Date
{
public:
    Date();
    Date(int day, int month, int year);
    Date(std::string date);
    ~Date();

    int Day();
    int Month();
    int Year();

    Date NextDay();
    Date PreviousDate();

    bool IsLeap();

    short WeekNumber();
    short WeekDay();

    int Duration(Date secondDate);
    int DaysTillYourBirthday(Date birthdaydate);
    int daysInMonth(int month);

    QString Output();
    std::string output();


protected:
    short yearCode();
    short monthCode();

    long long daysSinceFirstYear();

private:
    int m_day;
    int m_month;
    int m_year;
};

#endif // DATE_H
