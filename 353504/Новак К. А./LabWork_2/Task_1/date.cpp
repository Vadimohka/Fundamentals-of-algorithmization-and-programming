#include "date.h"
#include <ctime>

Date::Date() {
    day = 24;
    month = 4;
    year = 2000;
}

Date::Date(const QString &datestr){
    *this = StringInDate(datestr);
}

Date::Date(short d, short m, long y){
    day = d;
    month = m;
    year = y;
}

int Date::getYear() const{
    return year;
}

int Date::getDay() const{
    return day;
}

int Date::getMonth() const{
    return month;
}

int Date::getMaxDaysInMonth(int m) {
    if (m == 2){
        return isLeap() ? 29 : 28;
    } else if (m == 4 || m == 6 || m == 9 || m == 11){
        return 30;
    } else {
        return 31;
    }
}

bool Date::isLeap(){
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
        return true;
    }

    return false;
}

bool Date::isValid(){
    return (year < 100000 && year > 0 && month > 0 && month <= 12 && day > 0 &&
            day <= getMaxDaysInMonth(month));
}

Date Date::Today(){
    std::time_t t = std::time(0);   // получить текущее время
    std::tm* now = std::localtime(&t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

Date Date::NextDay(){
    Date NextDay;
    if(month <= 7){
        if(month % 2 && day < 31 || month % 2 == 0 && day < 30){
            if(month != 2){
                NextDay.day = day + 1;
                NextDay.month = month;
            } else {
                if(isLeap() && day < 29 || !isLeap() && day < 28){
                    NextDay.day = day + 1;
                    NextDay.month = month;
                }
            }
        }
        else {
            NextDay.day = 1;
            NextDay.month = (month == 12)?1 : (month + 1);

        }
    } else {
        if(month % 2 && day < 30 || month % 2 == 0 && day < 31){
            NextDay.day = day +1;
            NextDay.month = month;
        }
        else {
            NextDay.day = 1;

            if (NextDay.month == 12){
                NextDay.year++;
            }
            NextDay.month = (month == 12) ? 1 : (month + 1);
        }
    }

    return NextDay;
}

Date Date::PreviousDay(){
    Date PreviousDay;
    PreviousDay.year = year;
    if(day > 1){
        PreviousDay.day = day - 1;
    } else {
        if(month != 2){
            if(month <= 7){
                PreviousDay.day = (month % 2 ? 31 : 30);
            } else {
                PreviousDay.day = (month % 2 ? 30 : 31);
            }
        } else {
            PreviousDay.day = (isLeap() ? 29 : 28);
        }
        PreviousDay.month = month - 1;
    }

    if(PreviousDay.month == -1){
        PreviousDay.day = 31;
        PreviousDay.month = 12;
        PreviousDay.year--;
    }

    return PreviousDay;
}

short Date::DayOfWeek(){
    short codeMonth = 0;
    if(month == 1 || month == 10){
        codeMonth = 1;
    } else if(month == 2 || month == 3 || month == 11){
        codeMonth = 4;
    } else if(month == 5){
        codeMonth = 2;
    } else if(month == 6){
        codeMonth = 5;
    } else if(month == 8){
        codeMonth = 3;
    } else if(month == 9 || month == 12){
        codeMonth = 6;
    }

    if(isLeap()){
        codeMonth--;
    }

    int codeYear = ((short)(year / 100) - 1) % 4 * 2;
    if(codeYear == -2) codeYear = 6;
    codeYear += year % 100 + (year % 100) / 4;
    codeYear %= 7;

    short dayWeek = (codeMonth + codeYear + day) % 7;

    return dayWeek;
}

int Date::DayOfYear(){
    int now = 0;
    for(int i = 1; i < month; ++i){
        if(i != 2){
            if(i <= 7){
                now += (i % 2 ? 31 : 30);
            } else {
                now += (i % 2 ? 30 : 31);
            }
        } else {
            now += (isLeap() ? 29 : 28);
        }
    }

    now += day;

    return now;
}

short Date::WeekNumber(){
    short number = 0;

    short now_day_week = DayOfWeek();
    int now = DayOfYear();
    now -= now_day_week;

    number = qCeil(now / 7);

    return number;
}

long long Date::Duration(Date date){
    int days = 0;
    if(year == date.year){
        return qAbs(DayOfYear() - date.DayOfYear());
    } else {
        for(int i = qMin(date.year, year); i < qMax(date.year, year); ++i){
            days += 365;
            if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)){
                days++;
            }
        }
        days += qAbs(DayOfYear() - date.DayOfYear());
    }

    return days;
}

int Date::DaysTillYourBiryhday(Date bithdaydate){
    if(month < bithdaydate.month){
        return Duration(bithdaydate);
    } else if(month == bithdaydate.month){
        if(day <= bithdaydate.day){
            return Duration(bithdaydate);
        }
    }

    int days = 365 - qAbs(DayOfYear() - bithdaydate.DayOfYear());
    return isLeap() ? days + 1 : days;
}

QString Date::ToString() const{
    QString retString;
    retString += QString::number(day / 10) + QString::number(day % 10) + '.' +
                 QString::number(month / 10) + QString::number(month % 10) + '.';
    int tYear = year;
    retString += ("    ");

    for (int i = 4; i > 0; --i){
        retString.replace(5 + i, 1, char(tYear % 10 + '0'));
        tYear /= 10;
    }

    return retString;
}

Date Date::StringInDate(QString datestr){
    QStringList dateParts = datestr.split('.');

    if (dateParts.size() != 3){
        return Date(0, 0, 0);
    }

    Date tryget = Date(datestr.split('.')[0].toInt(), datestr.split('.')[1].toInt(),
                       datestr.split('.')[2].toInt());
    // if (tryget.isValid(tryget)) {
        return tryget;
    // }

    // return Date(0, 0, 0);
}

