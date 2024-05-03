#ifndef MERGESORT_H
#define MERGESORT_H

#include <QColor>

#include "picturedarray.h"

class MergeSort
{
public:
    MergeSort();

    static void Merge(PicturedArray &PictureArray, int low, int mid, int high);
    static void mergesort(PicturedArray &PictureArray, int low, int high);

    static void mergeSortForTime(PicturedArray &PictureArray, int low, int high);
    static void mergeForTime(PicturedArray &PictureArray, int low, int mid, int high);
    static long long timeMergeSort(PicturedArray &PictureArray);

private:
};

#endif // MERGESORT_H
