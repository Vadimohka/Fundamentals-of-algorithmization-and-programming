#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
public:
    Date(int day, int month, int year);
    explicit Date(QString date);
    bool canBeBirtday();
    Date nextDay();
    Date previousDay();
    int daysTillYourBirthday(Date birthdayDate);
    int duration(Date date);
    short weekNumber();
    bool isLeapYear(int year);
    inline bool isLeapYear() const {return isLeap;};
    inline bool isCorrectDate() const {return isCorrect;};
    QString getDate() const;
private:
    int dayInYear;
    bool isCorrect = 1;
    int currentDay;
    int currentMonth;
    int currentYear;
    bool isLeap = 0;
    short daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // DATE_H
