#ifndef SORTER_H
#define SORTER_H

#include <QVector>

class Sorter {
public:
    static void heapSort(QVector<int>& arr);
    static void quickSort(QVector<int>& arr);
    static void mergeSort(QVector<int>& arr);
    static void interpolationSort(QVector<int>& arr);  // Новый метод сортировки

private:
    static void heapify(QVector<int>& arr, int n, int i);
    static void quickSortHelper(QVector<int>& arr, int low, int high);
    static int partition(QVector<int>& arr, int low, int high);
    static void mergeSortHelper(QVector<int>& arr, int left, int right);
    static void merge(QVector<int>& arr, int left, int mid, int right);
};

#endif // SORTER_H
