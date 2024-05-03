#include "date.h"

Date::Date() = default;

Date::Date(int day, int month, int year) {
    Date::day = day;
    Date::month = month;
    Date::year = year;
}

bool Date::IsLeap()
{
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    else{
        return false;
    }
}

Date Date::NextDay(){
    if((month == 12) && (day == 31))
    {
        return Date(1, 1, year + 1);
    }
    else if((day == 29) && (month == 2))
    {
        return Date(1, 3, year);
    }
    else if((day == 28) && (month == 2) && IsLeap()){
        return Date(day + 1, month, year);
    }
    else if(day == list_days[month - 1])
    {
        return Date(1, month + 1, year);
    }
    else{
        return Date(day + 1, month, year);
    }
}

Date Date::PreviousDay(){
    if((month == 1) && (day == 1))
    {
        return Date(31, 12, year - 1);
    }
    else if (day == 1)
    {
        if (month == 3 && IsLeap())
        {
            return Date(29, 2, year);
        }

        return Date(list_days[month - 2], month - 1, year);
    }
    return Date(day - 1, month, year);
}

int Date::Duration(Date date)
{
    QDate dt1 = QDate(date.year, date.month, date.day);
    QDate dt2 = QDate(NowYear, NowMonth, NowDay);

    int toJulianDay1 = dt1.toJulianDay();
    int toJulianDay2 = dt2.toJulianDay();

    int result = toJulianDay1-toJulianDay2;

    return (result >= 0 ? result : -result);
}

int Date::DaysTillYourBithday(Date bithdaydate){
    QDate dt1 = QDate(bithdaydate.year, bithdaydate.month, bithdaydate.day);
    QDate dt2 = QDate(NowYear, NowMonth, NowDay);

    int toJulianDay1 = dt1.toJulianDay();
    int toJulianDay2 = dt2.toJulianDay();

    int result = toJulianDay2 - toJulianDay1;
        if (NowMonth == bithdaydate.month && bithdaydate.day == NowDay){
            return 0;
        }
        else if(bithdaydate.day == 29 && bithdaydate.month == 2){
            int year_bs = bithdaydate.year;
            while (NowYear >= year_bs){
            year_bs += 4;
            if (NowYear == year_bs){
                dt1 = QDate(NowYear, bithdaydate.month, bithdaydate.day);
                toJulianDay1 = dt1.toJulianDay();

                result = toJulianDay1 - toJulianDay2;
                if (result >= 0){
                    return result;
                }
                else{
                    dt1 = QDate(NowYear + 4, bithdaydate.month, bithdaydate.day);
                    toJulianDay1 = dt1.toJulianDay();
                    result = toJulianDay1 - toJulianDay2;
                    return result;
                }
            }
            }
            return (year_bs - NowYear) * 365;
        }
        else{
            dt1 = QDate(NowYear, bithdaydate.month, bithdaydate.day);
            toJulianDay1 = dt1.toJulianDay();

            result = toJulianDay1 - toJulianDay2;
            if (result >= 0){
                return result;
            }
            else{
                dt1 = QDate(NowYear + 1, bithdaydate.month, bithdaydate.day);
                toJulianDay1 = dt1.toJulianDay();
                result = toJulianDay1 - toJulianDay2;
                return result;
            }
        }
}

short Date::weekNumber()
{
    QDate date = QDate(year, month, day);
    return date.weekNumber();
}


