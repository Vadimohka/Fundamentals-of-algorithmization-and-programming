#ifndef SORTER_H
#define SORTER_H

#include "SVector.h"

class Sorter{

private:
    static bool _terminated;
    //for HeapSort
    static void _heapify(SVector& vect, size_t root, size_t last);
    static void _build_heap(SVector& vect, size_t lasts);

    //for MergeSort
    static void _mergeSort(SVector& vect, size_t beg, size_t end);

    //for QuickSort
    static void _quickSort(SVector& vect, size_t beg, size_t end);
    static size_t _partition(SVector& vect, size_t beg, size_t end);

public:
    static void QuickSort(SVector& vect);
    static void HeapSort(SVector& vect);
    static void MergeSort(SVector& vect);
    static void Terminate();
};

#endif