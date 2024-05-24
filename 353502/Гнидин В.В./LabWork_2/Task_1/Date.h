//
// Created by volodya-petarda on 4/2/24.
//

#ifndef LAB2_1_DATE_H
#define LAB2_1_DATE_H
#include <iostream>
#include <QDebug>
#include <QString>

class Date {
public:
    Date(int days);
    Date(short day, short month, short year);
    Date(std::string s);
    std::string ToString();

    static bool IsLeap(int year);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short DayOfWeek();
    short WeekNumber();
    int DaysTillYourBirthday(Date birthdayDate);
    int Duration(Date date);
    int InDays();
private:
    static constexpr short DAYS_IN_MONTH[]{0,31, 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31};
    short day, month, year;
};


#endif //LAB2_1_DATE_H
