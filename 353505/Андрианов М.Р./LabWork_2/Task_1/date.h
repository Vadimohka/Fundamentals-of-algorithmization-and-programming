#ifndef DATE_H
#define DATE_H

#include <QObject>
#include <QTextEdit>
#include<QDate>
class Date : public QObject
{
    Q_OBJECT

public:
    explicit Date(QObject *parent = nullptr);

    void readDate(QTextEdit *textEdit);
    void onNextDayClicked();
    void onPreviousDayClicked();
    void onIsLeapClicked();
    short weekNumber();

    void addOneDay();
    int daysDifference(const Date& otherDate) const;
    int daysFromEpoch() const;

    int Daysduration(const QDate &birthdayDate);


    QString toString() const;
    void setDate(int day, int month, int year);

private:
    int day_;
    int month_;
    int year_;





signals:
    void nextDayChanged(const QString &nextDay);
    void previousDayChanged(const QString &previousDay);
    void isLeapChanged(const QString &leapStatus);
    void weekNumberChanged(short weekNum);

    void DaysTillYourBirthdayChanged( int daysTillBirthday);

private:
    QTextEdit *textEdit_;

    int daysInMonth(int month, int year)const;
    bool isLeap(int year);
    short calculateWeekNumber(int year, int month, int day);
    int calculateDayOfYear(int year, int month, int day);
    int calculateWeekday(int year, int month, int day);
    int daysInYear(int year)const;




};


#endif // DATE_H
