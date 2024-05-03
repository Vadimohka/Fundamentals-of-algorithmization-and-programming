#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QVector>
#include <QMessageBox>

class Date
{
private:
    int years, months, days;
    QString date;
    long long datedays=0;
    int monthdays[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    void DaysInDate();
    Date *temp;
public:
    Date(int dayd,int monthd,int yeard);
    ~Date();
    Date NextDay();
    Date PreviousDay();
    bool qstoi();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBithday(Date *bithdaydate);
    int Duration (Date date);

    void setDate(QString date);
    void setYear(int years);
    void setMonth(int months);
    void setDay(int days);

    int getYear();
    int getMonth();
    int getDay();
    int getDateDays();
    QString getDate();

    QString dateToStandart();



};

#endif // DATE_H
// Определите и реализуйте следующие методы этого класса:
// • Date NextDay() – определить дату следующего дня;
// • Date PreviousDay() – определить дату предыдущего дня, bool IsLeap() – является
//     ли год этой даты високосным, short WeekNumber() – номер недели в году для
//     текущей даты;
// • int DaysTillYourBithday(Date bithdaydate) – сколько дней до вашего дня рождения
//     от текущей даты;
// • int Duration (Date date) – количество дней между текущей и данной датой.
// Далее необходимо выполнить следующее задание:
//дан текстовый файл с датами

// (01.01.0001 24.04.2000 29.02.2000 31.12.2021). Прочитать данные в динамический
// массив объектов класса и для каждого элемента коллекции вычислить а) следующий
// день, б) разницу между текущим и следующим элементом коллекции. С помощью
// оконного приложения вывести на экран информацию о датах в файле таблицей.

// По кнопке вызывать функции класса и выводить информацию на экран.

// Текущий день вычислять через время из системы или использовав стандартные функции.

// Добавить в форму поле для ввода даты рождения пользователя. Добавить функцию изменения и добавления дат в файл без полной перезаписи и соответствующий функционал в формах.

// Добавить функцию открытия .txt файла из любого дискового пространства.
// Функция открытия файла должна работать через методы оконных приложений.
