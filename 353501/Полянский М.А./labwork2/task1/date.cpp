#include "date.h"
#include <QDebug>

int daysInMonth[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int day, int month, int year) : Day(day), Month(month), Year(year) {
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
}

int Date::day() const {
    return Day;
}

int Date::month() const {
    return Month;
}

int Date::year() const {
    return Year;
}

void Date::setDay(int day) {
    Day = day;
}

void Date::setMonth(int month) {
    Month = month;
}

void Date::setYear(int year) {
    Year = year;
}

void Date::getInfo(int* day, int* month, int* year) const {
    *day = Day;
    *month = Month;
    *year = Year;
}

Date Date::nextDay() const {
    int maxDay = getMonthLength(Month, isLeapYear(Year));
    if (Day < maxDay) {
        return Date(Day + 1, Month, Year);
    } else if (Month < 12) {
        return Date(1, Month + 1, Year);
    } else {
        return Date(1, 1, Year + 1);
    }
}

Date Date::previousDay() const {
    if (Day > 1) {
        return Date(Day - 1, Month, Year);
    } else if (Month > 1) {
        int prevMonthDays = getMonthLength(Month - 1, isLeapYear(Year));
        return Date(prevMonthDays, Month - 1, Year);
    } else {
        return Date(31, 12, Year - 1);
    }
}

short Date::weekNumber() const {
    
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;
    int d = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return (d + 6) % 7;
}

short Date::dayOfWeek() const {
    
    int y0 = Year - (14 - Month) / 12;
    int x = y0 + y0 / 4 - y0 / 100 + y0 / 400;
    int m0 = Month + 12 * ((14 - Month) / 12) - 2;
    int d0 = (Day + x + (31 * m0) / 12) % 7;
    return d0;
}

Date Date::today() {
    QDate currentDate = QDate::currentDate();

    int day = currentDate.day();
    int month = currentDate.month();
    int year = currentDate.year();

    return Date(day, month, year);
}


bool Date::isDateValid() const {
    // Check if the date is valid
    if (Month < 1 || Month > 12)
        return false;
    if (Day < 1 || Day > getMonthLength(Month, isLeapYear(Year)))
        return false;
    return true;
}

Date Date::stringToDate(QString word) {
    QStringList parts = word.split(".");
    if (parts.size() != 3) {
        qDebug() << "Invalid date string format";
        return Date(1, 1, 2000);
    }
    bool ok1, ok2, ok3;
    int day = parts[0].toInt(&ok1);
    int month = parts[1].toInt(&ok2);
    int year = parts[2].toInt(&ok3);
    if (!ok1 || !ok2 || !ok3) {
        qDebug() << "Invalid date string format";
        return Date(22, 3, 2024);
    }
    Date date(day, month, year);

    if (!date.isDateValid()) {
        qDebug() << "Invalid date values";
        throw std::invalid_argument("Invalid date values");
    }
    return date;
}



QString Date::weekdayToString(int weekday) {
    switch (weekday) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Invalid weekday";
    }
}

int Date::duration(Date date1, Date date2) {
    // Calculate duration
    int days1 = date1.absDuration();
    int days2 = date2.absDuration();
    return std::abs(days1 - days2);
}

int Date::getMonthLength(int month, bool leap) const{
    if (month == 2) {
        return leap ? 29 : 28;
    } else {
        return daysInMonth[month - 1];
    }
}

QString Date::dateToString(const Date& date) {
    return QString::number(date.day()) + "." + QString::number(date.month()) + "." + QString::number(date.year());
}

int Date::absDuration() {
    int days = Day - 1;
    for (int i = 0; i < Month - 1; ++i) {
        days += daysInMonth[i];
    }
    int leapYears = (Year - 1) / 4 - (Year - 1) / 100 + (Year - 1) / 400;
    days += (Year - 1) * 365 + leapYears;
    return days;
}

bool Date::isLeapYear(int year) const{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

QString Date::toString() const {
    int year, month, day;
    getInfo(&day, &month, &year);

    QString formattedYear = QString::number(year);
    // Add leading zeros if the year is less than 1000
    if (year < 1000) {
        formattedYear = QString("%1").arg(year, 4, 10, QLatin1Char('0'));
    }

    return QString("%1.%2.%3").arg(day, 2, 10, QLatin1Char('0')).arg(month, 2, 10, QLatin1Char('0')).arg(formattedYear);
}

Date Date::FromString(std::string dateStr) {
    
    if (dateStr.size() != 10)
        throw std::invalid_argument("Invalid date, length should be 10");

    // Validate the format of the date string
    for (int i = 0; i < 10; i++) {
        if ((i == 2 || i == 5) && dateStr[i] != '.')
            throw std::invalid_argument("Invalid date, expected dot");
        else if (i != 2 && i != 5 && (dateStr[i] < '0' || dateStr[i] > '9'))
            throw std::invalid_argument("Invalid date, expected digit");
    }

    int day = std::stoi(dateStr.substr(0, 2));
    int month = std::stoi(dateStr.substr(3, 2));
    int year = std::stoi(dateStr.substr(6, 4));

    return Date(day, month, year);
}


Date Date::fromQDate(QDate date){
    return Date(date.day(), date.month(), date.year());
}