#include "data.h"



Date::Date(short int d, short int m, long long y)
{
    day=d;
    month=m;
    year=y;
}


Date::Date()
{
    day=-1;
    month=-1;
    year=-8;
}


Date Date::today()
{
    //qDebug()<<QDate::currentDate().day()<<"."<<QDate::currentDate().month()<<"."<<QDate::currentDate().year();
    short int d=ceil(time(nullptr)/86400),y=1970,m=1;
    //qDebug()<<time(nullptr)<<" sec "<<d<<" days ";
    Date a;
    while(d>=365-1+LeapYear(y))
    {
        d-=365+LeapYear(y);
        y++;
    }
    while(d>Days(m,y))
    {
        d-=Days(m,y);
        m++;
    }

    return {d,m,y};

}


std::string Date::NextDay()
{
    Date Next={day,month,year};
    Next.day++;
    if(Next.day>Days(Next.month))
        Next.month++,Next.day=1;
    if(Next.month>12)
        Next.year++,Next.month=1;

    return date_to_string(Next);
}



std::string Date::PreviousDay()
{
    Date Prev={day,month,year};
    Prev.day--;
    if(Prev.day<=0)
    {
        Prev.month--;
        if(Prev.month<=0)
            Prev.month=12,Prev.year--;
        Prev.day=Days(Prev.month);
    }
    return date_to_string(Prev);
}


int Date::DaysTillYourBirthday(Date birthdaydate)
{
    return Duration(birthdaydate);
}


long long Date::Duration(Date b)
{
    Date a(day,month,year);

    int mn=1;
    long long duration=0;
    if((b.year>a.year)||(b.year==a.year&&(b.month>a.month||(b.month==a.month&&a.day<b.day))))
    {
        mn=-1;
        std::swap(a,b);
    }
    duration-=b.day-1;
    b.day=1;
    //qDebug()<<"IN dur"<<a.day<<" "<<a.month<<" "<<a.year<<" & "<<b.day<<" "<<b.month<<" "<<b.year<<"duration = "<<duration;
    while(a.month>b.month)
        {
            b.month++;
            duration+=Days(b.month,b.year);
        }
    //qDebug()<<"IN dur"<<a.day<<" "<<a.month<<" "<<a.year<<" & "<<b.day<<" "<<b.month<<" "<<b.year<<"duration = "<<duration;
    while(a.month<b.month)
    {
        b.month--;
        duration-=Days(b.month,b.year);
    }
    //qDebug()<<"IN dur"<<a.day<<" "<<a.month<<" "<<a.year<<" & "<<b.day<<" "<<b.month<<" "<<b.year<<"duration = "<<duration;
    while(a.year!=b.year)
    {
        b.year++;
        duration+=365+LeapYear(b.year);
    }
    duration+=a.day-1;
    //qDebug()<<"IN dur"<<a.day<<" "<<a.month<<" "<<a.year<<" & "<<b.day<<" "<<b.month<<" "<<b.year<<"duration = "<<duration;

    return duration*mn;
}


bool Date::Init(std::string s)
{
    qDebug()<<"Try init:"<<s;
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

    if(s.size()-7>3)return false;
        year=stoull(s.substr(6));

    //qDebug()<<year;
    if(day==0||month==0||month>12||day>Days(month))
        return false;//day=month=year=-8888;
    return true;
}


std::string Date::get_date()
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


std::string Date::date_to_string(Date a)
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


bool Date::LeapYear()
{
    return ((year%4==0&&year%100!=0)||year%400==0);
}


bool Date::LeapYear(long long year)
{
    return ((year%4==0&&year%100!=0)||year%400==0);
}


short int Date::Days(short int m)
{
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        return 31;
    if(m==2)
        return 28+LeapYear();
    return 30;
    //{31,28,31,30,31,30,31,31,30,31,30,31};
    //  1  2  3  4  5  6  7  8  9 10 11 12
}


short int Date::Days(short int m,long long y)
{
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        return 31;
    if(m==2)
        return 28+LeapYear(y);
    return 30;
    //{31,28,31,30,31,30,31,31,30,31,30,31};
    //  1  2  3  4  5  6  7  8  9 10 11 12
}


short Date::get_day()
{
    return day;
}


short Date::get_month()
{
    return month;
}


long long Date::get_year()
{
    return year;
}


void Date::set_year(long long y)
{
    year=y;
}
