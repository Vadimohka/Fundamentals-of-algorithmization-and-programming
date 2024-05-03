#include "data.h"



Data::Data(short int d, short int m, unsigned long long y)
{
    day=d;
    month=m;
    year=y;
}


Data::Data()
{
    day=-1;
    month=-1;
    year=-8;
}


bool Data::Init(std::string s)
{
    //qDebug()<<"Try init:"<<s;
    if(s.size()<6||s[2]!='.'||s[5]!='.')
        return false;

    int siz=s.size();
    for(int i=0;i<siz;++i)
    {
        if(i==2||i==5)continue;
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    day=(s[0]-'0')*10+s[1]-'0';
    month=(s[3]-'0')*10+s[4]-'0';
    /*
    if(s.back()=='C')
        year=stoll(s.substr(6,s.size()-8))*(-1);
    else
*/

    if(s.size()-7>4)return false;
    year=stoull(s.substr(6));

    //qDebug()<<year;
    if(day==0||month==0||month>12||day>Days(month))
        return false;//day=month=year=-8888;
    return true;
}


std::string Data::get()
{
    std::string g="00.00.";
    long long x=day;
    short int i=1;

    while(x!=0)
    {
        g[i]=(char)(x%10)+'0';
        x/=10;
        i--;
    }
    //qDebug()<<g;

    x=month;
    i=4;
    while(x!=0)
    {
        g[i]=(char)(x%10)+'0';
        x/=10;
        i--;
    }
/*
    if(year<0)
        year*=(-1),g+=std::to_string(year),g+="BC";
    else
*/
    //qDebug()<<g;
    g+=std::to_string(year);
    //qDebug()<<year;
    //qDebug()<<g;
    return g;
}

Data Data::NextDay()
{
    Data Next={day,month,year};
    Next.day++;
    if(Next.day>Days(Next.month))
        Next.month++,Next.day=1;
    if(Next.month>12)
        Next.year++,Next.month=1;
    return Next;
}


std::string Data::Data_to_string(Data a)
{
    std::string g="00.00.";
    long long x=a.day;
    short int i=1;

    while(x!=0)
    {
        g[i]=(char)(x%10)+'0';
        x/=10;
        i--;
    }

    x=a.month;
    i=4;
    while(x!=0)
    {
        g[i]=(char)(x%10)+'0';
        x/=10;
        i--;
    }
    g+=std::to_string(a.year);
    return g;
}


bool Data::LeapYear()
{
    return ((year%4==0&&year%100!=0)||year%400==0);
}


bool Data::LeapYear( unsigned long long year)
{
    return ((year%4==0&&year%100!=0)||year%400==0);
}


short int Data::Days(short int m)
{
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        return 31;
    if(m==2)
        return 28+LeapYear();
    return 30;
    //{31,28,31,30,31,30,31,31,30,31,30,31};
    //  1  2  3  4  5  6  7  8  9 10 11 12
}


short int Data::Days(short int m, unsigned long long y)
{
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        return 31;
    if(m==2)
        return 28+LeapYear(y);
    return 30;
    //{31,28,31,30,31,30,31,31,30,31,30,31};
    //  1  2  3  4  5  6  7  8  9 10 11 12
}

bool Data::operator >=(Data b)
{
    if(year>b.year)
        return true;
    if(year<b.year)
        return false;
    if(month>b.month)
        return true;
    if(month<b.month)
        return false;
    return day>=b.day;
}

bool Data::operator <=(Data b)
{
    if(year>b.year)
        return false;
    if(year<b.year)
        return true;
    if(month>b.month)
        return false;
    if(month<b.month)
        return true;
    return day<=b.day;
}

bool Data::operator ==(Data b)
{
    return day==b.day&&month==b.month&&year==b.year;
}

bool Data::operator <(Data b)
{
    if(year<b.year)
        return true;
    if(year>b.year)
        return false;
    if(month<b.month)
        return true;
    if(month>b.month)
        return false;
    return day<b.day;
}

bool Data::operator >(Data b)
{
    if(year<b.year)
        return false;
    if(year>b.year)
        return true;
    if(month<b.month)
        return false;
    if(month>b.month)
        return true;
    return day>b.day;
}

short Data::get_day()
{
    return day;
}


short Data::get_month()
{
    return month;
}


unsigned long long Data::get_year()
{
    return year;
}
