#ifndef HEAPSORTER_H
#define HEAPSORTER_H
#include <QVector>
#include "swapanimator.h"

class HeapSorter
{
public:
    HeapSorter();
private:
    void static heapify(QVector<int>&, int, int);
public:
    void static Sort(QVector<int>&);
    void static SortAnimation(QVector<int>&, QVector<QVector<int>>&);
};

#endif // HEAPSORTER_H
