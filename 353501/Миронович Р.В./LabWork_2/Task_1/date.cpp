#include "date.h"


Date::Date()
{
}

Date::Date(int day, int month, int year)
    : m_day(day), m_month(month), m_year(year)
{

}

Date::Date(std::string date)
{
    std::istringstream iss(date);
    std::string token;
    std::getline(iss, token, '.');
    m_day = std::stoi(token);

    std::getline(iss, token, '.');
    m_month = std::stoi(token);

    std::getline(iss, token);
    m_year = std::stoi(token);
}


Date::~Date()
{

}


int Date::Day()
{
    return m_day;
}

int Date::Month()
{
    return m_month;
}

int Date::Year()
{
    return m_year;
}


int Date::daysInMonth(int month)
{
    short days[12] = {31, static_cast<short>(this->IsLeap() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

bool Date::IsLeap()
{
    if (m_year % 400 == 0) return true;
    else if (m_year % 100 == 0) return false;
    else if (m_year % 4 == 0) return true;

    return false;
}


Date Date::NextDay()
{
    int nextDay = m_day;
    int nextMonth = m_month;
    int nextYear = m_year;

    if (m_day < daysInMonth(m_month))
    {
        nextDay++;
    } else
    {
        nextDay = 1;
        if (m_month < 12)
        {
            nextMonth++;
        } else
        {
            nextMonth = 1;
            nextYear++;
        }
    }

    return Date(nextDay, nextMonth, nextYear);
}


Date Date::PreviousDate()
{
    int previousDay = m_day;
    int previousMonth = m_month;
    int previousYear = m_year;

    if (m_day > 1)
    {
        previousDay--;
    } else
    {
        if (m_month > 1)
        {
            previousMonth--;
            previousDay = daysInMonth(m_month);
        } else
        {
            previousMonth = 12;
            previousDay = 31;
            previousYear--;
        }
    }

    return Date(previousDay, previousMonth, previousYear);
}


short Date::yearCode()
{
    int numberCode[] = {6, 4, 2, 0};

    return (numberCode[(m_year / 100) % 4] + (m_year % 100) + (m_year % 100) / 4) % 7;
}

short Date::monthCode()
{
    if (IsLeap())
    {
        int codes[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
        return codes[m_month - 1];
    } else
    {
        int codes[] = {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
        return codes[m_month - 1];
    }
}

short Date::WeekDay()
{
    return (m_day + monthCode() + yearCode()) % 7;
}

short Date::WeekNumber()
{
    int firstJanuaryWeekDay = Date(1, 1, m_year).WeekDay();

    int dayDiffrence = this->Duration(Date(1, 1, m_year));
    short weekNumber = dayDiffrence / 7 + 1;

    if (this->WeekDay() < firstJanuaryWeekDay) weekNumber++;

    return weekNumber;
}


int Date::Duration(Date secondDate)
{
    return abs(daysSinceFirstYear() - secondDate.daysSinceFirstYear());
}


int Date::DaysTillYourBirthday(Date birthdaydate)
{
    if (this->m_month > birthdaydate.m_month
        || (this->m_month == birthdaydate.m_month && this->m_day > birthdaydate.m_day))
        return this->Duration(Date(birthdaydate.m_day, birthdaydate.m_month, this->m_year + 1));
    return this->Duration(Date(birthdaydate.m_day, birthdaydate.m_month, this->m_year));
}



long long Date::daysSinceFirstYear()
{
    long long daysUntilFisrtJanuary = (m_year - 1) * 365 + (m_year / 4 - 1);

    int daysUntilThisMonth = 0;
    for (int i = 1; i < m_month; ++i) {
        daysUntilThisMonth += daysInMonth(i);
    }

    int daysUntilThisDay = m_day - 1;

    return daysUntilFisrtJanuary + daysUntilThisMonth + daysUntilThisDay;
}


QString Date::Output()
{
    return QString::number(m_day) + "." + QString::number(m_month) + "." + QString::number(m_year);
}

std::string Date::output()
{
    return std::to_string(m_day) + "." + std::to_string(m_month) + "." + std::to_string(m_year);
}
