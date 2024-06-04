#include "date.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QRegularExpression>
#include <QMessageBox>
Date::Date(QObject *parent) : QObject(parent), textEdit_(nullptr) {}

void Date::readDate(QTextEdit *textEdit) {
    textEdit_ = textEdit;
}

int Date::daysInMonth(int month, int year) const{
    if (month == 2) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

bool Date::isLeap(const int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

short Date::calculateWeekNumber(int year, int month, int day) {
    // Вычисляем день года
    int dayOfYear = calculateDayOfYear(year, month, day);

    // Определяем номер недели в году
    int jan1Weekday = calculateWeekday(1, 1, year);
    int weekNum = (dayOfYear + jan1Weekday - 1) / 7 + 1;

    // Учитываем случаи, когда первая неделя начинается в предыдущем году
    if (jan1Weekday > 4) {
        weekNum--;
    }

    return static_cast<short>(weekNum);
}




int Date::calculateDayOfYear(int year, int month, int day) {
    // Определяем количество дней в предыдущих месяцах
    int daysInMonths = 0;
    for (int m = 1; m < month; ++m) {
        daysInMonths += daysInMonth(m, year);
    }

    // Добавляем дни текущего месяца
    int dayOfYear = daysInMonths + day;

    // Корректируем количество дней в случае високосного года
    if (isLeap(year) && month > 2) {
        dayOfYear++;
    }

    return dayOfYear;
}

int Date::calculateWeekday(int year, int month, int day) {
    // Алгоритм Зеллера
    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (h + 6) % 7; // Понедельник - 0, Воскресенье - 6
}






void Date::onNextDayClicked() {
    if (textEdit_) {
        QString text = textEdit_->toPlainText();
        QRegularExpression regex("(\\d{1,2})\\.(\\d{1,2})\\.(\\d{4})");
        QRegularExpressionMatch match = regex.match(text);
        if (match.hasMatch()) {
            int day = match.captured(1).toInt();
            int month = match.captured(2).toInt();
            int year = match.captured(3).toInt();

            int maxDay = daysInMonth(month, year);

            if (day < 1 || day > maxDay || month < 1 || month > 12 || year < 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Некорректная дата!\n"
                                                         " Неверно указан день");
                return;
            }

            day++;
            if (day > maxDay) {
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }

            QString nextDayText = QString("%1.%2.%3").arg(day, 2, 10, QLatin1Char('0'))
                                      .arg(month, 2, 10, QLatin1Char('0'))
                                      .arg(year, 4, 10, QLatin1Char('0'));

            emit nextDayChanged(nextDayText);
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Некорректный формат даты!\n"
                                                     " ДД.ММ.ГГГГ");
        }
    }
}



void Date::onPreviousDayClicked() {
    if (textEdit_) {
        QString text = textEdit_->toPlainText();
        QRegularExpression regex("(\\d{1,2})\\.(\\d{1,2})\\.(\\d{4})");
        QRegularExpressionMatch match = regex.match(text);
        if (match.hasMatch()) {
            int day = match.captured(1).toInt();
            int month = match.captured(2).toInt();
            int year = match.captured(3).toInt();

            int maxDay = daysInMonth(month, year);

            if (day < 1 || day > maxDay || month < 1 || month > 12 || year < 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Некорректная дата!\n"
                                                         " Неверно указан день, месяц или год");
                return;
            }

            day--;
            if (day < 1) {
                month--;
                if (month < 1) {
                    month = 12;
                    year--;
                }
                day = daysInMonth(month, year);
            }

            QString previousDayText = QString("%1.%2.%3").arg(day, 2, 10, QLatin1Char('0'))
                                          .arg(month, 2, 10, QLatin1Char('0'))
                                          .arg(year, 4, 10, QLatin1Char('0'));

            emit previousDayChanged(previousDayText);
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Некорректный формат даты!\n"
                                                     " ДД.ММ.ГГГГ");
        }
    }
}


