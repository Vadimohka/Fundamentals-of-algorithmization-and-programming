#ifndef DATE_H
#define DATE_H
#include <QDate>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QLabel>

class Date
{
public:
public:
    Date();
    static QDate previousDay(const QDate &currentDate);
    static bool isLeap(const QDate &date);
    static short weekNumber(const QDate &date);
    static QDate nextDay(QDate currentDate);
    static int calculateBirth(QDate currentDate, QDate birthDate);
private:

    QDate arr[];
};

#endif // DATE_H
