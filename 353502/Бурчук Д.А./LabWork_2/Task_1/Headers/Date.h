#ifndef LAB2_DATE_H
#define LAB2_DATE_H
#define uint unsigned

#include "QString"
#include "QDebug"
#include "QWidget"
#include <ctime>

class Date {
    uint _day;
    uint _month;
    uint _year;
    bool _isLeap;
public:
    Date(uint day, uint month, uint year);
    Date();

    uint day();
    uint month();
    uint year();
    bool isLeap();

    uint dayOfWeek() const;
    uint numberOfWeek() const;

    void checkLeap();
    void isBirthDay();

    Date nextDay();
    Date previousDay();
    Date nextBirthDay();
    Date previousBirthDay();

    int difference(Date compareDate) const;

//    Date &operator= (Date &date);
};


#endif //LAB2_DATE_H
