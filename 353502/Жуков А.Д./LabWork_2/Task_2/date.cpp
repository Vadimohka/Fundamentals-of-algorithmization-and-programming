#include "date.h"
#include <QDebug>
#include <utility>

enum numbers {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE};
constexpr int MONTH_30 = 30;
constexpr int MONTH_31 = 31;
constexpr int FEB_28 = 28;
constexpr int FEB_29 = 29;
constexpr int YEAR_100 = 100;
constexpr int YEAR_400 = 400;
constexpr int LAST_YEAR = 9999;
constexpr int YEAR_DAYS = 365;
constexpr int YEAR_DAYS_LEAP = 366;
constexpr int YEAR_OFFSET = 1900;

qint16 Date::getMonth() { return month; }

qint16 Date::getDay() {  return day; }

qint16 Date::getYear() { return year; }

Date::Date(QString d)
    : date(std::move(d))
    , day(date.mid(ZERO, TWO).toInt())
    , month(date.mid(THREE, TWO).toInt())
    , year(date.mid(SIX, FOUR).toInt())
{}

Date::Date(qint16 d, qint16 m, qint16 y)
    : day(d)
    , month(m)
    , year(y)
{
    QString sDay = QString::number(day);
    QString sMonth = QString::number(month);
    QString sYear = QString::number(year);

    while (sYear.length() < FOUR)
    {
        sYear = "0" + sYear;
    }

    date.clear();
    date += (sDay.length() == ONE ? "0" : "") + sDay + "." + (sMonth.length() == ONE ? "0" : "") + sMonth + "." + sYear;
}

bool Date::isLeapYear()
{
    return {(year % FOUR == ZERO) && (year % YEAR_100 != ZERO) || (year % YEAR_400 == ZERO)};
}

qint16 Date::WeekNumber()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    qint16 daysInYear = now->tm_yday, dayInWeek = now->tm_wday;
    qint16 WNum = qCeil((daysInYear - dayInWeek) / SEVEN) + ONE;
    return WNum;
}

Date* Date::NextDay()
{
    qint16 day = this->day, month = this->month, year = this->year;
    day++;

    qint16 isLeapFebr = isLeapYear() ? FEB_29 : FEB_28;

    if (date == "MONTH_31.12.9999")
    {
        day--;
        return new Date("-");
    }
    else if ((this->month == TWO && day == isLeapFebr + ONE)
               || ((month == FOUR || month == SIX || month == NINE || month == ELEVEN) && day == MONTH_30 + ONE)
               || ((month == ONE || month == THREE || month == FIVE || month == SEVEN || month == EIGHT || month == TEN || month == TWELVE) && day == MONTH_31 + 2))
    {
        day = ONE;
        month++;
        if (month == TWELVE + ONE)
        {
            month = ONE;
            year++;
        }
    }

    return new Date(day, month, year);
}

Date *Date::PreviousDay()
{
    qint16 day = this->day, month = this->month, year = this->year;
    day--;

    qint16 isLeapFebr = isLeapYear() ? FEB_29 : FEB_28;

    if (date == "01.01.0001")
    {
        day++;
        return new Date("-");
    }
    else if (this->month == THREE && day == ZERO)
    {
        day = isLeapFebr;
        month--;
    }
    else if ((month == FOUR || month == SIX || month == NINE || month == ELEVEN || month == TWO) && day == ZERO)
    {
        day = MONTH_31;
        month--;
    }
    else if ((month == ONE || month == FIVE || month == SEVEN || month == EIGHT || month == TEN || month == TWELVE) && day == ZERO)
    {
        month--;
        if (month == ZERO)
        {
            month = TWELVE;
            day = MONTH_31;
            year--;
        }
        else
        {
            day = MONTH_30;
        }
    }

    return new Date(day, month, year);
}

QString Date::ToStr() { return date; }

bool Date::CheckFormat(QString input)
{
    try
    {
        qint16 day = input.mid(ZERO, TWO).toInt();
        qint16 month = input.mid(THREE, TWO).toInt();
        qint16 year = input.mid(SIX, FOUR).toInt();

        if (input.length() != TEN || input[TWO] != '.' || input[FIVE] != '.'
            || year > LAST_YEAR || year < ONE || month > 12 || month < ONE || day < ONE
            || (month == FOUR || month == SIX || month == NINE || month == ELEVEN ? day > MONTH_30 : month ==  ? (Date(day, month, year).isLeapYear() ? day > FEB_29 : day > FEB_28) : day > MONTH_31))
        {
            return false;
        }
    }
    catch(QString & ex)
    {
        qDebug() << ex;
        return false;
    }
    return true;
}

