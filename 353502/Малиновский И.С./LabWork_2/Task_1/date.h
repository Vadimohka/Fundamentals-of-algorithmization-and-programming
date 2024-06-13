#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QDebug>

const QStringList headers = {"Дата", "Дата следующего дня", "Дата предыдущего дня", "Является ли год весокосным", "Номер недели в году", "Количество дней до дня рождения", "Разница между датами"};
class Date : public QDate
{
public:
    Date(const QDate &date);
    Date() : QDate()
    {
        setDate(0, 0, 0);
    }
    Date(int year, int month, int day) : QDate(year, month, day) {}
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    int16_t WeekNumber();
    int DaysTillYourBithday(Date bithdayDate);
    int Duration(Date date);
    void ConvertToDate(const QString &str);
    QString ConvertToString();
};

#endif // DATE_H
