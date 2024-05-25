//
// Created by zgdarya on 4/20/24.
//

#ifndef LAB2_TASK2_DATE_H
#define LAB2_TASK2_DATE_H


#include "ctime"
#include <QDebug>
#include "cmath"

class Date {
private:
    int _day;
    int _month;
    int _year;
    bool _isLeap;

public:
    bool isLeap();
    void checkLeap();
    int Duration(Date date);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    int getDay();
    int getMonth();
    int getYear();
    int daysFromBeginning();
    Date(int day, int month, int year);
    Date();
};


#endif //LAB2_TASK2_DATE_H
