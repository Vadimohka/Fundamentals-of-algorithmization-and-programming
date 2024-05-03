#include <date.h>
#include <QDebug>

Date::Date()
{

}

Date::Date(int valueDay, int valueMonth, int valueYear) {
    year = valueYear;
    month = valueMonth;
    day = valueDay;
}

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

void Date::setDay(int newDay) {
    day = newDay;
}

void Date::setMonth(int newMonth) {
    day = newMonth;
}

void Date::setYear(int newYear) {
    day = newYear;
}

Date Date::NextDay() {
    int newDay = getDay();
    int newMonth = getMonth();
    int newYear = getYear();

    std::vector<int> arrDayIntMonth = getVectorDayIntMonth(year);
    newDay++;

    if(newDay > arrDayIntMonth[newMonth - 1]) {
        newDay -= (arrDayIntMonth[newMonth - 1]);
        newMonth++;
    }
    if(newMonth > NumberMonthInYear) {
        newMonth -= NumberMonthInYear;
        newYear++;
    }
    Date nextDay(newDay, newMonth, newYear);

    return nextDay;
}

Date Date::PreviousDay() {
    int newDay = getDay();
    int newMonth = getMonth();
    int newYear = getYear();
    newDay--;
    std::vector<int> arrDayIntMonth = getVectorDayIntMonth(year);
    if(newDay < 1) {
        newMonth--;
        if(newMonth <= 0) {
            newMonth += NumberMonthInYear;
            newYear--;
        }
        newDay = arrDayIntMonth[newMonth - 1];
    }
    Date previosDay(newDay, newMonth, newYear);
    return previosDay;
}

int Date::getQuantityYearBetweenTime(int leftBorderYear, int rightBorderYear) { //correct
    leftBorderYear++;
    rightBorderYear--;
    if(rightBorderYear - leftBorderYear < 0) {
        return 0;
    }
    else {
        int valueQuantityYearBetweenTime = 0;
        int firstYearMiltiplesFour = leftBorderYear + (NumberFirstTypeOfSetFour - leftBorderYear % NumberFirstTypeOfSetFour);
        int quantityYearMultiplesFour = (rightBorderYear - firstYearMiltiplesFour + NumberFirstTypeOfSetFour) / NumberFirstTypeOfSetFour;

        int firstYearMiltiplesHundred = leftBorderYear + (NumberSecondTypeOfSetOneHundred - leftBorderYear % NumberSecondTypeOfSetOneHundred);

        int quantityYearMultiplesHundred = (rightBorderYear - firstYearMiltiplesHundred + NumberSecondTypeOfSetOneHundred) / NumberSecondTypeOfSetOneHundred;
        if(quantityYearMultiplesFour - quantityYearMultiplesHundred > 0) {
            valueQuantityYearBetweenTime += quantityYearMultiplesFour - quantityYearMultiplesHundred;
        }
        int firstYearMiltiplesFourHundred = leftBorderYear + (NumberThirdTypeOfSetFourHundred - leftBorderYear % NumberThirdTypeOfSetFourHundred);

        int quantityYearMultiplesFourHundred = (rightBorderYear - firstYearMiltiplesFourHundred + NumberThirdTypeOfSetFourHundred) / NumberThirdTypeOfSetFourHundred;
        if(quantityYearMultiplesFourHundred > 0) {
            valueQuantityYearBetweenTime += quantityYearMultiplesFourHundred;
        }
        return valueQuantityYearBetweenTime;
    }
}

