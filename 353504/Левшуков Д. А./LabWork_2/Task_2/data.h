#ifndef DataA_H
#define DataA_H

#include<string>

class Data
{
public:
    Data(short int d, short int m, unsigned long long y);
    Data();
    bool Init(std::string s);
    std::string get();
    Data NextDay();
    bool LeapYear();
    bool LeapYear( unsigned long long year);
    short int Days(short int m);
    short int get_day();
    short int get_month();
    unsigned long long get_year();
    short Days(short m, unsigned long long y);
    bool operator >= (Data b);
    bool operator <= (Data b);
    bool operator == (Data b);
    bool operator <(Data b);
    bool operator >(Data b);
private:
    short int day,month;
    unsigned long long year;
    std::string Data_to_string(Data a);
};

#endif // DataA_H
