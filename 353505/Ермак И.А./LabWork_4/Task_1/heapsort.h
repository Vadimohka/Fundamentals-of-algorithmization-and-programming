#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <QVector>

class HeapSort
{
public:
    HeapSort();
    void heapSort(QVector<int>&);
    void heapSort(QVector<int>&, QVector<QVector<int> >&);
private:
    void heap(QVector<int>&, int, int);
    void swap(int&, int&);
};

#endif // HEAPSORT_H
