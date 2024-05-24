#ifndef DATE_H
#define DATE_H

#include <QString>
#include <string>
#include <time.h>

class Date
{
public:
    Date(int _day, int _month, int _year);
    Date(std::string str);
    Date(QString str);
    Date();

    Date NextDay();
    Date PreviousDay();
    bool isLeap();
    short WeekNumber();

    int DaysTillYourBirthday(Date birthdayDate);
    int Duration (Date date);

    static bool isLeapThe(int _year);
    bool isThisDateEarlierThan(Date date);
    static Date Today();
    Date Tomorrow();
    Date Yesterday();
    static Date DateWithPlusThisTime(int minutes);
    void Print();
    QString ToString();

    int Day();
    int Month();
    int Year();

private:
    int day, month, year;
};

#endif // DATE_H
