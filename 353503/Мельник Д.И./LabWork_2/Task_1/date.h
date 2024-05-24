#ifndef DATE_H
#define DATE_H

#include<QString>

#include <string>

using std::string;

class Date {
private:
    int _day;
    int _month;
    int _year;

public:
    Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}

    ~Date() = default;

    auto static DaysInMonth(int month, int year) -> int;

    auto toQString() -> QString; /* Преобразует в строку QString    */
    auto previousDay() -> QString; /* Определяет дату предыдущего дня */
    auto nextDay() -> QString; /* Определяет дату следующего  дня */

    auto daysTillYourBithday(const Date &bithdaydate) -> int; /* сколько дней до вашего дня рождения от текущей даты */
    auto duration(const Date &date) -> int;                  /* количество дней между текущей и данной датой        */

    auto weekNumber() -> short; /* номер недели в году для текущей даты */
    auto isLeap() -> bool;  /* является ли год этой даты высокосным */

    auto getDay() -> int { return this->_day; }

    auto getMonth() -> int { return this->_month; }

    auto getYear() -> int { return this->_year; }
};

#endif // DATE_H

/* дан текстовый файл с датами
 * (01.01.0001 24.04.2000 29.02.2000 31.12.2021). Прочитать данные в динамический
 * массив объектов класса и для каждого элемента коллекции вычислить
 * а) следующий день
 * б) разницу между текущим и следующим элементом коллекции
 * С помощью оконного приложения вывести на экран информацию о датах в файле таблицей. По
 * кнопке вызывать функции класса и выводить информацию на экран. Текущий день
 * вычислять через время из системы или использовав стандартные функции. Добавить в
 * форму поле для ввода даты рождения пользователя. Добавить функцию изменения и
 * добавления дат в файл без полной перезаписи и соответствующий функционал в формах.
 * Добавить функцию открытия .txt файла из любого дискового пространства. Функция
 * открытия файла должна работать через методы оконных приложений. */
