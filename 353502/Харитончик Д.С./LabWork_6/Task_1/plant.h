#ifndef PLANT_H
#define PLANT_H

struct Plant
{
    int age;
    double height;
    char category;
    bool isHealthy;
    char name[50];
    int humidity[50];
};

#endif // PLANT_H