void Date::onIsLeapClicked() {
    if (textEdit_) {
        QString text = textEdit_->toPlainText();
        QRegularExpression regex("(\\d{1,2})\\.(\\d{1,2})\\.(\\d{4})");
        QRegularExpressionMatch match = regex.match(text);
        if (match.hasMatch()) {
            int year = match.captured(3).toInt();


            bool leap = isLeap(year);
            QString leapStatus = leap ? "Да" : "Нет";

            emit isLeapChanged(leapStatus);
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Некорректный формат даты!\n"
                                                     " ДД.ММ.ГГГГ");
        }
    }
}

short Date::weekNumber() {
    if (textEdit_) {
        QString text = textEdit_->toPlainText();
        QRegularExpression regex("(\\d{1,2})\\.(\\d{1,2})\\.(\\d{4})");
        QRegularExpressionMatch match = regex.match(text);
        if (match.hasMatch()) {
            int day = match.captured(1).toInt();
            int month = match.captured(2).toInt();
            int year = match.captured(3).toInt();

            if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Некорректная дата!\n"
                                                         " Неверно указан день, месяц или год");
                return -1;
            }

            short weekNum = calculateWeekNumber(year, month, day);
            QString weekNumText = QString::number(weekNum);

            emit weekNumberChanged(weekNum);
            return weekNum;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Некорректный формат даты!\n"
                                                     " ДД.ММ.ГГГГ");
        }
    }
    return -1;
}


int  Date::Daysduration(const QDate &birthdayDate) {
    if (!textEdit_) {
        // Проверяем, что textEdit инициализирован
        return -1;
    }

    QString currentText = textEdit_->toPlainText();
    QRegularExpression regex("(\\d{1,2})\\.(\\d{1,2})\\.(\\d{4})");
    QRegularExpressionMatch currentMatch = regex.match(currentText);
    if (!currentMatch.hasMatch()) {
        // Некорректный формат даты в textEdit, вернем -1
        return -1;
    }
    int currentDay = currentMatch.captured(1).toInt();
    int currentMonth = currentMatch.captured(2).toInt();
    int currentYear = currentMatch.captured(3).toInt();

    QDate currentDate(currentYear, currentMonth, currentDay);
    int daysTillBirthday = currentDate.daysTo(birthdayDate);

    emit DaysTillYourBirthdayChanged(daysTillBirthday);

    return daysTillBirthday;
}
//----------------------------------------------------------------------------------------------------------------------------------------

QString Date::toString() const {
    return QString("%1.%2.%3").arg(day_, 2, 10, QLatin1Char('0'))
        .arg(month_, 2, 10, QLatin1Char('0'))
        .arg(year_, 4, 10, QLatin1Char('0'));
}

void Date::setDate(int day, int month, int year) {
    day_ = day;
    month_ = month;
    year_ = year;
}
void Date::addOneDay() {
    day_++;

    if (day_ > daysInMonth(month_, year_)) {
        day_ = 1;
        month_++;

        if (month_ > 12) {
            month_ = 1;
            year_++;
        }
    }
}

int Date::daysDifference(const Date& otherDate) const {
    // Преобразуем обе даты в количество дней от начала эры
    int days1 = daysFromEpoch();
    int days2 = otherDate.daysFromEpoch();

    // Вычисляем разницу в днях
    int difference = days1 - days2;

    // Возвращаем абсолютное значение разницы
    return qAbs(difference);
}


int Date::daysFromEpoch() const {
    int days = 0;

    // Прибавляем количество дней от начала эры до начала текущего года
    for (int year = 1; year < year_; ++year) {
        days += daysInYear(year);
    }

    // Прибавляем количество дней от начала текущего года до текущей даты
    for (int month = 1; month < month_; ++month) {
        days += daysInMonth(month, year_);
    }

    days += day_ - 1; // Добавляем дни текущего месяца
    return days;
}

int Date::daysInYear(int year) const{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 366 : 365;
}
