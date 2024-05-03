#include "qsorter.h"

QSorter::QSorter() {}

void QSorter::Sort(QVector<int> &vect)
{
    InSort(vect, 0, vect.size() - 1);
}

void QSorter::SortAnimation(QVector<int> &vect, QVector<QVector<int>> &listOfStates)
{
    InSortAnimation(vect, 0, vect.size() - 1, listOfStates);
}

void QSorter::InSort(QVector<int> &arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            SwapAnimator::swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        InSort(arr, left, j);
    if (i < right)
        InSort(arr, i, right);
}

void QSorter::InSortAnimation(QVector<int> &arr, int left, int right, QVector<QVector<int> > &listOfStates)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            SwapAnimator::swap(arr[i],arr[j]);
            listOfStates.append(arr);
            i++;
            j--;
        }
    }
    if (left < j)
        InSortAnimation(arr, left, j, listOfStates);
    if (i < right)
        InSortAnimation(arr, i, right, listOfStates);
}

