#ifndef DATA_H
#define DATA_H

#include<string>
#include<QDate>
#include<ctime>

class Date
{
public:
    Date(short int d, short int m, long long y);
    Date();
    Date today();
    std::string NextDay();
    std::string PreviousDay();
    int DaysTillYourBirthday(Date birthdaydate);
    long long Duration(Date a);
    bool Init(std::string s);
    std::string get_date();
    bool LeapYear();
    short int Days(short int m);
    short int get_day();
    short int get_month();
    long long get_year();
    bool LeapYear(long long year);
    short Days(short m, long long y);
    void set_year(long long y);
private:
    short int day,month;
    long long year;
    std::string date_to_string(Date a);
};

#endif // DATA_H
