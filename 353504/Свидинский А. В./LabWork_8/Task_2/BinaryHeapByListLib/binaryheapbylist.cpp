#include "binaryheapbylist.h"
#include <QDebug>
#include <stdexcept>


template<typename T>
BinaryHeapByList<T>::BinaryHeapByList()
{
}

template<typename T>
int BinaryHeapByList<T>::parent(int i)
{
    return (i - 1) / 2;
}

template<typename T>
int BinaryHeapByList<T>::left(int i)
{
    return i * 2 + 1;
}

template<typename T>
int BinaryHeapByList<T>::right(int i)
{
    return i * 2 + 2;
}

template<typename T>
void BinaryHeapByList<T>::heapifyDown(int i)
{
    while(i <= list.size - 1)
    {
        int u = left(i);
        if(right(i) < list.size && list[right(i)] > list[u])
        {
            u = right(i);
        }

        if(u < list.size && list[i] < list[u])
        {
            std::swap(list[i], list[u]);
            i = u;
        }
        else break;
    }
}

template<typename T>
void BinaryHeapByList<T>::heapifyUp(int i)
{
    while(i != 0 && list[parent(i)] < list[i])
    {
        std::swap(list[parent(i)], list[i]);
        i = parent(i);
    }
}

template<typename T>
T BinaryHeapByList<T>::getMax()
{
    if(list.size > 0) return list[0];
    throw std::out_of_range("Heap is empty");
}

template<typename T>
void BinaryHeapByList<T>::decreaseKey(int k, T delta)
{
    if(k >= 0 && k < list.size)
    {
        list[k] -= delta;
        heapifyDown(k);
    }
}

template<typename T>
void BinaryHeapByList<T>::insert(T value)
{
    list.append(value);
    heapifyUp(list.size - 1);
}

template<typename T>
void BinaryHeapByList<T>::extractMax()
{
    list[0] = list[list.size - 1];
    list.size--;
    heapifyDown(0);
}

template<typename T>
void BinaryHeapByList<T>::print()
{
    for(int i = 0; i < list.size; i++)
    {
        qDebug() << list[i] << ' ';
    }
    qDebug() << '\n';
}
