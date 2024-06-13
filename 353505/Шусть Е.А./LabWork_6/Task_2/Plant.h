#ifndef PLANT_H
#define PLANT_H

#include <QString>

constexpr short MAX_ANOUNT_PLANT = 10;

struct Plant
{
    int age;                               // возраст планеты
    double height;                         // высота планеты
    char vitamin;                          // Состоит ли в солнечной системе
    bool isFlowering;                      // цветет ли растение
    static QString name[MAX_ANOUNT_PLANT]; // название планеты
    static int nutrients[MAX_ANOUNT_PLANT]; // Номер

    Plant();
    Plant(int age, double height, char vitamin, bool isFlowering);
    QString plantToString();
    void clear();
};

#endif // PLANT_H
