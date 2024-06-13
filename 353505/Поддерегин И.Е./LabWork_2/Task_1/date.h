#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int n = 0;
    int day;
    int month;
    int year;

public:
    Date (int _day, int _month, int _year) {
        day=_day;
        month=_month;
        year=_year;
    }
    int operator - (Date& rv) {
        return GetNumberDaysFromBegin() - rv.GetNumberDaysFromBegin();
    }
    std::string to_str();
    bool IsCorrectInput();
    bool IsLeap();
    Date NextDay ();
    Date PreviousDay();
    int GetNumberDaysInMonth(int i);
    int GetNumberDaysFromBegin();
    short WeekNumber ();

    double my_ceil(double week) {
        int int_part = (int)week;

        if (week==int_part) {
            return int_part;
        } else {
            return int_part+1;
        }
    }
    int GetDay();
    int GetMonth();
    int GetYear();
    int GetN();
    void SetN(int _n);
};

#endif // DATE_H
