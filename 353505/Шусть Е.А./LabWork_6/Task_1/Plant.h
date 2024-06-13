#ifndef PLANT_H
#define PLANT_H

#include <QString>

constexpr short MAX_ANOUNT_PLANT = 10;

struct Plant
{
    int age;                               // Возраст планеты
    double height;                         // Высота растения
    char number;                          //
    bool SolarSystem;                      // Находиться ли в Солнечной системе
    static QString name[MAX_ANOUNT_PLANT]; // Название планеты
    static int nutrients[MAX_ANOUNT_PLANT]; // Номер

    Plant();
    Plant(int age, double height, char number, bool SolarSystem);
    QString plantToString();
    void clear();
};

#endif // PLANT_H
