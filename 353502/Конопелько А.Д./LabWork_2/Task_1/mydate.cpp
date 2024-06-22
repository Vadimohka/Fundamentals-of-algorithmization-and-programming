#include "mydate.h"

QDate MyDate::NextDay(QDate date)
{
    return (date.addDays(1));
}

QDate MyDate::PreviousDay(QDate date)
{
    return (date.addDays(-1));
}

bool MyDate::IsLeap(QDate date)
{
    int year = date.year();
    return (isLeapYear(year));
}

short MyDate::WeekNumber()
{
    return (nowDate.weekNumber());
}

int MyDate::DaysTillYourBirthday(QDate birthdayDate)
{
    if(!birthdayDate.isValid() || birthdayDate > nowDate)
        return -1;
    int birthMonth = birthdayDate.month();
    int birthDay = birthdayDate.day();
    int birthYear = nowDate.year();
    int birthDayNumber = birthdayDate.dayOfYear();
    int startDayNumber = nowDate.dayOfYear();
    int daysInNowYear = nowDate.daysInYear();
    int addNumb = daysInNowYear - startDayNumber;
    if(birthMonth < nowDate.month()){
        birthYear++;
    }
    else if(birthMonth == nowDate.month() && birthDay < nowDate.day()){
        birthYear++;
    }
    else{
        return (birthDayNumber - startDayNumber);
    }
    if(QDate(birthYear, birthMonth, birthDay).isValid()){
        return(addNumb + QDate(birthYear, birthMonth, birthDay).dayOfYear());
    }
    else{
        int i = 0;
        while(true){
            if(QDate(birthYear + i, birthMonth, birthDay).isValid()){
                return (addNumb + QDate(birthYear + i, birthMonth, birthDay).dayOfYear());
            }
            else{
                addNumb += QDate(birthYear + i, birthMonth, birthDay - 2).daysInYear();
                i++;
            }
        }
    }
}

int MyDate::Duration(QDate date)
{
    return (abs(date.daysTo(nowDate)));
}

MyDate::MyDate(int day, int month, int year) : day(day),
    month(month),
    year(year)
{

}

MyDate::MyDate(QDate dateInsert)
{
    date = dateInsert;
}

MyDate::MyDate()
{
//    qDebug() << DaysTillYourBirthday(QDate(2005, 02, 29));
}


