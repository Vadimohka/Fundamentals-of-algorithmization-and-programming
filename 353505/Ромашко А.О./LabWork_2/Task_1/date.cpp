#include "date.h"
#include <QDebug>

void Date::DaysInDate()
{
    datedays = this->days;
    for(int j = 0; j< this->years;j++)
    {
        if(this->IsLeap())
            datedays+=1;
        for(int i = 0; i < 12; i++)
        {
            datedays = datedays + monthdays[i];
        }
    }
    qDebug() << "Days in date (start :01.01.0000): "<<datedays;
}

Date::Date(int dayd,int monthd,int yeard) {
    this->days=dayd;
    this->months=monthd;
    this->years=yeard;
}

Date::~Date()
{

}

Date Date::NextDay(){
    if(days<monthdays[months-1]){
        return Date(days+1,months,years);
    }
    else {
        if(months<12){
            return Date(1,months+1,years);
        }
        else if(years<9999){
            return Date(1,1,years+1);
        }
        else return Date(0,0,0);
    }
}

Date Date::PreviousDay()
{
    if(days>1){

        return Date(days-1,months,years);
    }
    else {
        if(months>1){
            return Date(monthdays[months-1],months-1,years);
        }
        else if(years>1){
            return Date(31,12,years-1);
        }
        else{
            return Date(0,0,0);
        }
    }
}

bool Date::qstoi()
{
    QString temp;
    try{
        for(int i = 0; i < date.size(); i++)
        {
            if(date[i] != '.')
            {
                if(!(date[i]>='0' && date[i]<='9')){
                    qDebug()  << "Throw";
                    throw 0;
                }
                temp.append(date[i]);
            }
            else
            {
                if(i!=2 && i!=5 ){
                    qDebug()  << "Throw";
                    throw 0;
                }
            }

        }
        int istr = temp.toInt();
        this->days = istr/1000000;
        this->months = istr%1000000/10000;
        this->years = istr%10000;
        int islp=0;
        if(this->IsLeap() && this->months == 2)
            islp=1;
        if(monthdays[this->months-1]+islp<this->days || this->days == 0)
        {
            throw 0;
        }
        if(this->months>12 || this->months == 0)
        {
            throw 0;
        }
        //this->date = this->dateToStandart();
    }
    catch(...)
    {
        qDebug()  << "Catch";

        return 0;
    }

    return 1;
}

short Date::WeekNumber(){

    short temp=0;
    for(int i=0;i<this->months-1;++i){
        temp+=monthdays[i];
    }
    return (temp+this->days)/7+1;
}

int Date::DaysTillYourBithday(Date *bithdaydate)
{
    int res = 0, m = this->months,mb = bithdaydate->months;
    qDebug()  << m << " " << mb;
    res += abs(this->days - bithdaydate->days);
    for(int i =0 ; i <12; i++)
    {
        if( i > m && i < mb)
        {
            res+= monthdays[i];
        }
    }
    return res;
}

int Date::Duration(Date date)
{
    return this->getDateDays()-date.getDateDays();
}

QString Date::dateToStandart()
{

    QString str;
    if(days<10)
    {
        str = '0' + QString::number(this->days);
    }
    else
    {
        str =  QString::number(this->days);
    }
    str += ".";
    if(months<10)
    {
        str += '0';
        str += QString::number(this->months);
    }
    else
    {
        str += QString::number(this->months);
    }
    str += ".";
    if(years>999)
    {
        str += QString::number(this->years);
    }
    else
    {
        if(years>99)
        {
            str += '0';
            str += QString::number(this->years);
        }
        else
        {
            if(years>9)
            {
                str += "00";
                str += QString::number(this->years);
            }
            else
            {
                if(years>0)
                {
                    str += "000";
                    str += QString::number(this->years);
                }
                else{
                    str += "0000";
                }
            }
        }
    }
    return str;
}

bool Date::IsLeap() {return (this->years%400==0 || (this->years%4==0 && this->years%100!=0)) ? 1 : 0;}

void Date::setDate(QString date){this->date = date;}
void Date::setYear(int years) {this->years = years;}
void Date::setMonth(int months) {this->months = months;}
void Date::setDay(int days) {this->days = days;}

QString Date::getDate(){ return date;}
int Date::getYear() {return years;}
int Date::getMonth() {return months;}
int Date::getDay() {return days;}
int Date::getDateDays(){DaysInDate(); return datedays;}


