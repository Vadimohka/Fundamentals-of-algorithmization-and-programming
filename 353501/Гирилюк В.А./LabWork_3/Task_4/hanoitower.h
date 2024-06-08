#ifndef HANOITOWER_H
#define HANOITOWER_H

#include <QGraphicsScene>
#include <QCoreApplication>

#include "disk.h"

class HanoiTower: public QGraphicsScene
{
public:
    bool running = false;
    HanoiTower();
    void setHeight(int n);
    void hanoi(int diskCount, QChar from, QChar to, QChar temp);
    int height = 225;
    int width = 200;
    int disksCount = 3;
    void hanoi(int diskCount);
    Disk *movable = nullptr;
    QVector<Disk*> A;
    QVector<Disk*> B;
    QVector<Disk*> C;
};

#endif // HANOITOWER_H
