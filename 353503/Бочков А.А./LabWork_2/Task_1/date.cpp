#include "date.h"

Date::Date() = default;

Date::Date(QString newDate) {
    if (newDate.size() != dateSize) {
        //date = "00.00.0000";
        //day=0;month=0;year=0;
        //form.show();
        error = true;
    } else {
        if (newDate.mid(2, 1) != "." || newDate.mid(five, 1) != ".") {
            //qDebug() << 1;
            //date = "00.00.0000";
            //day=0;month=0;year=0;
            //form.show();
            error = true;
        } else {
            date = newDate;
            QString strday;
            QString strmonth;
            QString stryear;
            strday = newDate.mid(0,2);
            strmonth = newDate.mid(3,2);
            stryear = newDate.mid(six, 4);
            bool ok = false;
            day = strday.toInt(&ok, ten);
            month = strmonth.toInt(&ok, ten);
            year = stryear.toInt(&ok, ten);
            if (!ok) {
                //qDebug() << 2;
                //date = "00.00.0000";
                //day=0;month=0;year=0;
                //form.show();
                error = true;
            } else {
                if (!QDate::isValid(year,month,day)) {
                    //qDebug() << day << month << year;
                    //date = "00.00.0000";
                    //day=0;month=0;year=0;
                    //form.show();
                    error = true;
                }
            }
        }
    }
    //qDebug() << strday << strmonth << stryear;
}

Date Date::NextDay()
{
    QString answ = "";
    int dday=day,mmonth=month,yyear=year;
    if (day < n28) {
        day++;
        if (day < ten) {
            answ+="0";
        }
        answ+=QString::number(day)+'.';
        if (month < ten) {
            answ+="0";
        }
        answ+=QString::number(month)+'.';
        if (year < thousand) {
            answ+="0";
        }
        if (year < hundred) {
            answ+="0";
        }
        if (year < ten) {
            answ+="0";
        }
        answ+=QString::number(year);
        Date ans(answ);{
            //date = "00.00.0000";
            //day=0;month=0;year=0;
        }
        day=dday;month=mmonth;year=yyear;
        return ans;
    }
    if (day == n28) {
        if (month==2 && !isLeap(year)) {
            day=1;
            month++;
        } else {
            day++;
        }
        if (day < ten) {
            answ+="0";
        }
        answ+=QString::number(day)+'.';
        if (month < ten) {
            answ+="0";
        }
        answ+=QString::number(month)+'.';
        if (year < thousand) {
            answ+="0";
        }
        if (year < hundred) {
            answ+="0";
        }
        if (year < ten) {
            answ+="0";
        }
        answ+=QString::number(year);
        Date ans(answ);
        day=dday;month=mmonth;year=yyear;
        return ans;
    }
    if (day == n29) {
        if (month==2 && isLeap(year)) {
            day=1;
            month++;
        } else {
            day++;
        }
        if (day < ten) {
            answ+="0";
        }
        answ+=QString::number(day)+'.';
        if (month < ten) {
            answ+="0";
        }
        answ+=QString::number(month)+'.';
        if (year < thousand) {
            answ+="0";
        }
        if (year < hundred) {
            answ+="0";
        }
        if (year < ten) {
            answ+="0";
        }
        answ+=QString::number(year);
        Date ans(answ);
        day=dday;month=mmonth;year=yyear;
        return ans;
    }
    if (day == n30) {
        if (month == 1 || month == 3 || month == five || month == seven || month == eight
            || month == ten || month == n12) {
            day++;
        } else {
            day = 1;
            month++;
        }
        if (day < ten) {
            answ+="0";
        }
        answ+=QString::number(day)+'.';
        if (month < ten) {
            answ+="0";
        }
        answ+=QString::number(month)+'.';
        if (year < thousand) {
            answ+="0";
        }
        if (year < hundred) {
            answ+="0";
        }
        if (year < ten) {
            answ+="0";
        }
        answ+=QString::number(year);
        Date ans(answ);
        day=dday;month=mmonth;year=yyear;
        return ans;
    }
    if (day == n31) {
        day=1;
        if (month == n12) {
            month=1;
            year++;
        } else {
            month++;
        }
        if (day < ten) {
            answ+="0";
        }
        answ+=QString::number(day)+'.';
        if (month < ten) {
            answ+="0";
        }
        answ+=QString::number(month)+'.';
        if (year < thousand) {
            answ+="0";
        }
        if (year < hundred) {
            answ+="0";
        }
        if (year < ten) {
            answ+="0";
        }
        answ+=QString::number(year);
        Date ans(answ);
        day=dday;month=mmonth;year=yyear;
        return ans;
    }
    Date ans(answ);
    return ans;
}

