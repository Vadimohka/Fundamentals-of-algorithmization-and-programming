#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QMessageBox>
#include <QDialog>
//#include <QtGlobal>

class Date : public QString
{
public:
    Date(QString dateTransfer, bool leapYear, int dayTransfer, int monthTransfer, int yearTransfer);
    QString DateOutput();
    bool IsLeapYear();
public slots:
    QString NextDate();
    int WeekNumber();
    QString PreviousDate();
    int DaysTillYourBirthday(Date birthdaydate);
    int Duration (Date dateSecond);
private:
    int TransferDateToDay();
protected:
    QString dateUsed;
    bool IsLeap;
    bool checked = false;
    int day;
    int month;
    int year;
};

#endif // DATE_H
