#ifndef CITY_H
#define CITY_H

#include <QString>

struct City {
    int population;
    double area;
    char category;
    bool isCapital;
    static const int maxNameLength = 50;
    static const int numFeatures = 3;
    char name[maxNameLength];
    int features[numFeatures];
    int a = 'A';
};

#endif // CITY_H
