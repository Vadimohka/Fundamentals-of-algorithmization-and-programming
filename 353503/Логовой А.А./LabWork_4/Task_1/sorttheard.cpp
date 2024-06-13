#include "sorttheard.h"
#include "sort.h"
#include <QApplication>

SortThread::SortThread(int* array, int size, QObject *parent)
    : QThread(parent), m_array(array), m_size(size) {}

void SortThread::setSortingAlgorithm(SortingAlgorithm algorithm) {
    m_algorithm = algorithm;
}

void SortThread::run() {
    Sort sort;
    connect(&sort, SIGNAL(arrayUpdated(int*, int)), this, SIGNAL(arrayUpdated(int*, int)));

    switch (m_algorithm) {
    case QuickSort:
        sort.quickSort(m_array, 0, m_size);
        break;
    case MergeSort:
        sort.mergeSort(m_array, 0, m_size);
        break;
    case HeapSort:
        sort.heapSort(m_array, m_size);
        break;
    case InterpolationSort:
        sort.interpolationSort(m_array, 0 , m_size);
        break;
    }
}
