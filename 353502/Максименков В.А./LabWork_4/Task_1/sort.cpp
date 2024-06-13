#include "sort.h"

Sort::Sort() {}


void Sort::heapify(QVector<int>& v, int n, int i)
{
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && v[l] > v[largest])
    {
        largest = l;
    }

    if (r < n && v[r] > v[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}


void Sort::Merge(QVector<int> &v, int l, int r)
{
    int middle = (l + r) / 2, start = l;
    int final = middle + 1;
    QVector<int> temp;
    temp.resize(v.size() + 1);

    for (int i = l; i <= r; ++i)
    {
        if ((start <= middle) && ((final > r) || (v[start] < v[final])))
        {
            temp[i] = v[start];
            start++;
        }
        else
        {
            temp[i] = v[final];
            final++;
        }
    }

    for (int i = l; i <= r; ++i)
    {
        v[i] = temp[i];
    }
}


void Sort::HeapSort(QVector<int> &v, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(v, n, i);
    }

    for (int i = n-1; i >= 0; --i)
    {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


void Sort::QuickSort(QVector<int> &v, int l, int r)
{
    if (l > r) return;

    int i = l, j = r, centralElement = v[(l + r) / 2];

    while (i <= j)
    {
        while (centralElement > v[i]) ++i;
        while (centralElement < v[j]) --j;
        if (i <= j)
        {
            std::swap(v[i], v[j]);
            ++i;
            --j;
        }
    }

    QuickSort(v, l ,j);
    QuickSort(v, i, r);
}


void Sort::MergeSort(QVector<int> &v, int first, int last)
{
    if (first < last)
    {
        MergeSort(v, first, (first + last) / 2);
        MergeSort(v, (first + last) / 2 + 1, last);
        Merge(v, first, last);
    }
}









