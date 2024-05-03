#include "date.h"

Date::Date() : day(1), month(1), year(0)
{

}

Date::~Date() = default;

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{

}

void Date::setDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

std::tuple<int, int, int> Date::getDate()
{
    return { this->day, this->month, this->year };
}

Date Date::NextDate()
{
    Date answer(day, month, year);
    answer.day++;
    bool isYearBissextus = (answer.year % 4 == 0 && (!answer.year % CONSTANT_FOR_BISSEXTUS == 0 || answer.year % 4 * CONSTANT_FOR_BISSEXTUS == 0));

    if (answer.month == 2)
    {
        if (isYearBissextus)
        {
            if (answer.day > NUMBER_OF_DAYS_IN_FEBRUARY + 1)
            {
                answer.day = 1;
                answer.month++;
            }
        }
        else
        {
            if (answer.day > NUMBER_OF_DAYS_IN_FEBRUARY)
            {
                answer.day = 1;
                answer.month++;
            }
        }
    }
    else if (answer.month <= MIDDLE_OF_YEAR_IN_MONTHS)
    {
        if (answer.month % 2 == 1)
        {
            if (answer.day > NUMBER_OF_DAYS_IN_BIGGER_MONTHS)
            {
                answer.day = 1;
                answer.month++;
            }
        }
        else
        {
            if (answer.day > NUMBER_OF_DAYS_IN_SMALLER_MONTHS)
            {
                answer.day = 1;
                answer.month++;
            }
        }
    }
    else
    {
        if (answer.month % 2 == 0)
        {
            if (answer.day > NUMBER_OF_DAYS_IN_BIGGER_MONTHS)
            {
                answer.day = 1;
                answer.month++;
            }
        }
        else
        {
            if (answer.day > NUMBER_OF_DAYS_IN_SMALLER_MONTHS)
            {
                answer.day = 1;
                answer.month++;
            }
        }
    }

    if (answer.month > NUMBER_OF_MONTHS_IN_YEAR)
    {
        answer.month=1;
        answer.year++;
    }

    return answer;
}

Date Date::PreviousDate()
{
    Date answer(day, month, year);
    answer.day--;
    bool isYearBissextus = (answer.year % 4 == 0 && (!answer.year % CONSTANT_FOR_BISSEXTUS == 0 || answer.year % 4 * CONSTANT_FOR_BISSEXTUS == 0));

    if (answer.day < 1)
    {
        answer.month--;
        if (answer.month < 1)
        {
            answer.month = NUMBER_OF_MONTHS_IN_YEAR;
            answer.year--;
        }

        if (answer.month == 2)
        {
            if (isYearBissextus)
            {
                answer.day = NUMBER_OF_DAYS_IN_FEBRUARY + 1;
            }
            else
            {
                answer.day = NUMBER_OF_DAYS_IN_FEBRUARY;
            }
        }
        else if (answer.month <= MIDDLE_OF_YEAR_IN_MONTHS)
        {
            if (answer.month % 2 == 1)
            {
                answer.day = NUMBER_OF_DAYS_IN_BIGGER_MONTHS;
            }
            else
            {
                answer.day = NUMBER_OF_DAYS_IN_SMALLER_MONTHS;
            }
        }
        else
        {
            if (answer.month % 2 == 0)
            {
                answer.day = NUMBER_OF_DAYS_IN_BIGGER_MONTHS;
            }
            else
            {
                answer.day = NUMBER_OF_DAYS_IN_SMALLER_MONTHS;
            }
        }
    }

    return answer;
}

int Date::Duration(Date date)
{
    int answer = 0;
    if (date.year > this->year || (date.year == this->year && date.month > this->month) || (date.year == this->year && date.month == this->month && date.day > this->day))
    {
        while (date.year != this->year || date.month != this->month || date.day != this->day)
        {
            date = date.PreviousDate();
            answer++;
        }
    }
    else
    {
        while (date.year != this->year || date.month != this->month || date.day != this->day)
        {
            date = date.NextDate();
            answer++;
        }
    }

    return answer;
}

int Date::DaysTillYourBirthday(Date birthdayDate)
{
    int answer = 0;

    Date currDate(*this);

    while (birthdayDate.month != currDate.month || birthdayDate.day != currDate.day)
    {
        currDate = currDate.NextDate();
        answer++;
    }

    return answer;
}

void Date::SetInstanceFromQString(QString object)
{
    this->day = object.mid(POSITION_FOR_DAY, 2).toInt();
    if (this->day == 0)
    {
        this->day = 1;
    }
    this->month = object.mid(POSITION_FOR_MONTH, 2).toInt();
    if (this->month == 0)
    {
        this->month = 1;
    }
    this->year = object.mid(POSITION_FOR_YEAR, 4).toInt();
}

QString Date::ToQString()
{
    QString answer = "";

    if (day < LOWEST_TWO_DIGIT_NUMBER)
    {
        answer.append('0');
    }
    answer.append(QString::number(day));
    answer.append('.');
    if (month < LOWEST_TWO_DIGIT_NUMBER)
    {
        answer.append('0');
    }
    answer.append(QString::number(month));
    answer.append('.');
    answer.append(QString::number(year));

    return answer;
}

