#include "date.h"


//Cosnstructor
Date::Date(short d, short m, int y) {
    try {
        if(d < 0 || m < 0 || y < 0){
            throw "Only positive numbers";
        }
    }
    catch (const char* error) {

    }

    year = y;
    month = m;
    day = d;

    is_leap = IsLeap();
}

// Task Funcs
short Date::WeekNumber()
{
    short total_days = 0;
    for(int i = 1; i < month; ++i){
        total_days += monthes[i];
    }
    total_days += day;

    return total_days / 7;
}

int Date::DaysTillYourBirthday(Date birth)
{
    short birth_day = birth.day;
    short birth_month = birth.month;

    short total_birthday_day = 0, total_day = 0;
    for(int i = 1; i < birth_month; ++i){
        total_birthday_day += monthes[i];
    }
    total_birthday_day += birth_day;
    for(int i = 1; i < month; ++i){
        total_day += monthes[i];
    }
    total_day += day;

    short diffrence = total_birthday_day - total_day;
    if(diffrence < 0){
        diffrence = 365 - qAbs(diffrence);
    }

    return diffrence;
}
int Date::Duration(Date date)
{
    int total_date_day = 0, total_day = 0;
    int diffrence = 0;

    for(int i = 1; i < date.GetMonth(); ++i){
        total_date_day += monthes[i];
    }
    for(int i = 1; i < month; ++i){
        total_day += monthes[i];
    }
    total_date_day += date.GetDay();
    total_day += day;

    if(date.year < year){
        diffrence = 365 - total_date_day + total_day;

        if(date.year - year != -1){
            diffrence += (year - date.year) * 365;
        }
    }
    else if(date.year > year){
        diffrence = 365 - total_day + total_date_day;

        if(year - date.year != -1){
            diffrence += (year - date.year) * 365;
        }
    }
    else{
        int _min = fmin(total_date_day, total_day);
        int _max = fmax(total_date_day, total_day);

        diffrence = _max - _min;
    }

    return diffrence;   
}
Date Date::NextDay()
{
    Date temp = Date(day, month, year);
    temp.day++;

    temp.MakeToStandart();

    return temp;
}
Date Date::PreviousDay()
{
    Date temp = Date(day, month, year);
    temp.day--;

    temp.MakeToStandart();

    return temp;
}

bool Date::IsLeap()
{
    if(year % 400 == 0){
        return true;
    }
    if(year % 100 == 0){
        return false;
    }
    if(year % 4 == 0){
        return true;
    }
    return false;
}


//Help Funcs
bool Date::IsValid()
{
    if(year > 0 && (day > 0 && day < monthes[month]) && (month > 0 && month < 13)){
        return true;
    }

    return false;
}
Date Date::StringToDate(QString str)
{
    //11.11.1111
    QString num_1 = "00";
    QString num_2 = "00";
    QString num_3 = "0000";

    num_1[0] = str[0];
    num_1[1] = str[1];

    num_2[0] = str[3];
    num_2[1] = str[4];

    num_3[0] = str[6];
    num_3[1] = str[7];
    num_3[2] = str[8];
    num_3[3] = str[9];

    short day_ = num_1.toShort();
    short month_ = num_2.toShort();
    short year_ = num_3.toInt();

    Date a = Date(day_, month_, year_);

    return a;
}
void Date::MakeToStandart()
{
    short days_in_month = monthes[month];
    if(day > days_in_month){
        day %= monthes[month];
        month++;
    }
    if(month == 13){
        month = 1;
        year++;
        is_leap = IsLeap();
    }

    if(day == 0){
        day = monthes[month - 1];
        month--;
    }
    if(month == 0){
        month = 12;
        year--;
    }

    if(day == 0){
        day = monthes[month];
    }

}
QString Date::Print() const
{
    QString temp, Sday, Smonth, Syear;
    Sday.setNum(day);
    Smonth.setNum(month);
    Syear.setNum(year);

    if(day < 10){
        Sday.insert(0, '0');
    }
    if(month < 10){
        Smonth.insert(0, '0');
    }
    if(year < 10){
        Syear.insert(0, "000");
    }
    else if(year < 100){
        Syear.insert(0, "00");
    }
    else if(year < 1000){
        Syear.insert(0, '0');
    }


    temp = Sday + "." + Smonth + "." + Syear;

    return temp;
}


//Geters
int Date::GetDay()
{
    return day;
}

int Date::GetMonth()
{
    return month;
}

int Date::GetYear()
{
    return year;
}
