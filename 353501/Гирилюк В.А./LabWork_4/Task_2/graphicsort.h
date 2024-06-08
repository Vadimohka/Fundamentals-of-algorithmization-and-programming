#ifndef GRAPHICSORT_H
#define GRAPHICSORT_H

#include <QGraphicsScene>
#include <QGraphicsObject>
#include <iostream>
#include <QThread>
#include <QCoreApplication>

#include "rect.h"

class GraphicSort: public QGraphicsScene
{
public:
    QVector<int> array;
    QVector<Rect*> rectArray;
    GraphicSort();
    bool running = false;
    bool isSorted() const;
    void setSize(int size);
    void swap(int i, int j);
    int binSearch(int digit);
    int binPow(int digit, int powder, int mod);
    void interpolationSort();

};

#endif // GRAPHICSORT_H
