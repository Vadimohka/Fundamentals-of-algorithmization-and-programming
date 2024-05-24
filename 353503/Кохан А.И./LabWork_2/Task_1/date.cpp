#include "date.h"
#include "ConstNumber.h"

Date::Date() : date(QDate::currentDate()), day(date.day()), month(date.month()), year(date.year()) {}

Date::Date(short value_day, short value_month, short value_year) : day(value_day), month(value_month), year(value_year) {}

QString Date::toString() const
{
    QString strDay, strMonth, strYear = QString::number(this->getYear());

    while(strYear.size() < SIZE_STRING_YEAR) {
        strYear.prepend('0');
    }

    if(this->getDay() < FIRST_TWO_DIGIT_NUMBER) {
        strDay = "0" + QString::number(this->getDay());
    }

    else {
        strDay = QString::number(this->getDay());
    }

    if(this->getMonth() < FIRST_TWO_DIGIT_NUMBER) {
        strMonth = "0" + QString::number(this->getMonth());
    }

    else {
        strMonth = QString::number(this->getMonth());
    }

    return strDay + "." + strMonth + "." + strYear;
}

Date Date::fromString(const QString& value)
{
    if(value.size() != FIRST_TWO_DIGIT_NUMBER) {
        return Date(0, 0, 0);
    }

    for (int i = 0; i < FIRST_TWO_DIGIT_NUMBER; ++i) {
        if(i == NUMBER_FIRST_DOT_IN_DATE || i == NUMBER_SECOND_DOT_IN_DATE) {
            continue;
        }

        else if(!value.at(i).isDigit()) {
            return Date(0, 0, 0);
        }
    }

    if(value.at(NUMBER_FIRST_DOT_IN_DATE) == '.' && value.at(NUMBER_SECOND_DOT_IN_DATE) == '.' && value.mid(FIRST_NUMBER_MONTH_IN_DATE,
            SIZE_STRING_MONTH).toInt() > 0 && value.left(SIZE_STRING_DAY).toInt() > 0 && value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt() > 0) {

        if((value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberApril ||
            value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberJune ||
            value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberSeptember ||
            value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberNovember) &&
            value.left(SIZE_STRING_DAY).toInt() <= MAX_DAY30 && value.left(SIZE_STRING_DAY).toInt() > 0)
        {
            return Date(value.left(SIZE_STRING_DAY).toInt(), value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt(),
                        value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt());
        }

        else if(
            (
                value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberJanuary ||
                value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberMarch ||
                value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberMay ||
                value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberJuly ||
                value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberAugust ||
                value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberOctober ||
                value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberDecember) &&
                value.left(SIZE_STRING_DAY).toInt() <= MAX_DAY31 &&
                value.left(SIZE_STRING_DAY).toInt() > 0)
        {
            return Date(value.left(SIZE_STRING_DAY).toInt(), value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt(),
                        value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt());
        }

        else if(value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberFebruary &&
                value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt() % 4 == 0 &&
                value.left(SIZE_STRING_DAY).toInt() <= MAX_DAY29 && value.left(SIZE_STRING_DAY).toInt() > 0)
        {
            return Date(value.left(SIZE_STRING_DAY).toInt(), value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt(),
                        value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt());
        }

        else if(value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberFebruary &&
                value.left(SIZE_STRING_DAY).toInt() <= MAX_DAY28 && value.left(SIZE_STRING_DAY).toInt() > 0)
        {
            return Date(value.left(SIZE_STRING_DAY).toInt(), value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt(),
                        value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt());
        }
    }

    return Date(0, 0, 0);
}

Date Date::nextDay() const
{
    if(this->getDay() == MAX_DAY31 && this->getMonth() == numberDecember) {
        return Date(1, 1, this->getYear() + 1);
    }

    if (this->getDay() == MAX_DAY31) {
        return Date(1, this->getMonth() + 1, this->getYear());
    }

    if (this->getDay() == MAX_DAY30
        && (this->getMonth() == numberApril || this->getMonth() == numberJune
            || this->getMonth() == numberSeptember || this->getMonth() == numberNovember)) {
        return Date(1, this->getMonth() + 1, this->getYear());
    }

    if (this->getDay() == MAX_DAY29 && this->getMonth() == numberFebruary
        && this->getYear() % 4 == 0) {
        return Date(1, this->getMonth() + 1, this->getYear());
    }

    if (this->getDay() == MAX_DAY28 && this->getMonth() == numberFebruary) {
        return Date(1, this->getMonth() + 1, this->getYear());
    }

    return Date(this->getDay() + 1, this->getMonth(), this->getYear());
}

