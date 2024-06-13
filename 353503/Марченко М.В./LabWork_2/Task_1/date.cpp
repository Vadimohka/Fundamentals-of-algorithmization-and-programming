#include "date.h"
#include <QDebug>
Date::Date(qint16 year,qint16 month,qint16 day)
{
    this->year=year;
    this->month=month;
    this->day=day;
    if(IsLeap()){
        ++daysMonth[1];
    }
    daysAmount+=day;
    for(int i=0;i<month-2;i++)
    {
        daysAmount+=daysMonth[i];
    }
}

Date Date::NextDay()
{
    if(month==12&&day==31){

        return Date(year+1,1,1);
    }
    else if(day==daysMonth[month-1]){
        return Date(year,month+1,1);
    }
    else {
        return Date(year,month,day+1);
    }
}

Date Date::PreviousDay()
{
    if(month==1&&day==1) {
        return Date(year-1,12,31);
    }
    else if(day==1){
        return Date(year,month-1,daysMonth[month-2]);
    }
    else{
        return Date(year,month,day-1);
    }
}

bool Date::IsLeap()
{
    if((year%4==0)&&(year%100!=0||year%400==0)){
        return true;
    }
    else {
        return false;
    }
}

qint16 Date::WeekNumber()
{
    int daysPassed = day;
    for (int i = 1; i < month; ++i) {
        daysPassed += daysMonth[i - 1];
    }
    int weekNumber = (daysPassed -1) / 7+1;

    return weekNumber;
}

int Date::DaysTillYourBirthday(Date birthdaydate)
{
    QString strCurDay="",strCurMonth="", strCurYear="";
    QString strCurDate=QDate::currentDate().toString("dd.MM.yyyy");
    qint16 curDay=0,curMonth=0,curYear=0;
    int dateGivenValue=0,dateCurrentValue=0;
    for(int i=0;i<strCurDate.size();i++)
    {
        if (i >= 0 && i < 2){
            strCurDay += strCurDate[i];
        }
        else if (i > 2 && i < 5){
            strCurMonth += strCurDate[i];
        }
        else if (i > 5){
            strCurYear += strCurDate[i];
        }
    }
    curDay=strCurDay.toInt();
    curMonth=strCurMonth.toInt();
    curYear=strCurYear.toInt();
    QDate dateGiven=QDate(2024,birthdaydate.month,birthdaydate.day);
    QDate dateCurrent=QDate(curYear,curMonth,curDay);
    dateGivenValue=dateGiven.toJulianDay();
    dateCurrentValue=dateCurrent.toJulianDay();
    if( birthdaydate.day ==29 && birthdaydate.month == 2){
        return (4 - (curYear % 4))*365 + 1 - qAbs(dateGivenValue-dateCurrentValue);
    }
    else if(birthdaydate.month < curMonth || (birthdaydate.month == curMonth && birthdaydate.day < curDay)){
        if((birthdaydate.month<=2 && birthdaydate.day<29) || ( (curYear+1)%4==0 && ((curYear+1)%100!=0) )|| ((curYear+1)%400==0) ) {
            return 366- qAbs(dateGivenValue-dateCurrentValue);
        }
        else{
            return 365 - qAbs(dateGivenValue-dateCurrentValue);
        }
    }
    else{
        return qAbs(dateGivenValue-dateCurrentValue);
    }
}

int Date::Duration(Date date)
{
    QString strCurDay="",strCurMonth="",strCurYear="";
    QString strCurDate=QDate::currentDate().toString("dd.MM.yyyy");
    qint16 curDay=0,curMonth=0,curYear=0;
    int dateGivenValue=0,dateCurrentValue=0;
    for(int i=0;i<strCurDate.size();i++)
    {
        if(i>=0&&i<2){
            strCurDay+=strCurDate[i];
        }
        if(i>2&&i<5){
            strCurMonth+=strCurDate[i];
        }
        if(i>5){
            strCurYear+=strCurDate[i];
        }
    }
    curDay=strCurDay.toInt();
    curMonth=strCurMonth.toInt();
    curYear=strCurYear.toInt();
    QDate dateGiven=QDate(date.year,date.month,date.day);
    QDate dateCurrent=QDate(curYear,curMonth,curDay);
    dateGivenValue=dateGiven.toJulianDay();
    dateCurrentValue=dateCurrent.toJulianDay();
    return qAbs(dateGivenValue-dateCurrentValue);
}

QString Date::str()
{
    return QDate(year,month,day).toString("dd.MM.yyyy");
}

QString Date::boolToString(bool answer)
{
    if(answer){
        return "Yes";
    }
    else{
        return "No";
    }
}

QString Date::qint16ToString(qint16 x)
{
    QString conversion="";
    return conversion.setNum(x);
}

QString Date::intToString(int x)
{
    QString conversion="";
    return conversion.setNum(x);
}

