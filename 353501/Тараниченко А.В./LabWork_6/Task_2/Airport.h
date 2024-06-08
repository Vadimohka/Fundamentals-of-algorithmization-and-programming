#ifndef AIRPORT_H
#define AIRPORT_H

struct Airport {
    int terminals;                                             // Количество терминалов
    double area;                                               // Площадь аэропорта
    char code;                                                 // Код аэропорта
    bool hasParking;                                           // Наличие парковки
    static const int MAX_CHAR_ARRAY_SIZE = 30;                 // Максимальный размер символьного массива
    static const int MAX_LONG_LONG_ARRAY_SIZE = 5;             // Максимальный размер массива целых чисел
    static char managementOfficeAddress[MAX_CHAR_ARRAY_SIZE];  // Адрес управления аэропортом
    static long long passengerCount[MAX_LONG_LONG_ARRAY_SIZE]; // Массив с количеством пассажиров по годам
};
#endif // AIRPORT_H
