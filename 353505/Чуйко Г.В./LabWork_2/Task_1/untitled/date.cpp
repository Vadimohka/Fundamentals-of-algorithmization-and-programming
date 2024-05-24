#include "date.h"
#include <ctime>

Date::Date(int day, int month, int year) {
    currentDay = day;
    currentMonth = month;
    currentYear = year;

    dayInYear = 0;
    for(int i = 0; i<currentMonth-1; ++i){
        dayInYear += daysInMonth[i];
    }
    dayInYear += currentDay;
    if(isLeapYear(currentYear))
    {
        daysInMonth[1]=29;
        isLeap=true;
    }

    if(currentDay<1||currentDay>daysInMonth[currentMonth-1]||currentMonth>12||currentMonth<1||currentYear<1||currentYear>9999)isCorrect=false;
}

Date::Date(QString date){
    if(date.length()!=10){
        isCorrect = false;
        currentDay = 0;
        currentMonth = 0;
        currentYear = 0;
    }
    else{

        for(int i =0; i<10;++i){
            if((i==2||i==5)&&date[i]!='.'){
                isCorrect = false;
            }
            else if(!date[i].isDigit()&&i!=2&&i!=5){
                isCorrect = false;
            }
        }

        currentDay = date[0].digitValue()*10+date[1].digitValue();
        currentMonth = date[3].digitValue()*10+date[4].digitValue();
        currentYear = date[6].digitValue()*1000 + date[7].digitValue()*100 + date[8].digitValue()*10 + date[9].digitValue();

        if(isLeapYear(currentYear))
        {
            daysInMonth[1]=29;
            isLeap=true;
        }

        dayInYear = 0;
        for(int i = 0; i<currentMonth-1; ++i){
            dayInYear += daysInMonth[i];
        }
        dayInYear += currentDay;

        if(currentDay<1||currentDay>daysInMonth[currentMonth-1]||currentMonth>12||currentMonth<1)isCorrect=false;
    }
}

bool Date::isLeapYear(int year){
    if(year%400==0){
        return true;
    }else if(year%100==0){
        return false;
    }else if(year%4==0){
        return true;
    }else{
        return false;
    }
}

Date Date::nextDay(){
    int day = currentDay + 1;
    int month = currentMonth;
    int year = currentYear;

    if(day>daysInMonth[month-1]){
        month++;
        day=1;
        if(month>12){
            year++;
            month=1;
        }
    }

    return Date(day, month, year);
}

Date Date::previousDay(){
    int day = currentDay - 1;
    int month = currentMonth;
    int year = currentYear;

    if(day==0){
        month--;
        day=daysInMonth[month];
        if(month==0){
            year--;
            month=12;
        }
    }

    return Date(day, month, year);
}

short Date::weekNumber(){
    return (dayInYear-1)/7 + 1;
}

int Date::daysTillYourBirthday(Date birthdayDate){
    int duration = 1;
    Date nextDay = Date::nextDay();
    while(birthdayDate.currentDay!=nextDay.currentDay||birthdayDate.currentMonth!=nextDay.currentMonth){
        nextDay = nextDay.nextDay();
        duration++;
    }
    return duration;
}

int Date::duration(Date date){
    int duration = 0;
    if(this->currentYear == date.currentYear) return qAbs(date.dayInYear - this->dayInYear);

    if(this->currentYear < date.currentYear){
        duration += date.dayInYear - this->dayInYear;
        duration += 365;
        if((this->isLeap&&this->dayInYear<60)||(date.isLeap&&date.dayInYear>60)) duration++;
        for(int i = this->currentYear+1; i<date.currentYear; ++i){
            duration += 365;
            if(isLeapYear(i)) duration++;
        }
    }

    if(this->currentYear > date.currentYear){
        duration += this->dayInYear - date.dayInYear;
        duration += 365;
        if((this->isLeap&&this->dayInYear>60)||(date.isLeap&&date.dayInYear<60)) duration++;
        for(int i = date.currentYear+1; i<this->currentYear; ++i){
            duration += 365;
            if(isLeapYear(i)) duration++;
        }
    }
    return duration;
}

bool Date::canBeBirtday(){
    time_t nowTime = std::time(NULL);
    tm *localtime = std::localtime(&nowTime);
    Date nowDate(localtime->tm_mday,1+localtime->tm_mon,localtime->tm_year+1900);
    if(nowDate.currentYear>this->currentYear||(nowDate.currentYear==this->currentYear&& this->dayInYear<nowDate.dayInYear)){
        return true;
    }else{
        return false;
    }

}

QString Date::getDate() const{
    if(!this->isCorrect) return "--.--.----   ";
    QString data = "";
    data.append(QChar('0'+currentDay/10));
    data.append(QChar('0'+currentDay%10));
    data.append('.');
    data.append(QChar('0'+currentMonth/10));
    data.append(QChar('0'+currentMonth%10));
    data.append('.');
    data.append(QChar('0'+currentYear/1000));
    data.append(QChar('0'+ (currentYear%1000)/100));
    data.append(QChar('0'+ (currentYear%100)/10));
    data.append(QChar('0'+currentYear%10));

    return data;
}
