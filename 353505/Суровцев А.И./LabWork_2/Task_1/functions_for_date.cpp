#include "functions_for_date.h"

functions_for_Date::functions_for_Date() {}

void functions_for_Date::add_new_Date(My_Date newDate)
{
    list_of_dates.push_back(newDate);
}

QString functions_for_Date::from_myDate_toString(My_Date date)
{
    return date.toString();
}

QString functions_for_Date::get_Date(int position)
{
    if (position >= 0 and position < list_of_dates.length()) {
        return from_myDate_toString(list_of_dates[position]);
    }
    return "";
}

QString functions_for_Date::get_prev_Date(int position)
{
    My_Date temp = list_of_dates[position];
    if (temp.getDay() == 0 && temp.getMonth() == 0 && temp.getYear() == 0) return "01.00.0000 BC";
    else if (temp.getDay() != 1) temp.addDays(-1);
    else if (temp.getMonth() == 1) temp.setDate(temp.getYear() - 1, 12, temp.DaysInMonth(12, temp.getYear() - 1));
    else temp.setDate(temp.getYear(), temp.getMonth() - 1, temp.DaysInMonth(temp.getMonth() - 1, temp.getYear()));
    return from_myDate_toString(temp);
}

QString functions_for_Date::get_next_Date(int position)
{
    My_Date temp = list_of_dates[position];
    if (temp.getDay() == temp.DaysInMonth(temp.getMonth(), temp.getYear())) {
        if (temp.getMonth() == 12) temp.setDate(temp.getYear() + 1, 1, 1);
        else temp.setDate(temp.getYear(), temp.getMonth() + 1, 1);
    }
    else temp.addDays(1);
    return from_myDate_toString(temp);
}

bool functions_for_Date::isLY(int position)
{
    return list_of_dates[position].isLeapYear(list_of_dates[position].getYear());
}

long long functions_for_Date::daysTo(My_Date endDate, My_Date startDate)
{
    long long endDays =endDate.TotalDays();
    long long startDays = startDate.TotalDays();
    return endDays - startDays;
}

int functions_for_Date::DaysTillYourBithday(My_Date bithdaydate, int position, bool &q)
{
    long long ans = 0;
    if (daysTo(bithdaydate, list_of_dates[position]) >= 0) {
        q = true;
        if (bithdaydate.getDay() == 29 && bithdaydate.getMonth() == 2) {
            while (!list_of_dates[position].isLeapYear(list_of_dates[position].getYear())) {
                list_of_dates[position].setDate(list_of_dates[position].getYear() + 1, list_of_dates[position].getMonth(), list_of_dates[position].getDay());
            }
            ans = daysTo(bithdaydate, list_of_dates[position]);
        }
        else ans = daysTo(bithdaydate, list_of_dates[position]);
    }
    else {
        q = false;
        if (bithdaydate.getDay() == 29 && bithdaydate.getMonth() == 2 && list_of_dates[position].getDay() == 29 && list_of_dates[position].getMonth() == 2) ans = 0;
        else {
            bithdaydate.setDate(list_of_dates[position].getYear(), bithdaydate.getMonth(), bithdaydate.getDay());
            if (bithdaydate.getDay() == 29 && bithdaydate.getMonth() == 2) {
                do {
                    bithdaydate.setDate(bithdaydate.getYear() + 1, bithdaydate.getMonth(), bithdaydate.getDay());
                } while (!bithdaydate.isLeapYear(bithdaydate.getYear()));
                ans = daysTo(bithdaydate, list_of_dates[position]);
            }
            else if (daysTo(bithdaydate, list_of_dates[position]) >= 0) {
                ans = daysTo(bithdaydate, list_of_dates[position]);
            }
            else {
                bithdaydate.setDate(bithdaydate.getYear() + 1, bithdaydate.getMonth(), bithdaydate.getDay());
                ans = daysTo(bithdaydate, list_of_dates[position]);
            }
        }
    }
    return ans;
}
