#include "date.h"

Date::Date(int day, int month, int year): day(day), month(month), year(year) {}

int Date::getDay() const
{
    return day;
}

void Date::setDay(int newDay)
{
    day = newDay;
}

int Date::getMonth() const
{
    return month;
}

void Date::setMonth(int newMonth)
{
    month = newMonth;
}

int Date::getYear() const
{
    return year;
}

void Date::setYear(int newYear)
{
    year = newYear;
}


Date Date::NextDay()
{
    int numberOfdaysInMonth;
    switch (month)
    {
    case 2:
        numberOfdaysInMonth = (IsLeap() ? 29 : 28);
        break;
    case 4: case 6: case 9: case 11:
        numberOfdaysInMonth = 30;
        break;
    default:
        numberOfdaysInMonth = 31;
        break;
    }

    if (day < numberOfdaysInMonth) return Date(day + 1, month, year);
    if (day == numberOfdaysInMonth)
    {
        if (month < 12) return Date(1, month + 1, year);
        else return Date(1, 1, year + 1);
    }
}

bool Date::IsLeap()
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

bool Date::IsLeap(int year)
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

Date Date::PreviousDay()
{
    if (day > 1) return Date(day - 1, month, year);
    if (day == 1)
    {
        if (month > 1) return Date(31, month - 1, year);
        else return Date(31, 12, year - 1);
    }
}

short Date::WeekNumber()
{
    int days = day;

    for(int i = 1; i < month; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) days += 31;
        else if(i == 2)
        {
            if(IsLeap()) days += 29;
            else days += 28;
        }
        else days += 30;
    }

    short ans = 1;
    if (days >= 7 - theFirstDay() + 1 + 1)
    {
        int days1 = days - (7 - theFirstDay() + 1);
        ans = (days1 % 7 == 0 ? days1 / 7 : days1 / 7 + 1) + 1;
    }

    return ans;
}

short Date::theFirstDay()
{
    int totalDays = 5, totalYears = 0;
    while (totalYears < year)
    {
        if (IsLeap(totalYears))
        {
            ++totalYears;
            totalDays += 366;
        }
        else
        {
            ++totalYears;
            totalDays += 365;
        }

        totalDays %= 7;
    }
    return totalDays + 1;
}

int Date::Duration(Date date)
{
    return duration(*this, date);
}

int Date::duration(Date date1, Date date2)
{
/*
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int daysFirst = date1.day, daysSecond = date2.day;

    for (int m = 1; m < date1.month; ++m)
    {
        daysFirst += daysInMonth[m - 1];
    }
    daysFirst += (date1.year - 1) * 365 + (date1.year - 1) / 4 - (date1.year - 1) / 100 + (date1.year - 1) / 400;


    for (int m = 1; m < date2.month; ++m)
    {
        daysSecond += daysInMonth[m - 1];
    }
    daysSecond += (date2.year - 1) * 365 + (date2.year - 1) / 4 - (date2.year - 1) / 100 + (date2.year - 1) / 400;

    return abs(daysSecond - daysFirst);*/

    QDate temp1(date1.year, date1.month, date1.day), temp2(date2.year, date2.month, date2.day), temp;
    int ans = 0;

    qDebug() << date1.year << " " << date1.month << " " << date1.day;

    if (temp1 > temp2)
    {
        temp = temp1;
        temp1 = temp2;
        temp2 = temp;
        qDebug() << "NOW";
    }
    while (temp1 < temp2)
    {
        temp1 = temp1.addDays(1);
        ++ans;
        //qDebug() << "trreee";
        //qDebug() << temp1 << " " << temp2;
    }
    return ans;

}

int Date::DaysTillYourBirthday(Date birthdayDate)
{
    Date temp = birthdayDate;

    if (!IsLeap() && (temp.getMonth() == 2 && temp.getDay() == 29))
    {
        //temp.setMonth(3);
        //temp.setDay(1);
        int nowYear = year;

        if ((month < temp.getMonth()) || (month == temp.getMonth() && day <= temp.getDay()))
        {
            temp.setYear(year);
            int ans = duration(*this, temp);
            return (ans == 366 ? 0 : ans);
        }
        else
        {
            while (!IsLeap(nowYear))
            {
                nowYear++;
                qDebug() << "here";
            }
            temp.setYear(nowYear);
            int ans = duration(*this, temp);
            return (ans == 366 ? 0 : ans);
        }

        /*while (!IsLeap(nowYear))
        {
            nowYear++;
            qDebug() << "here";
        }
        temp.setYear(nowYear);
        int ans = duration(*this, temp);
        return (ans == 366 ? 0 : ans);*/

    }
/*
    if (!IsLeap() && (temp.getMonth() == 2 && temp.getDay() == 29))
    {
        temp.setMonth(3);
        temp.setDay(1);
    }
*/
    if ((month < temp.getMonth()) || (month == temp.getMonth() && day <= temp.getDay()))
    {
        temp.setYear(year);
    }
    else
    {
        temp.setYear(year + 1);
    }
    int ans = duration(*this, temp);
    return (ans == 366 ? 0 : ans);
}

QString Date::DateInStringFormat()
{
    QString ans;
    if (day <= 9) ans.push_back('0');
    ans.push_back(QString::number(day));
    ans.push_back('.');
    if (month <= 9) ans.push_back('0');
    ans.push_back(QString::number(month));
    ans.push_back('.');
    if (year <= 999) ans.push_back('0');
    if (year <= 99) ans.push_back('0');
    if (year <= 9) ans.push_back('0');
    ans.push_back(QString::number(year));
    return ans;
}



