#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <QPair>
#include <QVector>

class HeapSort
{
public:
    HeapSort();
    static void heapSort(int* arr, int n, QVector <QPair <int, int>>& vec);
    void static heap(int* arr, int i, int n, QVector <QPair <int, int>>& vec);
    void static swap(int& i, int& j);


};

#endif // HEAPSORT_H
