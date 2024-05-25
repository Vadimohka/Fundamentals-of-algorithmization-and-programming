//
// Created by zgdarya on 4/10/24.
//

#ifndef LAB2_TASK1_DATE_H
#define LAB2_TASK1_DATE_H
#define uint unsigned
#include "ctime"
#include <QDebug>
#include "cmath"

class Date {
private:
    uint _day;
    uint _month;
    uint _year;
    bool _isLeap;
public:
    Date NextDay();
    Date PreviousDay();
    bool isLeap();
    void checkLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date birthday);
    int Duration(Date date);
    void setDay(uint day);
    void setMonth(uint month);
    void setYear(uint year);
    uint getDay();
    uint getMonth();
    uint getYear();
    uint dayInWeek();
    int daysFromBeginning();
    Date(uint day, uint month, uint year);
    Date();
};


#endif //LAB2_TASK1_DATE_H
