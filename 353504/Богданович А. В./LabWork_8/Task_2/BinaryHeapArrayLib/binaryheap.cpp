#include "binaryheap.h"
#include <QDebug>
#include <stdexcept>


template<typename T>
BinaryHeap<T>::BinaryHeap()
{
    capacity = 1;
    size = 0;
    array = std::make_unique<T[]>(capacity);
}

template<typename T>
int BinaryHeap<T>::parent(int i)
{
    return (i - 1) / 2;
}

template<typename T>
int BinaryHeap<T>::left(int i)
{
    return i * 2 + 1;
}

template<typename T>
int BinaryHeap<T>::right(int i)
{
    return i * 2 + 2;
}

template<typename T>
void BinaryHeap<T>::heapifyDown(int i)
{
    while(i <= size - 1)
    {
        int u = left(i);
        if(right(i) < size && array[right(i)] > array[u])
        {
            u = right(i);
        }


        if(u < size && array[i] < array[u])
        {
            std::swap(array[i], array[u]);
            i = u;
        }
        else break;
    }
}

template<typename T>
void BinaryHeap<T>::heapifyUp(int i)
{
    while(i != 0 && array[parent(i)] < array[i])
    {
        std::swap(array[parent(i)], array[i]);
        i = parent(i);
    }
}

template<typename T>
T BinaryHeap<T>::getMax()
{
    if(size > 0) return array[0];
    throw std::out_of_range("Heap is empty");
}

template<typename T>
void BinaryHeap<T>::decreaseKey(int k, T delta)
{
    if(k >= 0 && k < size)
    {
        array[k] -= delta;
        heapifyDown(k);
    }
}

template<typename T>
void BinaryHeap<T>::insert(T value)
{
    if (size == capacity)
    {
        capacity++;
        std::unique_ptr<T[]> newArray = std::make_unique<T[]>(capacity);
        for (int i = 0; i < size; ++i)
        {
            newArray[i] = array[i];
        }
        array = std::move(newArray);
    }
    array[size] = value;
    heapifyUp(size);
    size++;
}

template<typename T>
void BinaryHeap<T>::extractMax()
{
    size--;
    array[0] = array[size];
    heapifyDown(0);
}

template<typename T>
void BinaryHeap<T>::print()
{
    for(int i = 0; i < size; i++)
    {
        qDebug() << array[i] << ' ';
    }
    qDebug() << '\n';
}

template<typename T>
int BinaryHeap<T>::getSize()
{
    return size;
}

template<typename T>
T* BinaryHeap<T>::getArray()
{
    return array.get();
}
