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
    void heapify(int size, int i);
    void heapSort(int size);
    void quickSort(int begin, int end);
    void merge(int const left, int const mid, int const right);
    void mergeSort(const int begin, const int end);
};

#endif // GRAPHICSORT_H
