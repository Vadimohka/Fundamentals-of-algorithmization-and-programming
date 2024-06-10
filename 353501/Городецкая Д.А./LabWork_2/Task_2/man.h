#ifndef MAN_H
#define MAN_H
#include <QString>
// #include "mainwindow.h"
#include "heightrange.h"
#include "weightrange.h"
#include "agerange.h"
struct Man {
    int serialNumber;
    QString name;
    int age;
    int height;
    int weight;
    QString habits;
    QString hobbies;
    AgeRange ageRange;
    HeightRange heightRange;
    WeightRange weightRange;

    Man(int serial, const QString& n, int a, int h, int w, const QString& hab, const QString& hob, const AgeRange& aRange, const HeightRange& hRange, const WeightRange& wRange)
        : serialNumber(serial), name(n), age(a), height(h), weight(w), habits(hab), hobbies(hob), ageRange(aRange), heightRange(hRange), weightRange(wRange)
    {
    }
};
#endif // MAN_H
