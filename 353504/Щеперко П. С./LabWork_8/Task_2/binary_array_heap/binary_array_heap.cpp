#include "binary_array_heap.h"

BinaryArrayHeap::BinaryArrayHeap()
{
    capacity = 1;
    size = 0;
    array = std::make_unique<int[]>(capacity);
}

BinaryArrayHeap::~BinaryArrayHeap()
{
    array.reset();
}

int BinaryArrayHeap::parent(int i)
{
    return (i - 1) / 2;
}

int BinaryArrayHeap::left(int i)
{
    return i * 2 + 1;
}

int BinaryArrayHeap::right(int i)
{
    return i * 2 + 2;
}

void BinaryArrayHeap::heapifyDown(int i)
{
    while(i <= size - 1)
    {
        int u = left(i);
        if (right(i) < size && array[right(i)] > array[u]) {
            u = right(i);
        }
        if (u < size && array[i] < array[u]) {
            std::swap(array[i], array[u]);
            i = u;
        } else {
            break;
        }
    }
}

void BinaryArrayHeap::heapifyUp(int i)
{
    while(i != 0 && array[parent(i)] < array[i]) {
        std::swap(array[parent(i)], array[i]);
        i = parent(i);
    }
}

int BinaryArrayHeap::getMax()
{
    if (size > 0)
        return array[0];
    throw QException();
}

void BinaryArrayHeap::decreaseKey(int k, int delta)
{
    if(k >= 0 && k < size)
    {
        array[k] -= delta;
        heapifyDown(k);
    }
}

void BinaryArrayHeap::insert(int value)
{
    if (size == capacity) {
        capacity++;
        std::unique_ptr<int[]> newArray = std::make_unique<int[]>(capacity);
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        array = std::move(newArray);
    }
    array[size] = value;
    heapifyUp(size);
    size++;
}

void BinaryArrayHeap::extractMax()
{
    size--;
    array[0] = array[size];
    heapifyDown(0);
}

void BinaryArrayHeap::print()
{
    for(int i = 0; i < size; i++) {
        qDebug() << array[i] << ' ';
    }
    qDebug() << '\n';
}

int BinaryArrayHeap::getSize()
{
    return size;
}

int* BinaryArrayHeap::getArray()
{
    return array.get();
}