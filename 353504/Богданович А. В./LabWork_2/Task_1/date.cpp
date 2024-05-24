#include "date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;

    if (IsLeap()) {
        NumOfDays[1] = 29;
    }
}

Date::Date() {

}

bool Date::isDateCorrect() {
    if (this->month > 12 || this->month < 1) {
        return false;
    }

    if (this->day < 1 || this->day > NumOfDays[this->month - 1]) {
        return false;
    }

    if (this->year < 0) {
        return false;
    }


    return true;
}

Date Date::NextDate() {
    Date NextDay = *this;

    if (NextDay.day == NumOfDays[NextDay.month - 1]) {
        NextDay.day = 1;
        if (NextDay.month == 12) {
            NextDay.month = 1;
            NextDay.year += 1;
        } else {
            NextDay.month += 1;
        }
    } else {
        NextDay.day += 1;
    }

    return NextDay;
}

Date Date::PreviousDate() {
    Date PrevDay = *this;

    if (PrevDay.day == 1) {
        if (PrevDay.month == 1) {
            PrevDay.month = 12;
            PrevDay.year -= 1;
        } else {
            PrevDay.month -= 1;
        }
        PrevDay.day = NumOfDays[PrevDay.month - 1];
    } else {
        PrevDay.day -= 1;
    }

    return PrevDay;
}

bool Date::IsLeap() {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

short Date::WeekNumber() {
    return DaysInThisYear()/7 + 1;
}

int Date::DaysTillYourBithday(Date birthdaydate) {
    Date curDate = getTodaysDate();

    int b = 0;
    if (!birthdaydate.IsLeap()) {
        b++;
    }

    if (curDate.month < birthdaydate.month) {
        birthdaydate.year = curDate.year;

    } else if (curDate.month == birthdaydate.month) {
        if (curDate.day <= birthdaydate.day) {
            birthdaydate.year = curDate.year;

        } else {
            birthdaydate.year = curDate.year + 1;
        }
    } else {
        birthdaydate.year = curDate.year + 1;
    }

    if (birthdaydate.day == 29 && birthdaydate.month == 2 && !curDate.IsLeap()) {
        birthdaydate.day = 28;
    }
    b += birthdaydate.Duration(birthdaydate);

    return b;
}

int Date::Duration(Date date) {
    Date curDate = getTodaysDate();

    return abs(date.DateToDays() - curDate.DateToDays());
}

Date StringToDate(QString str) {
    QString day = "", month = "", year = "";
    int dotCnt = 0;

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '.') {
            dotCnt++;
            continue;
        }

        if (dotCnt == 0) {
            day += str[i];
        } else if (dotCnt == 1) {
            month += str[i];
        } else if (dotCnt == 2) {
            year += str[i];
        }
    }

    Date date(day.toInt(), month.toInt(), year.toInt());
    return date;
}

Date Date::getTodaysDate() {
    QString todayDate = QDate::currentDate().toString("dd.MM.yyyy");
    return StringToDate(todayDate);

}


int Date::DaysInThisYear() {
    int days = 0;
    for (int i = 0; i < month - 2; i++) {
        days += NumOfDays[i];
    }

    days += day;

    return days;
}

int Date::DateToDays(){
    int days = 0;
    days += year*365 + (year / 4) - (year / 100) + (year / 400);
    qDebug() << days;
    for (int i = 0; i < month - 1; i++) {
        days += NumOfDays[i];
    }
    days += day;
    return days;

}

QString Date::getDate() {
    QString date = "";
    if (day < 10) {
        date += "0";
    }
    date += QString::number(day) + ".";
    if (month < 10) {
        date += "0";
    }
    date += QString::number(month) + ".";
    if (year < 10) {
        date += "000";
    } else if (year < 100) {
        date += "00";
    } else if (year < 1000) {
        date += "0";
    }
    date += QString::number(year);

    return date;
}