bool Date::IsLeap() {
    if((year % NumberFirstTypeOfSetFour == 0 && year % NumberSecondTypeOfSetOneHundred != 0) || year % NumberThirdTypeOfSetFourHundred == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::IsLeap(int year) {
    if(year % NumberFirstTypeOfSetFour == 0 && year % NumberSecondTypeOfSetOneHundred != 0) {
        return true;
    }
    else {
        return false;
    }
}

Date Date::getNowDate() {
    long valueYear = StartNumberToCountNowYear;
    long valueMonth = StartNumberToCountNowMonth;
    long valueDay = StartNumberToCountNowDay;

    time_t rawtime;
    time (&rawtime);

    rawtime += 3 * NumberSecondsInHour;

    valueYear += 4 * (rawtime / NumberSecondsInFourYear);

    rawtime -= (rawtime / NumberSecondsInFourYear) * NumberSecondsInFourYear;
    while(rawtime > NumberSecondsInFourYear ) {
        rawtime -= NumberSecondsInFourYear;
        valueYear+= 4;
    }

    while(rawtime > NumberSecondsInYear ) {
        rawtime -= NumberSecondsInYear;
        valueYear++;
    }

    std::vector<int> arrDayIntMonth = getVectorDayIntMonth(valueYear);
    for (int i = 0; i < 12; i++) {
        int valueSecondSomeMonth = arrDayIntMonth[i] * NumberSecondsInDay;
        if(rawtime > valueSecondSomeMonth) {
            rawtime -= valueSecondSomeMonth;
            valueMonth++;
        }
        else {
            break;
        }
    }
    valueDay += rawtime / NumberSecondsInDay;

    rawtime -= (valueDay - 1) * NumberSecondsInDay;

    Date nowDate(valueDay, valueMonth, valueYear);

    nowYear = valueYear;
    nowMonth = valueMonth;
    nowDay = valueDay;
    nowHour = rawtime / NumberSecondsInHour;
    rawtime -= nowHour * NumberSecondsInHour;
    nowMinute = rawtime / NumberSecondsInMinute;
    nowSecond = rawtime - nowMinute * NumberSecondsInMinute;

    return nowDate;
}

std::vector<int> Date::getVectorDayIntMonth(int year) {
    std::vector<int> a = {NumberDateFirstMonth, NumberDateSecondMonth,
                          NumberDateThirdMonth, NumberDateFourthMonth,
                          NumberDateFivethMonth, NumberDateSixthMonth,
                          NumberDateSeventhMonth, NumberDateEighthMonth,
                          NumberDateNinthMonth, NumberDateTenthMonth,
                          NumberDateEleventhMonth, NumberDateTwelfthMonth};
    if(IsLeap(year) == true) a[1]++;
    return a;
}

QString Date::getNameDayOfWeek() {
    int numberNowDayPresentCentury = 0;
    std::vector<int> dayIntMonth = getVectorDayIntMonth(year);
    int numberDayInFullYear = getQuantityYearBetweenTime(0, year) * NumberDayInLeapYear +
            (year - getQuantityYearBetweenTime(0, year) - 1) * NumberDayInNotLeapYear;
    numberNowDayPresentCentury += numberDayInFullYear;
    for (int i = 0; i < month - 1; i++) {
        numberNowDayPresentCentury += dayIntMonth[i];
    }
    numberNowDayPresentCentury += day - 1;
    numberNowDayPresentCentury =  numberNowDayPresentCentury % NumberDayInWeek;
    return  arrDayWeek[numberNowDayPresentCentury];
}

bool Date::isSecondDateMoreFirst(Date firstDate, Date secondDate) {
    if(secondDate.getYear() > firstDate.getYear()) {
        return true;
    }
    else if(secondDate.getYear() == firstDate.getYear()) {
        if(secondDate.getMonth() > firstDate.getMonth()) {
            return true;
        }
        else if(secondDate.getMonth() == firstDate.getMonth()) {
            if(secondDate.getDay() >= firstDate.getDay()) {
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

int Date::daysTillYourBithday(Date birthdayDate) {
    int valueDaysTillYourBithday = 0;
    Date date(day,month,year);
    birthdayDate.year = date.year;
    if(isSecondDateMoreFirst(birthdayDate, date)) {
        birthdayDate.year++;
    }

    std::vector<int> vectorDayIntMonth = getVectorDayIntMonth(birthdayDate.year);
    int valueCalculationYear = birthdayDate.year - date.year;
    //qDebug() << "valueCalculationYear = " << valueCalculationYear << '\n';

    int valueCalculationMonth = (birthdayDate.month - date.month + valueCalculationYear * NumberMonthInYear) % NumberMonthInYear;

    //qDebug() << "valueCalculationMonth = " << valueCalculationMonth << '\n';
    int valueCalculationDay = birthdayDate.day - date.day;
    //qDebug() << "valueCalculationDay = " << valueCalculationDay << '\n';

    for(int i = 0; i < valueCalculationMonth; i++) {
        valueDaysTillYourBithday += vectorDayIntMonth[(i + date.month) % NumberMonthInYear];
    }
    valueDaysTillYourBithday += valueCalculationDay;
    int numberDayInYear = NumberDayInNotLeapYear + IsLeap(birthdayDate.year);
    if(valueDaysTillYourBithday < 0) valueDaysTillYourBithday = numberDayInYear + valueDaysTillYourBithday;
    valueDaysTillYourBithday %= NumberDayInNotLeapYear;
    if(birthdayDate.day == NumberDayFebruaryLeap && birthdayDate.month == 2)  {
        valueDaysTillYourBithday += 3 * NumberDayInNotLeapYear - 1;
    }
    return valueDaysTillYourBithday;
}

bool Date::isTwoDateSame(Date firstDate, Date secondDate) {
    return (firstDate.day == secondDate.day && firstDate.month == secondDate.month && firstDate.year == secondDate.year);
}

int Date::WeekNumber() {
    int valueWeekNumber = 0;
    QString nameFirstDayYear = getNameDayOfWeek();
    if(nameFirstDayYear == ("Thusday" || "Friday" || "Saturday" || "Sunday")) {
        valueWeekNumber++;
    }
    int dayWithoutMonth = 0;
    std::vector<int> arrDayIntMonth = getVectorDayIntMonth(year);
    for(int i = 0; i < month; i++) {
        dayWithoutMonth += arrDayIntMonth[i];
    }
    dayWithoutMonth += day - 1;
    valueWeekNumber += dayWithoutMonth / NumberDayInWeek;
    return valueWeekNumber;
}

int Date::Duration() {
    int valueDuration = 0;

    Date nowDate = getNowDate();

    bool isPositiveYear = 0;
    if(year > nowDate.year) isPositiveYear = 1;

    int numberQuantityYear = getQuantityYearBetweenTime(year, nowDate.year);
    valueDuration += numberQuantityYear * NumberDayInLeapYear;
    if(qMax(year,nowDate.year) > qMin(nowDate.year, year) + 1) {
        valueDuration += (year  - nowDate.year - 2 - numberQuantityYear) * NumberDayInNotLeapYear;
    }
    if(isPositiveYear == false)  valueDuration *= -1;

    bool isPositiveMonth = 0;
    if(month > nowDate.month) isPositiveMonth = 1;

    int dayWithoutMonth = 0;
    std::vector<int> arrDayIntMonth = getVectorDayIntMonth(year);
    for(int i = qMin(month, nowDate.month); i < qMax(month,nowDate.month); i++) {
        dayWithoutMonth += arrDayIntMonth[i];
    }
    if(isPositiveMonth == false) {
        dayWithoutMonth *= -1;
    }

    dayWithoutMonth += day - nowDate.day;
    valueDuration += dayWithoutMonth;

    return valueDuration;
}

Date Date::fromString(QString strDate) {
    QString strDay = "";
    QString strMonth = "";
    QString strYear = "";

    int ptr = 0;

    for(; ptr < strDate.size() && strDate[ptr].isDigit(); ptr++) {
        strDay += strDate[ptr];
    }

    ptr++;

    for(; ptr < strDate.size() && strDate[ptr].isDigit(); ptr++) {
        strMonth += strDate[ptr];
    }

    ptr++;

    for(; ptr < strDate.size() && strDate[ptr].isDigit(); ptr++) {
        strYear += strDate[ptr];
    }

    day = strDay.toInt();
    month = strMonth.toInt();
    year = strYear.toInt();

    Date date(strDay.toInt(), strMonth.toInt(), strYear.toInt());
    return date;
}

QString Date::toString() {
    QString strDay = QVariant(getDay()).toString();
    QString strMonth =  QVariant(getMonth()).toString();
    QString strYear = QVariant(getYear()).toString();

    if(day == 0 || month == 0 || year == 0) {
        return "--.--.----";
    }
    while(strDay.size() < 2) {
        strDay = '0' + strDay;
    }
    while(strMonth.size() < 2) {
        strMonth = '0' + strMonth;
    }
    while(strYear.size() < 4) {
        strYear = '0' + strYear;
    }
    QString result = strDay + '.' + strMonth + '.' + strYear;

    return result;
}

QString Date::getStrNowDate() {
    getNowDate();
    Date date(nowDay, nowMonth, nowYear);
    return date.toString();
}

QString Date::getStrNowTime() {
    getNowDate();
    QString strHour = QVariant(nowHour).toString();
    QString strMinute =  QVariant(nowMinute).toString();
    QString strSecond = QVariant(nowSecond).toString();

    while(strSecond.size() < 2) {
        strSecond = '0' + strSecond;
    }
    while(strMinute.size() < 2) {
        strMinute = '0' + strMinute;
    }
    while(strHour.size() < 2) {
        strHour = '0' + strHour;
    }
    QString result = strHour + '.' + strMinute + '.' + strSecond;

    return result;
}
