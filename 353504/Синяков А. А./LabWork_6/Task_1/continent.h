#ifndef CONTINENT_H
#define CONTINENT_H

struct Continent {
    int area;
    double averageHeight;
    char firstLetter;
    bool hasOceanCoast;
    static const int stringLength = 20;
    char name[stringLength];
    static const int climateDataSize = 5;
    int climateData[climateDataSize];
};

#endif // CONTINENT_H
