#include "date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    if(IsLeap()){
        countDaysInMonths[1]++;
    }
}


bool Date::CheckStringDate(QString date)
{
    if (date[2] != '.' || date[5] != '.' || date.length() != 10)
    {
        return false;
    }

    for(int i = 0; i < date.length(); ++i)
    {
        if ((date[i] > '9' || date[i] < '0') && date[i] != '.' )
        {
            return false;
        }
    }

    QString Day, Month, Year;
    for(int i = 0; i < 10; i++)
    {
        if(i>-1 && i<2)
        {
            Day+=date[i];
        }

        if(i > 2 && i < 5)
        {
            Month+=date[i];
        }

        if(i > 5)
        {
            Year+=date[i];
        }
    }

    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date ss(day, month, year);

    if (month > 12 || day > 31 || month < 0 || day< 0 || year > 9999 || year < 0)
    {
        return false;
    }

    if (!ss.IsLeap() && month == 2 && day > 28)
    {
        return false;   
    }

    if (ss.IsLeap() && month == 2 && day > 29)
    {
        return false;
    }

    if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        return false;
    }

    return true;
}

Date Date::fromString(const QString& dateString) {
    QStringList dateComponents = dateString.split('.');
    QString dayStr = dateComponents[0];
    QString monthStr = dateComponents[1];
    QString yearStr = dateComponents[2];

    int day = dayStr.toInt();
    int month = monthStr.toInt();
    int year = yearStr.toInt();

    return Date(day, month, year);
}

bool Date::IsLeap()
{
    if ( (year % 4 == 0)  && (year % 100 != 0 || year % 400 == 0)){
        return true;
    }
    else{
        return false;
    }
}

bool Date::IsLeap(int year){
    if ( (year % 4 == 0)  && (year % 100 != 0 || year % 400 == 0)){
        return true;
    }
    else{
        return false;
    }
}

Date Date::NextDay(){
    if((month == 12) && (day == 31)){
        return Date(1, 1, year + 1);
    }
    else if (day == countDaysInMonths[month - 1]){
        return Date(1, month + 1, year);
    }
    else{
        return Date(day + 1, month, year);
    }
}

Date Date::PreviousDay(){
    if((month == 1)&&(day == 1))
    {
        return Date(31, 12, year - 1);
    }
    else if (day == 1)
    {
        if (month == 3 && IsLeap())
        {
            return Date(29, 2, year);
        }
        else{
            return Date(countDaysInMonths[month-2], month - 1, year);
        }

    }
    else{
        return Date(day-1, month, year);
    }
}

short Date::WeekNumber(){
    QDate date(year, month, day);

    return date.weekNumber();
}

QString Date::str()
{
    return QDate(year,month,day).toString("dd.MM.yyyy");
}

bool isLeapYearForInt(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::getDaysInMonth() {
    if (month == 2 && isLeapYearForInt(year)) {
        return 29;
    }
    else if (month == 2) {
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int Date::Duration(Date date1){

    QDate Qdate2 = Qdate2.currentDate();

    Date date2 = Date(Qdate2.day(), Qdate2.month(), Qdate2.year());

    //date 1 should be earlier
    if (date1.year > date2.year ||
        ( date1.year == date2.year && date1.month > date2.month ) ||
        ( date1.year == date2.year && date1.month == date2.month && date1.day > date2.day )) {
        std::swap(date1, date2);
    }

    return date2.absDuration() - date1.absDuration();
}

int Date::Duration(Date date1, Date date2){

    //date 1 should be earlier
    if (date1.year > date2.year ||
        ( date1.year == date2.year && date1.month > date2.month ) ||
        ( date1.year == date2.year && date1.month == date2.month && date1.day > date2.day )) {
        std::swap(date1, date2);
    }

    return date2.absDuration() - date1.absDuration();
}

int Date::absDuration() {
    int duration = 0;
    Date date = *this;

    for (int i = 1; i < year; i++) {
        duration += Date::IsLeap(i) ? 366 : 365;
    }

    for (int i = 1; i < month; i++) {
        Date tmpDate = Date {day, i, year};
        duration += tmpDate.getDaysInMonth();
    }

    duration += day;

    return duration;
}

int Date::durationQDate(Date date)
{
    QString str1,str2, str3;
    QString str = QDate::currentDate().toString("dd.MM.yyyy");

    for (int i = 0; i< str.size();i++)
    {
        if(i > -1 && i < 2)
        {
            str1=str1+str[i];
        }

        if(i < 5 && i > 2)
        {
            str2 = str2 + str[i];
        }

        if(i > 5)
        {
            str3 = str3 + str[i];
        }
    }

    int curDay = str1.toInt();
    int curMonth = str2.toInt();
    int curYear = str3.toInt();

    QDate dt1 = QDate(date.year,date.month,date.day);

    QDate dt2 = QDate(curYear,curMonth,curDay);

    int diff1 = dt1.toJulianDay();

    int diff2 = dt2.toJulianDay();

    int result = qAbs(diff1-diff2);

    return result;
}

bool Date::wasFebPast(){
    return this->month > 2;
}

int Date::DaysTillYourBithday(Date birthdaydate)
{

    if (IsLeap() && this->month > birthdaydate.month){
        return Duration(Date(birthdaydate.day,  birthdaydate.month, this->year + 1));
    }
    else if(IsLeap() && this->month == birthdaydate.month){
        if(this->day > birthdaydate.day){
            return Duration(Date(birthdaydate.day, birthdaydate.month, this->year + 1));
        }
    }
    else if (this->month > birthdaydate.month){
        return Duration(Date(birthdaydate.day, birthdaydate.month, this->year));
    }
    else if(this->month == birthdaydate.month){
        if(this->day > birthdaydate.day){
            return Duration(Date(birthdaydate.day, birthdaydate.month, this->year));
        }
    }
    return Duration(Date( birthdaydate.day, birthdaydate.month, this->year) );
}
