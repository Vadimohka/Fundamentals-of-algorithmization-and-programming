#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QSet>
#include <QFileDialog>
class Date
{
public:
    Date(QString);

    Date(int, int, int);

    Date* nextday();

    Date* previousDate();

    QString getDate();

    int daysTillYourBirthday(Date* birthdayDate);

    QString getDuration(Date* current);

    QString getWeekNumber();

    bool isCorrect();

private:

    QString date;

    int day = 1;

    int month = 1;

    int year = 1;

    void setDate();

    bool isLeap();

    short weekNumber();

    QSet <int> mon30 = {4, 6, 9, 11};

    int duration(Date* current);
};




#endif // DATE_H
