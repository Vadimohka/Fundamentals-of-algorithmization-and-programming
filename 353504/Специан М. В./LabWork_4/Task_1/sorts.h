#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <svector.h>

class Sorts
{
public:
    static void quickSort(SVector&, int, int);
    static void heapSort(SVector&);
    static void mergeSort(SVector&, int, int);
    static int binsearch(SVector&, int);
};

#endif // SORTS_H
