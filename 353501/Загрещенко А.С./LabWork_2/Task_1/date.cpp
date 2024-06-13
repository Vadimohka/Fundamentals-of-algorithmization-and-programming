#include "date.h"

Date::Date(int day, int month, int year)
{
    if (CheckCorrectDate(day, month, year)) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else {
        this->day = -1;
        this->month = -1;
        this->year = -1;
    }
}

Date::Date(QString string_date)
{
    QRegularExpression re("(\\d{2})\\.(\\d{2})\\.(\\d{4})");
    QRegularExpressionMatch match = re.match(string_date);
    if (match.hasMatch() && string_date.size() == 10) {
        int day = match.captured(1).toInt();
        int month = match.captured(2).toInt();
        int year = match.captured(3).toInt();
        if (CheckCorrectDate(day, month, year)) {
            this->day = day;
            this->month = month;
            this->year = year;
        }
    }
    else {
        this->day = -1;
        this->month = -1;
        this->year = -1;
    }
}

void Date::SetDate(QString string_date)
{
    QRegularExpression re("(\\d{2})\\.(\\d{2})\\.(\\d{4})");
    QRegularExpressionMatch match = re.match(string_date);
    if (match.hasMatch()){
        int day = match.captured(1).toInt();
        int month = match.captured(2).toInt();
        int year = match.captured(3).toInt();
        if (CheckCorrectDate(day, month, year)) {
            this->day = day;
            this->month = month;
            this->year = year;
        }
        else {
            this->day = -1;
            this->month = -1;
            this->year = -1;
        }
    }
}

QString Date::DayOfWeekString()
{
    switch (DayOfWeek()) {
    case 0:
        return "Воскресенье";
    case 1:
        return "Понедельник";
    case 2:
        return "Вторник";
    case 3:
        return "Среда";
    case 4:
        return "Четверг";
    case 5:
        return "Пятница";
    case 6:
        return "Суббота";
    default:
        return "Ошибка";
    }
}

bool Date::IsValid()
{
    if (day == -1 || month == -1 || year == -1 || !CheckCorrectDate(day, month, year)) {
        return false;
    }
    else {
        return true;
    }
}

void Date::SetDate(int day, int month, int year)
{
    if (CheckCorrectDate(day, month, year)) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else {
        this->day = -1;
        this->month = -1;
        this->year = -1;
    }
}

Date Date::NextDay() {
    int new_day = this->day;
    int new_month = this->month;
    int new_year = this->year;

    if (new_day == 31 && new_month == 12) {
        new_year++;
        new_month = 1;
        new_day = 1;
    } else if (new_day == DaysInMonth(new_month, new_year)) {
        new_month++;
        new_day = 1;
    } else {
        new_day++;
    }

    return Date(new_day, new_month, new_year);
}

Date Date::PreviousDay() {
    int new_day = this->day;
    int new_month = this->month;
    int new_year = this->year;

    if (new_day == 1 && new_month == 1) {
        new_year--;
        new_month = 12;
        new_day = 31;
    } else if (new_day == 1) {
        new_month--;
        new_day = DaysInMonth(new_month, new_year);
    } else {
        new_day--;
    }

    return Date(new_day, new_month, new_year);
}

bool Date::IsLeap() {
    return IsLeap(this->year);
}

bool Date::IsLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

short Date::WeekNumber() {
    return DayOfYear() / 7 + 1;
}

short Date::DayOfWeek()
{
    int YY = this->year % 100;
    int year_code = (YY + (YY / 4)) % 7;
    QMap<int, int> month_codes = {{1,  0},{2,  3},{3,  3},{4,  6},{5,  1},{6,  4},{7,  6},{8,  2},{9,  5},{10, 0},{11, 3},{12, 5}};

    int month_code = month_codes.value(this->month);

    int century_code = ((this->year / 100) % 20 - 3) * (-2);
    int date_number = this->day;
    int leap_year_code = (IsLeap() && (month == 1 || month == 2));
    return (year_code + month_code + century_code + date_number - leap_year_code) % 7;
}

short Date::DayOfYear()
{
    int count = this->day;
    for (int i = 1; i < this->month; i++) {
        count += DaysInMonth(i, this->year);
    }
    return count;
}

int Date::DaysTillYourBithday(Date bithdaydate)
{
    Date nextBithday(bithdaydate.GetDay(), bithdaydate.GetMonth(), this->year);
    if (bithdaydate.GetYear() > this->year) {
        return this->Duration(bithdaydate);
    }
    else if (this->Duration(nextBithday, true) < 0) {
        return this->Duration(Date(bithdaydate.GetDay(), bithdaydate.GetMonth(), this->year+1));
    }
    else {
        return this->Duration(Date(bithdaydate.GetDay(), bithdaydate.GetMonth(), this->year));
    }
}

int Date::Duration(Date date, bool sign)
{
    int start_year = fmin(this->year, date.GetYear());
    int days1 = this->DayOfYear(), days2 = date.DayOfYear();
    for (int i = start_year; i < this->year; i++) {
        days1 += (this->IsLeap(i)?366:365);
    }

    for (int i = start_year; i < date.GetYear(); i++) {
        days2 += (date.IsLeap(i)?366:365);
    }
    return (sign?days2-days1:abs(days2-days1));
}

QString Date::StringDate() {
    QString str_date = QString("%1.%2.%3")
                           .arg(this->day, 2, 10, QChar('0'))
                           .arg(this->month, 2, 10, QChar('0'))
                           .arg(this->year, 4, 10, QChar('0'));
    return str_date;
}

int Date::GetDay()
{
    return this->day;
}

int Date::GetYear()
{
    return this->year;
}

int Date::GetMonth()
{
    return this->month;
}

short Date::DaysInMonth(int month, int year) {
    QSet<int> day31 = {1, 3, 5, 7, 8, 10, 12};

    if (month == 2) {
        return (IsLeap(year) ? 29 : 28);
    } else if (day31.contains(month)) {
        return 31;
    } else {
        return 30;
    }
}

bool Date::CheckCorrectDate(int day, int month, int year)
{
    if (year > 9999 || year < 0) {
        return false;
    }
    if (month > 12 || month < 1) {
        return false;
    }
    if (day > DaysInMonth(month, year) || day < 1) {
        return false;
    }
    return true;
}

bool Date::CheckCorrectDate(QString *string_date)
{
    QRegularExpression re("(\\d{2})\\.(\\d{2})\\.(\\d{4})");
    QRegularExpressionMatch match = re.match(*string_date);
    if (match.hasMatch() && string_date->size() == 10) {
        int day = match.captured(1).toInt();
        int month = match.captured(2).toInt();
        int year = match.captured(3).toInt();
        return CheckCorrectDate(day, month, year);
    }
    else {
        return false;
    }
}
