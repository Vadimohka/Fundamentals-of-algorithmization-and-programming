#ifndef SORT_H
#define SORT_H

#include <QtGlobal>
#include <QApplication>

class Sort : public QObject {
    Q_OBJECT

public:
    int *arr_global;

    void heapSort(int* arr, int size);

    void mergeSort(int* arr, int left, int right);

    void quickSort(int* arr, int start, int end);

    void interpolationSort(int* arr, int start, int size);


signals:
    void arrayUpdated(int* arr, int size);

private:

    void heapify(int* arr, int size, int index);

    void merge(int* arr, int left, int middle, int right);

    int partQuickSort(int* arr, int left, int right);
};

#endif // SORT_H
