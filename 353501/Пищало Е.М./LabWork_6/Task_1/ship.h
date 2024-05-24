#ifndef SHIP_H
#define SHIP_H

#include "QChar"

struct Ship
{
    int year;
    double cost;
    QChar generation;
    bool isAvailable;
    static const int MAX_NAME_SIZE = 16;
    static const int MAX_LEVELS_SIZE = 4;
    QChar name[MAX_NAME_SIZE] = {'s', 'h', 'i', 'p'};
    int passengersPerLevel[MAX_LEVELS_SIZE] = {0,0,0,0};
};

#endif // SHIP_H
