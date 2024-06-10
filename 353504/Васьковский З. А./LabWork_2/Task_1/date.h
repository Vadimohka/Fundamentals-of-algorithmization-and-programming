#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
class Date
{
public:
    Date(int day,int month,int year);
    ~Date();

    Date NextDay();
    Date PreviousDate();
    static Date getCurrentTime();

    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date birthdaydate);
    int Duration(Date date1,Date date2);

    QString formatDate(const Date& date);
    static QVector<Date> readDatesFromFile(const QString& fileName);
    void addDateToFile(const QString &fileName, const Date &date);
    void writeDateToFile(const QString &fileName, const Date &date,int position);
    static void removeDateFromFile(const QString &filename);
    static bool isValidDate(int day,int month,int year);
    static void clearFile(const QString& filename);


    int getDay() const;
    int getMonth() const;
    int getYear() const;
private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