Date Date::previousDay() const
{
    if(this->getDay() == NUMBER_FIRST_DAY && this->getMonth() == numberJanuary) {
        return Date(MAX_DAY31, numberDecember, this->getYear() - 1);
    }

    else if(this->getDay() == NUMBER_FIRST_DAY &&
             (this->getMonth() == numberFebruary ||
              this->getMonth() == numberApril ||
              this->getMonth() == numberJune ||
              this->getMonth() == numberSeptember ||
              this->getMonth() == numberNovember)
             )
    {
        return Date(MAX_DAY31, this->getMonth() - 1, this->getYear());
    }

    else if(this->getDay() == NUMBER_FIRST_DAY &&
             (this->getMonth() == numberMay ||
              this->getMonth() == numberJuly ||
              this->getMonth() == numberOctober ||
              this->getMonth() == numberDecember)
             )
    {
        return Date(MAX_DAY30, this->getMonth() - 1, this->getYear());
    }

    else if(this->getDay() == NUMBER_FIRST_DAY && this->getMonth() == numberMarch && this->getYear() % 4 == 0) {
        return Date(MAX_DAY29, this->getMonth() - 1, this->getYear());
    }

    else if(this->getDay() == NUMBER_FIRST_DAY && this->getMonth() == numberMarch) {
        return Date(MAX_DAY28, this->getMonth() - 1, this->getYear());
    }
    else {
        return Date(this->getDay() - 1, this->getMonth(), this->getYear());
    }
}

int Date::Duration(const Date value_date) const
{
    int deltaYears = 0;

    for(int i = qMin(this->getYear(), value_date.getYear()); i < qMax(this->getYear(), value_date.getYear()); ++i)
    {
        (i % 4 == 0)? deltaYears += MAX_DAY_IN_LEAP_YEAR : deltaYears += MAX_DAY_IN_YEAR;
    }

    if(value_date.getYear() == this->getYear()) {
        return abs(value_date.dayNumber() - this->dayNumber());
    }

    else if(value_date.getYear() > this->getYear()) {
        return deltaYears + value_date.dayNumber() - this->dayNumber();
    }

    else {
        return deltaYears + this->dayNumber() - value_date.dayNumber();
    }
}

short Date::weekNumber() const
{
    QDate tempData;

    tempData.setDate(this->getYear(), this->getMonth(), this->day);

    return tempData.weekNumber();
}

short Date::dayNumber() const
{
    short dayNum = 0;

    for(short i = 1; i <= this->getMonth(); ++i) {
        if(i == this->getMonth()) {
            dayNum += this->getDay();
        }

        else if(i == numberJanuary || i == numberMarch || i == numberMay || i == numberJuly ||
                i == numberAugust || i == numberOctober || i == numberDecember)
        {
            dayNum += MAX_DAY31;
        }

        else if(i == numberApril || i == numberJune || i == numberSeptember || i == numberNovember)
        {
            dayNum += MAX_DAY30;
        }

        else if(i == numberFebruary && this->getYear() % 4 == 0)
        {
            dayNum += MAX_DAY29;
        }

        else
        {
            dayNum += MAX_DAY28;
        }
    }

    return dayNum;
}

short Date::getDay() const
{
    return this->day;
}

short Date::getMonth() const
{
    return this->month;
}

short Date::getYear() const
{
    return this->year;
}

void Date::setDay(const short value)
{
    this->day = value;
}

void Date::setMonth(const short value)
{
    this->month = value;
}

void Date::setYear(const short value)
{
    this->year = value;
}

bool Date::isLeap() const
{
    return (this->getYear() % 4 == 0)? true : false;
}
