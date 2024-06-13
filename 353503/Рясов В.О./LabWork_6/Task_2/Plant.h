#ifndef PLANT_H
#define PLANT_H

#include <QString>

constexpr short MAX_ANOUNT_PLANT = 10;

struct Plant
{
    int age;                               // возраст растения
    double height;                         // высота растения
    char vitamin;                          //
    bool isFlowering;                      // цветет ли растение
    static QString name[MAX_ANOUNT_PLANT]; // название растения
    static int nutrients[MAX_ANOUNT_PLANT]; // питательные вещества растения

    Plant();
    Plant(int age, double height, char vitamin, bool isFlowering);
    QString plantToString();
    void clear();
};

#endif // PLANT_H
