#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>

struct House
{
    int floors;
    double area;
    char type;
    bool hasGarage;
    static char address[100];
    static int rooms[10];
};

#endif // HOUSE_H
