#ifndef SORTER_H
#define SORTER_H
//I am booored

#include <cstdint>
#include <algorithm>

class Sorter
{
public:
    Sorter();
    static void HeapSort(int64_t* arr, int64_t size);
    static void QuickSort(int64_t* arr, int64_t size);
    static void MergeSort(int64_t* arr, int64_t size);
    static void InterpolationSort(int64_t* arr, int64_t size);
};

#endif // SORTER_H
