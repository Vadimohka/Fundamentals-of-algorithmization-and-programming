#include "date.h"

Date::Date(){}

long long Date :: getDateDay()
{

    return Day;

}

long long Date :: getDateMonth()
{

    return Month;

}

long long Date :: getDateYear()
{

    return Year;

}

void Date :: setValue( long long newDay , long long newMonth , long long newYear )
{

    Day = newDay;
    Month = newMonth;
    Year = newYear;

}

long long Date :: getDifference( Date secondDate , bool IsBirthDay )
{

    long long Day1 = getDateDay(), Day2 = secondDate.getDateDay(), Month1 = getDateMonth(), Month2 = secondDate.getDateMonth(), Year1 = getDateYear(), Year2 = secondDate.getDateYear();

    long long Result = 0;

    if( IsBirthDay )
    {

        Year1 = 0;
        Year2 = 0;

    }

    if( Year1 > Year2 )
    {

        std :: swap( Year1 , Year2 );
        std :: swap( Month1 , Month2 );
        std :: swap( Day1 , Day2 );

    }else if( Year1 == Year2 ){

        if( Month1 > Month2 )
        {

            std :: swap( Month1 , Month2 );
            std :: swap( Day1 , Day2 );

        }else if( Month1 == Month2 ){

            return abs( Day1 - Day2 );

        }

        if( Month1 % 2 == 1 )
            Result += 31 - Day1;
        else if( Month1 != 2 )
            Result += 30 - Day1;
        else if( Year1 % 4 == 0 )
            Result += 29 - Day1;
        else
            Result += 28 - Day1;

        Result += Day2;

        ++ Month1;

        while( Month1 != Month2 )
        {

            if( Month1 % 2 == 1 )
                Result += 31;
            else if( Month1 != 2 )
                Result += 30;
            else if( Year1 % 4 == 0 )
                Result += 29;
            else
                Result += 28;

            ++ Month1;

        }

        return Result;

    }

    if( Month1 % 2 == 1 )
        Result += 31 - Day1;
    else if( Month1 != 2 )
        Result += 30 - Day1;
    else if( Year1 % 4 == 0 )
        Result += 29 - Day1;
    else
        Result += 28 - Day1;
    Result += Day2;

    ++ Month1;

    while( Month1 != 13 )
    {

        if( Month1 % 2 == 1 )
            Result += 31;
        else if( Month1 != 2 )
            Result += 30;
        else if( Year1 % 4 == 0 )
            Result += 29;
        else
            Result += 28;

        ++ Month1;

    }

    -- Month2;

    while( Month2 != 0 )
    {

        if( Month2 % 2 == 1 )
            Result += 31;
        else if( Month2 != 2 )
            Result += 30;
        else if( Year2 % 4 == 0 )
            Result += 29;
        else
            Result += 28;

        -- Month2;

    }

    ++ Year1;

    while( Year1 != Year2 )
    {

        if( Year1 % 4 == 0 )
            Result += 366;
        else
            Result += 365;

        ++ Year1;

    }

    if( IsBirthDay && ( ( getDateMonth() > secondDate.getDateMonth() ) || ( getDateDay() == secondDate.getDateMonth() && getDateDay() == secondDate.getDateDay() ) ) )
        Result = 365 - Result;


    return Result;

}

Date Date :: getPreviusDate()
{

    long long FDay = Day, FMonth = Month, FYear = Year;

    -- Day;

    if( Day == 0 )
    {

        if( Month % 2 == 1 )
            Day += 31;
        else if( Month != 2 )
            Day += 30;
        else if( Year % 4 == 4 )
            Day += 29;
        else
            Day += 28;

        -- Month;

        if( Month == 0 )
        {

            Month += 12;
            -- Year;

        }

    }

    Date prevDate;

    if( FDay == 1 && FMonth == 1 && FYear == 1 )
        prevDate.setValue( FDay , FMonth , FYear );
    else
        prevDate.setValue( Day , Month , Year );

    Day = FDay;
    Month = FMonth;
    Year = FYear;

    return prevDate;

}

Date Date :: getNextDate()
{

    long long FDay = Day, FMonth = Month, FYear = Year;

    ++ Day;

    if( Month % 2 == 1 && Day == 32 )
    {

        Day = 1;
        ++ Month;

    }else if( Month != 2 && Day == 31 ){

        Day = 1;
        ++ Month;

    }else if( Year % 4 == 4 && Day == 30 ){

        Day = 1;
        ++ Month;

    }else if( Month == 2 && Day == 29 ){

        Day = 1;
        ++ Month;

    }

    if( Month == 13 )
    {

        Month = 1;
        ++ Year;

    }

    Date nextDate;

    if( FDay == 30 && FMonth == 12 && FYear == 9999 )
        nextDate.setValue( FDay , FMonth , FYear );
    else
        nextDate.setValue( Day , Month , Year );

    Day = FDay;
    Month = FMonth;
    Year = FYear;

    return nextDate;

}

QString Date :: IsLeap()
{

    if( getDateYear() % 4 )
        return "NO";
    return "YES";

}
