#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
public:
    Counter();
    Counter( int newDays , short newHours , short newMinutes , short newSeconds );
    void addSecond();
    int getDay();
    short getHour();
    short getMinutes();
    short getSeconds();

private:
    int days;
    short hours;
    short minutes;
    short seconds;

};

#endif // COUNTER_H
