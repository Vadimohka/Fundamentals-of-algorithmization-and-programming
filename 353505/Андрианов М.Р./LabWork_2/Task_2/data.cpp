#include "data.h"

void Data::cr(QString a[]){
    name=a[0];
    list=a[1];
    perf=a[2];
    lead=a[3];
    date=a[4];
    ex=a[5];
    k[0]=name;
    k[1]=list;
    k[2]=perf;
    k[3]=lead;
    k[4]=date;
    k[5]=ex;
}
QString Data::check(QString ak){
    if(ak==name) return name;
    else return "";
}
QString Data::ret(int i){
    return k[i];
}
QString Data::checker(QString ak){
    QString akk="31.04.2024";
    int temp1=0,temp2=0,day2=0,day1=0,year1=0,year2=0,month1=0,month2=0;
    temp1+=ex[ex.length()-1].digitValue();
    for(int i=ex.length()-2;i>-1;--i){
        temp1+=ex[i].digitValue();
        temp1*=10;
    }
    year1=ak[6].digitValue()*1000+ak[7].digitValue()*100+ak[8].digitValue()*10+ak[9].digitValue();
    year2=2024;
    month1=ak[3].digitValue()*10+ak[4].digitValue();
    month2=4;
    day1=ak[0].digitValue()*10+ak[1].digitValue();
    day2=31;
    if(year1>year2) return "";
    else if(year1==year2){
        if(month1>month2) return "";
        else if(month1==month2){
            if(day1>day2) return "";
            else if(day1+temp1<=day2) {
                return ak;
            }
            else return "";
        }
        else {
            for(int i=month1;i<month2;++i){
                temp2+=days[i];
            }

            if(temp2+days[month1-1]+day2-day1>=temp1) return ak;
            else return "";
        }
    }
    else {
        for(int i=year1;i<year2;++i){
            temp2+=365;
            if(year1%400==0 || (year1%4==0 && year1%100!=0)) temp2+=1;
        }
        for(int i=11;i>month1;++i){
            temp2+=days[i];
        }
        if(temp2+(days[month1-1]-day1)+120<=temp1) return ak;
        else return "";
    }
}
