//
// Created by acryoz on 28.2.24.
//

#include "../headers/Date.h"


Date default_date = Date(1,1,1970);
int days_in_month[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cumulative_days[13]{0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
enum Days{Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7};
enum Months{January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12};

Date::Date() {
    this->m_day = 1;
    this->m_month = 1;
    this->m_year = 1970;
    this->valid = true;
}

Date::Date(uint day, uint month, uint year) {
    this->m_day = day;
    this->m_month = month;
    this->m_year = year;
    this->valid = true;
    if((month == Months::February && day >= 29 && !this->isLeap()) || (month > Months::December) || month <= 0 || day <= 0 || (day > days_in_month[month] && month != Months::February) || year <= 0){
        this->m_day = 1;
        this->m_month = 1;
        this->m_year = 1970;
        this->valid = false;
    }
}


Date::Date(const Date &old_date) {
    this->m_day = old_date.day();
    this->m_month = old_date.month();
    this->m_year = old_date.year();
    this->valid = old_date.isValid();
}


uint Date::day() const{
    return this->m_day;
}


uint Date::month() const{
    return this->m_month;
}


uint Date::year() const{
    return this->m_year;
}


Date Date::nextDay() const{
    uint nday = this->m_day + 1;
    uint nmonth = this->m_month;
    uint nyear = this->m_year;
    if(this->day() == 29 && this->month() == Months::February){
        return {1, 3, this->year()};
    }
    if(nday > days_in_month[nmonth]){
        if(nmonth != Months::February || (nmonth == Months::February && !isLeapYear(nyear))){
            nday -= days_in_month[nmonth];
            nmonth += 1;
        }
    }
    if(nmonth > Months::December){
        nmonth -= 12;
        nyear += 1;
    }
    return {nday, nmonth, nyear};
}


Date Date::previousDay() const{
    if(this->m_day == 1 && this->m_month == Months::January && this->m_year == 1){
        return {2000, 2000, 2000};
    }
    if(this->day() == 1 && this->month() == Months::March){
        if(this->isLeap()){
            return {29, 02, this->year()};
        }
        else{
            return {28, 02, this->year()};
        }
    }
    uint nday = this->m_day - 1;
    uint nmonth = this->m_month;
    uint nyear = this->m_year;
    if(nday == 0){
        nmonth -=1;
        nday = days_in_month[nmonth];
        if(nmonth == Months::December){
            nday += 1;
        }
    }
    if(nmonth == 0){
        nday = 31;
        nmonth = Months::December;
        nyear -= 1;
    }
    return {nday, nmonth, nyear};
}


bool Date::isLeap() const{
    if(this->m_year % 400 == 0){
        return true;
    }
    else if(this->m_year % 100 == 0){
        return false;
    }
    else if(this->m_year % 4 == 0){
        return true;
    }
    return false;
}

uint Date::daysTo(const Date& date) const{
    uint days_from = 0;
    Date start;
    Date end;
    if(date.year() < this->m_year){
        start = Date(date);
        end = Date(*this);
    }
    else if(date.year() > this->m_year){
        start = Date(*this);
        end = Date(date);
    }
    else{
        if(date.month() > this->m_month){
            start = Date(*this);
            end = Date(date);
        }
        else if(date.month() < this->m_month){
            start = Date(date);
            end = Date(*this);
        }
        else{
            if(date.day() > this->m_day){
                start = Date(*this);
                end = Date(date);
            }
            else if(date.day() < this->m_day){
                start = Date(date);
                end = Date(*this);
            }
            else{
                return 0;
            }
        }
    }
    uint years_from = end.year() - start.year();
    days_from += years_from * 365;
    days_from += leapYearsBefore(end.year()) - leapYearsBefore(start.year() - 1);
    uint cum_days = cumulative_days[end.month()] + end.day()  - cumulative_days[start.month()] - start.day();
    if(end.isLeap() && end.month() > Months::February){
        cum_days +=1;
    }
    if(start.isLeap() && start.month() > Months::February){
        cum_days -= 1;
    }
    days_from += cum_days;
    return days_from;
}

uint Date::weekNumber() const{
    uint w =(10 + cumulative_days[this->month()] + this->day() - this->daynumber())/7;
    if(this->isLeap() && this->month() > Months::February){
        w =(10 + cumulative_days[this->month()] + this->day() + 1 - this->daynumber())/7;
    }
    uint wks = weeks(this->m_year);
    if(w < 1){
        return weeks(this->m_year - 1);
    }
    else if(w > wks){
        return 1;
    }
    else{
        return w;
    }
}


uint Date::daysTillYourBirthday(const Date& birthday) const{
    if(*this < birthday){
        return this->daysTo(birthday);
    }
    else if(Date(birthday.day(), birthday.month(), this->year()) < *this){
        return this->daysTo(Date(birthday.day(), birthday.month(), this->year() + 1));
    }
    else{
        return this->daysTo(Date(birthday.day(), birthday.month(), this->year()));
    }
}


uint Date::daynumber() const {
    return (this->daysTo(default_date) + 3)%7 + 1;
}


bool Date::isValid() const{
    return this->valid;
}

Date& Date::operator=(const Date &old_date) {
    this->m_day = old_date.day();
    this->m_month = old_date.month();
    this->valid = old_date.isValid();
    this->m_year = old_date.year();
    return *this;
}


QString Date::toQstring() const {
    QString month = QString::number(this->m_month);
    if(this->m_month < Months::October){
        month = QString("0");
        month.append(QString::number(this->m_month));
    }
    QString day = QString::number(this->m_day);
    if(this->m_day < 10){
        day = QString("0");
        day.append(QString::number(this->m_day));
    }
    QString year = QString::number(this->m_year);
    if(this->m_year < 10){
        year = QString("000");
        year.append(QString::number(this->m_year));
    }
    else if(this->m_year < 100){
        year = QString("00");
        year.append(QString::number(this->m_year));
    }
    else if(this->m_year < 1000){
        year = QString("0");
        year.append(QString::number(this->m_year));
    }
    return QStringLiteral("%1.%2.%3").arg(day).arg(month).arg(year);
}


uint leapYearsBefore(uint year){
    return year/4 - year/100 + year/400;
}

bool Date::operator<(const Date& other) const{
    if(this->year() < other.year()){
        return true;
    }
    else if(this->year() == other.year()){
        if(this->month() < other.month()){
            return true;
        }
        else if(this->month() == other.month()){
            if(this->day() < other.day()){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
    return false;
}

Date Date::today() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    return {(uint)now->tm_mday, (uint)now->tm_mon + 1, (uint)now->tm_year + 1900};
}

Date Date::fromString(const QString& str) {
    auto inp = str.toLatin1();
    if(inp[2] != '.' || inp[5] != '.'){
        return {2000, 2000, 2000};
    }
    if(!(str[0].isDigit() && str[1].isDigit() && str[3].isDigit() && str[4].isDigit() &&
        str[6].isDigit() && str[7].isDigit() && str[8].isDigit() && str[9].isDigit())){
        return {2000, 2000, 2000};
    }
    uint day = 10*(inp[0]-'0') + inp[1] - '0';
    uint month = 10*(inp[3]-'0') + inp[4] - '0';
    uint year = 1000*(inp[6] - '0') + 100*(inp[7] - '0')+ 10*(inp[8] - '0') + inp[9] - '0';
    return {day, month, year};
}


uint weeks(uint y){
    uint py = (y + leapYearsBefore(y))%7;
    uint py1 = (y - 1 + leapYearsBefore(y - 1))%7;
    if(py == 4 || py1 == 3){
        return 53;
    }
    else{
        return 52;
    }
}


bool isLeapYear(uint y){
    if(y % 400 == 0){
        return true;
    }
    else if(y % 100 == 0){
        return false;
    }
    else if(y % 4 == 0){
        return true;
    }
    return false;
}