#ifndef WATCHES_H
#define WATCHES_H

#include <QString>

struct Watches
{
    int hours;
    int minutes;
    int seconds;
    const char *name;
    char serialLetter;
    double serialNumber;
    bool waterResistance;
    int detailsNumbers[5];

    QString toString()
    {
        QString str = {"Время: " + QString::number(hours) + ":" + QString::number(minutes) + ":"
                       + QString::number(seconds) + "\nНазвание: " + QString(name)
                       + "\nСерия: " + QString(serialLetter) + QString::number(serialNumber)};
        str.push_back("\nВлагозащита: " + QString(waterResistance ? "Есть" : "Нет"));
        str.push_back("\nНомера деталей: ");
        for (int i : detailsNumbers) {
            str.push_back(QString::number(i) + ", ");
        }
        str.chop(2);
        return str;
    }
};

#endif // WATCHES_H
