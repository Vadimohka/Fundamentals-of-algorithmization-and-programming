#include "date.h"
Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}
QString Date::fromDateToString() {
    return QDate(year,month,day).toString("dd.MM.yyyy");
}
Date::Date(int y,int m,int d){
    day = d;
    month = m;
    year = y;
    for(int i = 0;i < m - 1;++i){
        daysofyear += days_in_month[i];
    }
    if(is_Leap()) daysofyear++;
    daysofyear += day;
}
bool Date::is_Leap()
{
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }

    return false;
}
Date Date::previousDay()
{
    if((month == 1)&&(day == 1))
    {
        return Date(year - 1, 12, 31);
    }

    if (day == 1)
    {
        if (month == 3 && is_Leap())
        {
            return Date(year, 2, 29);
        }

        return Date(year, month - 1, days_in_month[month-2]);
    }

    return Date(year, month, day-1);
}

short Date::WeekNumber()
{
    return daysofyear / 7 + 1;
}
Date Date::nextDay()
{
    if((month % 12 == 0) && (day == 31))
    {
        return Date(year+1, 1, 1);
    }

    if((day == 29) && (month == 2))
    {
        return Date(year, 3, 1);
    }

    if(day == days_in_month[month - 1])
    {
        return Date(year, month + 1, 1);
    }

    return Date(year, month, day + 1);
}
QString Date::booltostr(bool ans)
{
    if(ans)
    {
        return "Yes";
    }

    return "No";
}

QString Date::shorttostr(short a)
{
    QString str;
    return str.setNum(a);
}
int Date::count_days(Date x){
    int result = 0;
    for(int y = 1;y <= x.year;++y){
        if ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0)){
            result += 366;
        }
        else result += 365;
    }
    for(int y = 1;y <= x.month;++y){
        if ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0) && y == 2){
            result += 29;
        }
        else result += days_in_month[y - 1];
    }
    result += x.day;
    return result;
}

QString Date::duration(Date date){
    QString str1,str2, str3;
    QString str = QDate::currentDate().toString("dd.MM.yyyy");

    for (int i = 0; i< str.size();i++)
    {
        if(i > -1 && i < 2)
        {
            str1=str1+str[i];
        }

        if(i < 5 && i > 2)
        {
            str2 = str2 + str[i];
        }

        if(i > 5)
        {
            str3 = str3 + str[i];
        }
    }

    int curDay = str1.toInt();
    int curMonth = str2.toInt();
    int curYear = str3.toInt();
    Date curdate(curYear,curMonth,curDay);
    int a = count_days(curdate);
    int b = count_days(date);
    int result = a - b;
    if (result < 0) result = -result;
    QString resultstr = QString::number(result);
    return resultstr;

}
QString Date::durationnextandthis(Date date){

    QDate dt1 = QDate(year,month,day);

    QDate dt2 = QDate(date.year,date.month,date.day);

    int diff1 = dt1.toJulianDay();

    int diff2 = dt2.toJulianDay();

    int result = qAbs(diff1-diff2);
    QString resultstr = QString::number(result);
    return resultstr;
}
int Date::daysTillYourBithday(Date birthdaydate)
{
    QString str1, str2;
    QString str = QDate::currentDate().toString("dd.MM.yyyy");

    for (int i = 0; i< str.size();i++)
    {
        if(i > -1 && i < 2)
        {
            str1=str1+str[i];
        }

        if(i < 5 && i > 2)
        {
            str2 = str2 + str[i];
        }
    }

    int curDay = str1.toInt();
    int curMonth = str2.toInt();

    if (is_Leap() && curMonth > birthdaydate.month)
    {
        return 366 - duration(Date(this->year, birthdaydate.month, birthdaydate.day)).toInt();
    }

    else if(is_Leap() && curMonth == birthdaydate.month)
    {
        if(curDay>birthdaydate.day)
        {
            return 366 - duration(Date(this->year, birthdaydate.month, birthdaydate.day)).toInt();
        }
    }

    else if (curMonth > birthdaydate.month)
    {
        return 365 - duration(Date(this->year, birthdaydate.month, birthdaydate.day)).toInt();
    }

    else if(curMonth == birthdaydate.month)
    {
        if(curDay>birthdaydate.day)
        {
            return 365 - duration(Date(this->year, birthdaydate.month, birthdaydate.day)).toInt();
        }
    }

    return duration(Date(this->year, birthdaydate.month, birthdaydate.day)).toInt();
}
