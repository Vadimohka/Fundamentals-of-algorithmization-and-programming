#ifndef MERGESORT_H
#define MERGESORT_H

#include <QVector>

class MergeSort
{
public:
    MergeSort();
    void mergeSort(QVector<int>&);
    void mergeSort(QVector<int>&, QVector<QVector<int> >&);
private:
    void BuiltInMergeSort(QVector<int>&, int, int);
    void BuiltInMergeSort(QVector<int>&, QVector<QVector<int> >&, int, int);
    void Merge(QVector<int>&, int, int, int);
};

#endif // MERGESORT_H