int Date::DaysTillYourBithday(Date bithdayDate)
{
    int quantityOfDaysNow = ZERO;
    int quantityOfDaysBithday = ZERO;
    int deltaNowAndBithday = -ONE;

    std::time_t todayTime = std::time(nullptr);
    std::tm *quantityOfDays = std::localtime(&todayTime);
    quantityOfDaysNow = quantityOfDays->tm_yday;

    for (int i = ONE; i < bithdayDate.getMonth(); ++i)
    {
        if (i == 2)
        {
            quantityOfDaysBithday += bithdayDate.isLeapYear() ? FEB_29 : FEB_28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            quantityOfDaysBithday += MONTH_30;
        }
        else
        {
            quantityOfDaysBithday += MONTH_31;
        }
    }

    quantityOfDaysBithday += bithdayDate.getDay(); // кол-во дней с начала года ближайшего др

    if (quantityOfDaysNow <= quantityOfDaysBithday)
    {
        deltaNowAndBithday = quantityOfDaysBithday-quantityOfDaysNow;
    }
    else
    {
        //int year = quantityOfDays->tm_year + 1900;
        if (bithdayDate.isLeapYear() == 0)
        {
            deltaNowAndBithday = YEAR_DAYS + ONE + quantityOfDaysBithday - quantityOfDaysNow; //хз
        }
        else
        {
            deltaNowAndBithday = 364 + quantityOfDaysBithday - quantityOfDaysNow; //хз
        }
    }

    return deltaNowAndBithday;
}

int Date::DaysBetweenDates(Date firstDate, Date secondDate)
{
    int daysInMonth = ZERO;
    int daysInYear = ZERO;

    for (int i = ONE; i < firstDate.getMonth(); ++i)
    {
        if (i == 2)
        {
            daysInMonth += firstDate.isLeapYear() == 0 ? FEB_29 : FEB_28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            daysInMonth += MONTH_30;
        }
        else
        {
            daysInMonth += MONTH_31;
        }
    }

    daysInYear = (firstDate.getYear() - ONE) * YEAR_DAYS + (firstDate.getYear() - ONE) / 4 + (firstDate.getYear() - ONE) / YEAR_400 - (firstDate.getYear() - ONE) / YEAR_100;

    int firstDateTotalDays = firstDate.getDay() + daysInMonth + daysInYear;

    daysInMonth = 0;
    daysInYear = 0;

    for (int i = ONE; i < secondDate.getMonth(); ++i)
    {
        if (i == 2)
        {
            daysInMonth += secondDate.isLeapYear() ? FEB_29 : FEB_28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            daysInMonth += MONTH_30;
        }
        else
        {
            daysInMonth += MONTH_31;
        }
    }

    daysInYear = (secondDate.getYear() - ONE) * YEAR_DAYS
                 + (secondDate.getYear() - ONE) / FOUR
                 - (secondDate.getYear() - ONE) / YEAR_100
                 + (secondDate.getYear() - ONE) / YEAR_400;

    int secondDateTotalDays = secondDate.getDay() + daysInMonth + daysInYear;

    return qAbs(firstDateTotalDays - secondDateTotalDays);
}

int Date::DaysBetweenDates(Date firstDate)
{
    int daysInMonth = ZERO;
    int daysInYear = ZERO;

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    for (int i = ONE; i < firstDate.getMonth(); ++i)
    {
        if (i == 2)
        {
            daysInMonth += firstDate.isLeapYear() ? FEB_29 : FEB_28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            daysInMonth += MONTH_30;
        }
        else
        {
            daysInMonth += MONTH_31;
        }
    }

    daysInYear = (firstDate.getYear() - ONE) * YEAR_DAYS
                 + (firstDate.getYear() - ONE) / FOUR
                 + (firstDate.getYear() - ONE) / YEAR_400 - (firstDate.getYear() - ONE) / YEAR_100;

    int firstDateTotalDays = firstDate.getDay() + daysInMonth + daysInYear;
    int currentDateTotalDays = now->tm_yday
                               + (now->tm_year + YEAR_OFFSET - ONE) * YEAR_DAYS
                               + (now->tm_year + YEAR_OFFSET - ONE) / FOUR
                               + (now->tm_year + YEAR_OFFSET - ONE) / YEAR_400
                               - (now->tm_year + YEAR_OFFSET - ONE) / YEAR_100;

    //qDebug() << firstDateTotalDays << now->tm_year;

    return qAbs(firstDateTotalDays - currentDateTotalDays);
}
