#include "date.h"
#include <qcontainerfwd.h>
#include <qdatetime.h>
#include <stdexcept>
#include <string>

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {
  if (isLeapYear(year)) {
    daysInMonth[1] = 29;
  }
}

int Date::day() const { return day_; }
int Date::month() const { return month_; }
int Date::year() const { return year_; }

void Date::setDay(int day) { day_ = day; }
void Date::setMonth(int month) { month_ = month; }
void Date::setYear(int year) { year_ = year; }


bool Date::isLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);}

Date Date::nextDay() const {
    int nextDay = day_;
    int nextMonth = month_;
    int nextYear = year_;

    nextDay++;
    int daysInMonth = 31;

    if (nextMonth == 2) {
        daysInMonth = isLeapYear(nextYear) ? 29 : 28;
    } else if (nextMonth == 4 || nextMonth == 6 || nextMonth == 9 ||
               nextMonth == 11) {
        daysInMonth = 30;
    }

    if (nextDay > daysInMonth) {
        nextDay = 1;
        nextMonth++;
        if (nextMonth > 12) {
            nextMonth = 1;
            nextYear++;
        }
    }

    return Date(nextDay, nextMonth, nextYear);
}

Date Date::previousDay() const {
    if (day_ == 1 && month_ == 1 && year_ == 1) {
        Date date(01, 01, 0001);
        return date;
    }

    int prevDay = day_ - 1;
    int prevMonth = month_;
    int prevYear = year_;

    if (prevDay < 1) {
        prevMonth--;
        if (prevMonth < 1) {
            prevMonth = 12;
            prevYear--;
        }

        int daysInPrevMonth = 31;

        if (prevMonth == 2) {
            daysInPrevMonth = isLeapYear(prevYear) ? 29 : 28;
        } else if (prevMonth == 4 || prevMonth == 6 || prevMonth == 9 ||
                   prevMonth == 11) {
            daysInPrevMonth = 30;
        }

        prevDay = daysInPrevMonth;
    }

    return Date(prevDay, prevMonth, prevYear);
}

Date Date::today() {
    QDate todayTmp = QDate::currentDate();
    Date today{todayTmp.day(), todayTmp.month(), todayTmp.year()};
    return today;
}

QString Date::tillBday(Date bday) const {
    Date today = *this;
    if (today.day_ == bday.day_ && today.month_ == bday.month_ &&
        today.year_ == bday.year_) {
        return "You were born today!";
    }
    if (bday.year_ > today.year_ ||
        (bday.year_ == today.year_ && bday.month_ > today.month_) ||
        (bday.year_ == today.year_ && bday.month_ == today.month_ &&
         bday.day_ > today.day_)) {
        return "You haven't been born yet!";
    }

    if (today.month_ == bday.month_ && today.day_ == bday.day_) {
        return "Today is your birthday!";
    }

    int nextBdayYear;
    if (today.month_ < bday.month_ || today.month_ == bday.month_ && today.day_ < bday.day_) {
        nextBdayYear = today.year_;
    } else {
        nextBdayYear = today.year_ + 1;
    }

    Date nextBday{bday.day_, bday.month_, nextBdayYear};
    return QString::number(Date::duration(today, nextBday));
}

int Date::duration(Date date1, Date date2) {
    return date2.absDuration() - date1.absDuration();
}

int Date::absDuration() {
    int duration = 0;
    Date date = *this;
    
    for (int i = 1; i < date.year(); i++) {
        duration += Date::isLeapYear(i) ? 366 : 365;
    }

    for (int i = 1; i < date.month(); i++) {
        Date tmpDate {date.day(), i, date.year()};
        duration += tmpDate.getMonthLength();
    }

    duration += date.day();

    return duration;
}

short Date::weekNumber() const {
    int totalDays = 0;
    int weekNum = 0;

    int j = 1; //дата первого понедельника
    int weekday = -1;
    while (weekday != 0) {
        Date tmpDate{j, 01, year_};
        weekday = tmpDate.dayOfWeek();
        j++;
    }
    j--; // дата первого понедельника
    totalDays -=j;

    if (j == 1) weekNum --;

    if (day_ < j && month_ == 1) {
        weekNum = 1;
        return weekNum;
    }

    for (int i = 1; i < month_; i++) {
        Date tmpDate{day_, i, year_};
        totalDays += tmpDate.getMonthLength();
    }
    totalDays += day_;
    totalDays /= 7;
    weekNum += totalDays;

    return weekNum + 2;
}

short Date::dayOfWeek() const {
    int day = day_;
    int month = month_;
    int year = year_;

    // 0 - Monday
    int weekday;

    if (month < 3) {
        month += 12;
        year--;
    }

    weekday = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 -
               year / 100 + year / 400) % 7;

    return weekday;
}

Date Date::stringToDate(QString word) {
    int day, month, year;
    day = std::stoi(word.toStdString().substr(0, 2));
    month = std::stoi(word.toStdString().substr(3, 2));
    year = std::stoi(word.toStdString().substr(6, 4));

    Date date(day, month, year);

    if (!date.isDateValid()) {
        throw std::invalid_argument("Invalid date");
    }

    return date;
}

bool Date::isDateValid() const {
    int day = day_;
    int month = month_;
    int year = year_;

    if (year < 1) {
        return false;
    }
    
    if (month > 12 || month < 1) {
        return false;
    }

    if (month == 2 && ((isLeapYear(year) && (day > 29 || day < 1)) ||
                       (!isLeapYear(year) && (day > 28 || day < 1)))) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) &&
        (day > 30 || day < 1)) {
        return false;
    } else if (day > 31 || day < 1) {
        return false;
    }

    return true;
}

int Date::getMonthLength() {
    int i = this->month();
    if (i == 4 || i == 6 || i == 9 || i == 11) {
        return 30;
    } else if (i == 2) {
        return isLeapYear(this->year()) ? 29 : 28;
    } else {
        return 31;
    }
}

QString Date::dateToString(Date date) {

    QString day = QString::number(date.day());
    QString month = QString::number(date.month());
    QString year = QString::number(date.year());

    if (day.size() < 2)
        day.insert(0, "0");

    if (month.size() < 2)
        month.insert(0, "0");

    while (year.size() < 4) {
        year = "0" + year;
    }

    QString dateString = day + "." + month + "." + year;

    return dateString;
}

QString Date::weekdayToString(int weekday) {
    switch (weekday) {
    case 0:
        return "Monday";
        break;
    case 1:
        return "Tuesday";
        break;
    case 2:
        return "Wednesday";
        break;
    case 3:
        return "Thursday";
        break;
    case 4:
        return "Friday";
        break;
    case 5:
        return "Saturday";
        break;
    case 6:
        return "Sunday";
        break;
    default:
        return "n/a";
        break;
    }
}

