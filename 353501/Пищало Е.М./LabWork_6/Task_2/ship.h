#ifndef AUTO_H
#define AUTO_H

#include "QChar"

struct Ship
{
    int year;
    double cost;
    char generation;
    bool isAvailable;
    static const int MAX_NAME_SIZE = 16;
    static const int MAX_LEVELS_SIZE = 4;
    char name[MAX_NAME_SIZE];
    int passengersPerLevel[MAX_LEVELS_SIZE] = {0,0,0,0};
};

#endif // AUTO_H
