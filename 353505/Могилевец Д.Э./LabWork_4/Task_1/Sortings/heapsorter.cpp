#include "heapsorter.h"

HeapSorter::HeapSorter() {}

void HeapSorter::heapify(QVector<int>& arr, int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        SwapAnimator::swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void HeapSorter::Sort(QVector<int>& arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i);
    for (int i = arr.size() - 1; i > 0; i--) {
        SwapAnimator::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void HeapSorter::SortAnimation(QVector<int> &arr, QVector<QVector<int> > &listOfStates)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i);
    for (int i = arr.size() - 1; i > 0; i--) {
        SwapAnimator::swap(arr[0], arr[i]);
        listOfStates.push_back(arr);
        heapify(arr, i, 0);
    }
}

