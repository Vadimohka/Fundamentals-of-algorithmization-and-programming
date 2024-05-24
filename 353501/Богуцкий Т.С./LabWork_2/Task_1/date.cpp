#include "date.h"

Date::Date()
{


}

bool Date::isLeap()
{
    if (year % 4 == 0) return true;
    else return false;
}

long Date::WeekNumber()
{
    int number = 0, res = 0;

    if (year % 4 == 0)
    {
        for (int i = 1; i <= month; i++)
        {
            if (i != 1)
            {
                number += month_vis_amount_days[i];
            }
        }
    }

    else
    {
        for (int i = 1; i <= month; i++)
        {
            if (i != 1)
            {
                number += month_amount_days[i];
            }
        }
    }

    number += day;

    if (number % 7 != 0) res = number/7 +1;
    else res = number/7;

    return res;
}

QString Date::NextDay()
{
    QString str;
    if (isLeap())
    {
        if (day == month_vis_amount_days[month])
        {
            if (month == 12) str =  "01.01." + is_0_neaded(year, true) + QString::number(year+1);
            else
            {
                str = "01." + is_0_neaded(month, true) + QString::number(month+1) +"."+ is_0_neaded(year, false) +QString::number(year);
            }
        }
        else str =  is_0_neaded(day, true) + QString::number(day+1) + "." + is_0_neaded(month, false) + QString::number(month) + "." + is_0_neaded(year, false) + QString::number(year);

    }

    else
    {
       if (day == month_amount_days[month])
       {
           if (month == 12) str =  "01.01." + is_0_neaded(year, true) + QString::number(year+1);
           else str = "01." + is_0_neaded(month, true) + QString::number(month+1) + "." + is_0_neaded(year, false) + QString::number(year);
       }
       else str =  is_0_neaded(day, true) + QString::number(day+1) + "." + is_0_neaded(month, false) + QString::number(month) + "." + is_0_neaded(year, false) + QString::number(year);
    }

    return str;
}

QString Date::PreviousDay()
{
    QString str;

    if (day == 1 and month == 1)
    {
        str = "31.12.";
        str += (year-1) <= 9?"0":"";
        str += QString::number(year - 1);
    }
    else if (day == 1)
    {
        if (isLeap())
        {
            int help = month_vis_amount_days[month - 1];
            str = QString::number(help) + ".";
            str += (month-1)<=9?"0":"";
            str += QString::number(month - 1) + "." + is_0_neaded(year, false) + QString::number(year);
        }
        else
        {
            int helper = month_amount_days[month -1];
            str = QString::number(helper) + ".";
            str += (month-1)<=9?"0":"";
            str += QString::number(month - 1) + "." + is_0_neaded(year, false) + QString::number(year);
        }

    }
    else
    {
        str = (day-1)<=9?"0":"";
        str += QString::number(day-1) + "." + is_0_neaded(month, false) + QString::number(month) + "." + is_0_neaded(year, false) + QString::number(year);
    }
    return str;
}

//надо посчитать количество всех дней в текущей дате

int Date::DaysTillYourBirthday(Date birthdaydate)
{
    int counter_birthday = 0, counter_current_date = 0, res = 0;

    // подсчет дней в дате дня рождения

    if (current_year % 4 == 0)
    {
        for (int i = 1; i <= birthdaydate.month; i++){
            counter_birthday += month_vis_amount_days[i];
        }
    }
    else
    {
        for (int i = 1; i <= birthdaydate.month; i++){
            counter_birthday += month_amount_days[i];
        }
    }

    counter_birthday += birthdaydate.day;

    // подсчет дней в текущей дате

    if (current_year % 4 == 0)
    {
        for (int i = 1; i <= current_month; i++){
            counter_current_date += month_vis_amount_days[i];
        }
    }
    else
    {
        for (int i = 1; i <= current_month; i++){
            counter_current_date += month_amount_days[i];
        }
    }

    counter_current_date += current_day;

    // количество дней до дня рождения

    if (counter_birthday > counter_current_date) res = counter_birthday - counter_current_date;
    else
    {
        if (current_year % 4 == 0) res = 366 - counter_current_date + counter_birthday;
        else res = 365 - counter_current_date + counter_birthday;
    }

    return res;
}

int Date::Duration(Date date, Date date2)
{
    int counter_birthday = 0, counter_current_date = 0, res = 0;

    if (current_year % 4 == 0)
    {
        for (int i = 1; i <= date.month; i++){
            counter_birthday += month_vis_amount_days[i];
        }
    }
    else
    {
        for (int i = 1; i <= date.month; i++){
            counter_birthday += month_amount_days[i];
        }
    }

    counter_birthday += date.day;

    int chislo_let = date.year;
    for (int i = 0; i < date.year; i++)
    {
        if (chislo_let % 4 == 0){
            counter_birthday += 366;
            chislo_let--;
        }
        else
        {
          counter_birthday += 365;
          chislo_let--;
        }
    }


    // подсчет дней в текущей дате

    if (current_year % 4 == 0)
    {
        for (int i = 1; i <= date2.month; i++){
            counter_current_date += month_vis_amount_days[i];
        }
    }
    else
    {
        for (int i = 1; i <= date2.month; i++){
            counter_current_date += month_amount_days[i];
        }
    }

    counter_current_date += date2.day;

    int chislo_let_current = date2.year;
    for (int i = 0; i < date2.year; i++)
    {
        if (chislo_let_current % 4 == 0){
            counter_current_date += 366;
            chislo_let_current--;
        }
        else
        {
          counter_current_date += 365;
          chislo_let_current--;
        }
    }

    // количество дней до даты

    if (counter_birthday > counter_current_date) res = counter_birthday - counter_current_date;
    else res = counter_birthday - counter_current_date;

    return res;
}

void Date::getDate(QString str, int *day_from_date, int *month_from_date, int *year_from_date)
{
    QString help_string;
    int counter_tochek = 0;
    str +=".";

    for(QString helper: str)
    {
        if (helper !="."){
            help_string += helper;
        }

        else
        {
            counter_tochek++;
            if (counter_tochek == 1)
            {
                if (!help_string.isEmpty())
                    *day_from_date = help_string.toInt();
            }
            else if (counter_tochek == 2)
            {
                if (!help_string.isEmpty())
                    *month_from_date = help_string.toInt();
            }
            else
            {
                if (!help_string.isEmpty())
                    *year_from_date = help_string.toInt();
            }
            help_string.clear();
        }
    }
}

QString Date::is_0_neaded(int num, bool plus)
{
    QString str;
    if(plus)
    {
        if (num+1 >0 && num+1 <=9) str ="0";
        else str = "";
    }
    else
    {
        if (num >0 && num <=9) str ="0";
        else str = "";
    }

    return str;
}
