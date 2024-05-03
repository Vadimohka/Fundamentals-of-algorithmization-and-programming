#include "courier.h"

courier::courier() {}

courier::courier(std::string numb, std::string nick, short tf, short tt, unsigned long long mw)
{
    number=numb;
    name=nick;
    time_to=tt;
    time_from=tf;
    max_weight=mw;
}

std::string courier::getNumber() const
{
    return number;
}

void courier::setNumber(const std::string &newNumber)
{
    number = newNumber;
}

std::string courier::getName() const
{
    return name;
}

void courier::setName(const std::string &newName)
{
    name = newName;
}

short courier::getTime_to() const
{
    return time_to;
}

void courier::setTime_to(short newTime_to)
{
    time_to = newTime_to;
}

short courier::getTime_from() const
{
    return time_from;
}

void courier::setTime_from(short newTime_from)
{
    time_from = newTime_from;
}

unsigned long long courier::getMax_weight() const
{
    return max_weight;
}

void courier::setMax_weight(unsigned long long newMax_weight)
{
    max_weight = newMax_weight;
}

std::string courier::get_in_string()
{
    std::string s;
    s="["+number + "] " + name + " work "+get_time_from_in_string()+" - "+get_time_to_in_string()+" max weight: "+std::to_string(getMax_weight());
    return s;
}

std::string courier::get_time_to_in_string()
{
    short h=time_to/60,m=time_to%60;
    std::string s="";
    if(h<10)
        s+="0";
    s+=std::to_string(h);
    s+=":";
    if(m<10)
        s+="0";
    s+=std::to_string(m);
    return s;
}

std::string courier::get_time_from_in_string()
{
    short h=time_from/60,m=time_from%60;
    std::string s="";
    if(h<10)
        s+="0";
    s+=std::to_string(h);
    s+=":";
    if(m<10)
        s+="0";
    s+=std::to_string(m);
    return s;
}

std::string courier::get_in_file_format()
{
    std::string s="";//[2] {HIT A.A} 200 800 50
    s="["+number + "] {" + name + "} "+std::to_string(time_from)+" "+std::to_string(time_to)+" "+std::to_string(max_weight);
    return s;
}

bool courier::operator <(courier b)
{
    if(time_to!=b.time_to)
        return b.time_to>time_to;
    if(time_from!=b.time_from) return b.time_from>time_from;
    return b.max_weight>max_weight;
}
