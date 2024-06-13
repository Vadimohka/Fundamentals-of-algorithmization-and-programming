#ifndef HEAPSORTING_H
#define HEAPSORTING_H

#include "abstractsorting.h"
class HeapSorting : public AbstractSorting
{
public:
    HeapSorting();

private:
    void static heapify(QVector<int>&, int, int, QHBoxLayout* = nullptr) ;

public:
    void static sort(QVector<int>&, QHBoxLayout* = nullptr);


    //void static SortAnimation(QVector<int>&, QVector<QVector<int>>&, QHBoxLayout* = nullptr);
};

#endif // HEAPSORTING_H
