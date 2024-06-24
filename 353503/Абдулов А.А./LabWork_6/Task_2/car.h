#ifndef AUTO_H
#define AUTO_H

#include "QChar"

struct Car{
    int year;
    double mileage;
    QChar model;
    bool isPassengerCar;
    static const int NAME_SIZE = 20;
    static const int COUNT_OF_WHEELS = 4;
    QChar name[NAME_SIZE];
    int tirePressures[COUNT_OF_WHEELS] = {0, 0, 0, 0};
};

#endif // AUTO_H
