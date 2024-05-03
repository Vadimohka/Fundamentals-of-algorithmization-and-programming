#ifndef SORT_H
#define SORT_H

#include <QVector> // for iterpolation sort

using ull = unsigned long long;

class Sort {
    static const int MAX_FUNC_RUNNING = 9000;
    static int runningFuctionsCntr;
    static bool isOverflowed;

    static void mergeArrays(int *start, int *mid, int *end, int arrSize);
    static void heapify(int *array, int arrSize, int pos);
    static void sortPart(int* &end, QVector<int> &partSizes);

public:
    // impossible to create an object
    Sort() = delete;
    Sort(const Sort&) = delete;
    Sort& operator=(const Sort&) = delete;

    // sort algorithms
    static void Heap(int* start, int* end);
    static void Heap(int* array, int size);
    static void Merge(int* start, int* end);
    static void Merge(int* array, int size);
    static void Quick(int* start, int* end);
    static void Quick3Way(int* start, int* end);
    static void Quick(int* array, int size);
    static void Quick3Way(int* array, int size);
    static void Interpolation(int* start, int* end);
    static void Interpolation(int* array, int size);

    // safe sort algorithms
    static bool Quicks(int* start, int* end);
    static bool Quicks(int* array, int size);

    static int maxFunctionsRunning();
};

#endif // SORT_H