Date Date::PreviousDay()
{
    QString answ = "";
    int dday=day,mmonth=month,yyear=year;
    if (day==1) {
        if (month==1) {
            day = n31;
            month = n12;
            year--;
            if (day < ten) {
                answ+="0";
            }
            answ+=QString::number(day)+'.';
            if (month < ten) {
                answ+="0";
            }
            answ+=QString::number(month)+'.';
            if (year < thousand) {
                answ+="0";
            }
            if (year < hundred) {
                answ+="0";
            }
            if (year < ten) {
                answ+="0";
            }
            answ+=QString::number(year);
            qDebug() << answ;
            Date ans(answ);
            day=dday;month=mmonth;year=yyear;
            return ans;
        }
        month--;
        if (month == 1 || month == 3 || month == five || month == seven || month == eight
            || month == ten) {
            day = n31;
        } else {
            if (month==2) {
                if (isLeap(year)) {
                    day = n29;
                } else {
                    day = n28;
                }
            } else {
                day = n30;
            }
        }
    } else {
        day--;
    }
    if (day < ten) {
        answ+="0";
    }
    answ+=QString::number(day)+'.';
    if (month < ten) {
        answ+="0";
    }
    answ+=QString::number(month)+'.';
    if (year < thousand) {
        answ+="0";
    }
    if (year < hundred) {
        answ+="0";
    }
    if (year < ten) {
        answ+="0";
    }
    answ+=QString::number(year);
    qDebug() << answ;
    Date ans(answ);
    day=dday;month=mmonth;year=yyear;
    return ans;
}

bool Date::isLeap(int checkYear)
{
    if (checkYear % 4 == 0 && (checkYear % hundred != 0 || checkYear % hundred4 == 0)) {
        return true;
    }
    return false;
}

int16_t Date::WeekNumber()
{
    //qDebug() << day << month<< year;
    return (DateInDays(day, month, year) - DateInDays(1, 1, year)) / seven + 1;
}

int Date::DaysTillYourBirthday(Date birthdaydate)
{
    int duration = DateInDays(birthdaydate.day,birthdaydate.month,year)-DateInDays(day,month,year);
    if (duration < 0 || (birthdaydate.day == n29 && birthdaydate.month == 2 && !isLeap(year))) {
        if (birthdaydate.day == n29 && birthdaydate.month == 2) {
            birthdaydate.year = year+1;
            while (!isLeap(birthdaydate.year)) {
                birthdaydate.year++;
            }
            //qDebug() << birthdaydate.year;
            return DateInDays(birthdaydate.day,birthdaydate.month,birthdaydate.year)-DateInDays(day,month,year);
        }
        return DateInDays(birthdaydate.day,birthdaydate.month,year+1)-DateInDays(day,month,year);
    }
    return duration;
}

int Date::Duration(Date date)
{
    return abs(DateInDays(date.day,date.month,date.year)-DateInDays(day,month,year));
}

int Date::DateInDays(int day, int month, int year)
{
    year--;
    int ans = year * n365 + year / 4 - year / hundred + year / hundred4;
    year++;
    switch (month)
    {
    case 2:
    {
        ans += n31;
        break;
    }
    case 3:
    {
        ans += n59;
        break;
    }
    case 4:
    {
        ans += n90;
        break;
    }
    case five: {
        ans += n120;
        break;
    }
    case six: {
        ans += n151;
        break;
    }
    case seven: {
        ans += n181;
        break;
    }
    case eight: {
        ans += n212;
        break;
    }
    case nine: {
        ans += n243;
        break;
    }
    case ten: {
        ans += n273;
        break;
    }
    case n11: {
        ans += n304;
        break;
    }
    case n12: {
        ans += n334;
        break;
    }
    default:
        break;
    }
    if (month > 2 && year % 4 == 0 && (year % hundred != 0 || year % hundred4 == 0)) {
        ans++;
    }
    ans += day;
    return ans;
}
