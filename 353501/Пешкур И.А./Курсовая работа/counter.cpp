#include "counter.h"

Counter::Counter()
{

    days = 0;
    minutes = 0;
    hours = 0;
    seconds = 0;

}

Counter::Counter( int newDays , short newHours , short newMinutes , short newSeconds )
{

    days = newDays;
    hours = newHours;
    minutes = newMinutes;
    seconds = newSeconds;

}

void Counter :: addSecond()
{

    ++ seconds;

    if( seconds == 60 )
    {

        seconds = 0;
        ++ minutes;

    }

    if( minutes == 60 )
    {

        minutes = 0;
        ++ hours;

    }

    if( hours == 24 )
    {

        hours = 0;
        ++ days;

    }

}

int Counter :: getDay()
{

    return days;

}

short Counter :: getHour()
{

    return hours;

}

short Counter :: getMinutes()
{

    return minutes;

}

short Counter :: getSeconds()
{

    return seconds;

}


