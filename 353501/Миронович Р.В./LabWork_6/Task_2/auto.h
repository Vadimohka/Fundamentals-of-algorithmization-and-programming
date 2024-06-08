#ifndef AUTO_H
#define AUTO_H

#include "QChar"

struct Auto
{
    int year;
    double cost;
    char model;
    bool isPassengerCar;
    static const int MAX_NAME_SIZE = 16;
    static const int MAX_WHEELS_SIZE = 4;
    char name[MAX_NAME_SIZE];
    int wheelsYear[MAX_WHEELS_SIZE] = {0,0,0,0};
};

#endif // AUTO_H
