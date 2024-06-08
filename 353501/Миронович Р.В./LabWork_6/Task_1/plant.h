#ifndef PLANT_H
#define PLANT_H

struct Plant {
    int area;
    double averageHeight;
    char firstLetter;
    bool fruit;
    static const int stringLength = 20;
    char name[stringLength];
    static const int climateDataSize = 5;
    int climateData[climateDataSize];
};

#endif // PLANT_H
