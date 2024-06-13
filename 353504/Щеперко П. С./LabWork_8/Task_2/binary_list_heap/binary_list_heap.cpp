#include "binary_list_heap.h"

BinaryListHeap::BinaryListHeap()
{}

int BinaryListHeap::parent(int i)
{
    return (i - 1) / 2;
}

int BinaryListHeap::left(int i)
{
    return i * 2 + 1;
}

int BinaryListHeap::right(int i)
{
    return i * 2 + 2;
}

void BinaryListHeap::heapifyDown(int i)
{
    while (i <= list.size - 1) {
        int u = left(i);
        if (right(i) < list.size && list[right(i)] > list[u]) {
            u = right(i);
        }
        if (u < list.size && list[i] < list[u]) {
            std::swap(list[i], list[u]);
            i = u;
        } else {
            break;
        }
    }
}

void BinaryListHeap::heapifyUp(int i)
{
    while (i != 0 && list[parent(i)] < list[i]) {
        std::swap(list[parent(i)], list[i]);
        i = parent(i);
    }
}

int BinaryListHeap::getMax()
{
    if (list.size > 0)
        return list[0];
    throw QException();
}

void BinaryListHeap::decreaseKey(int k, int delta)
{
    if (k >= 0 && k < list.size) {
        list[k] -= delta;
        heapifyDown(k);
    }
}

void BinaryListHeap::insert(int value)
{
    list.append(value);
    heapifyUp(list.size - 1);
}

void BinaryListHeap::extractMax()
{
    list[0] = list[list.size - 1];
    list.size--;
    heapifyDown(0);
}

QStringList BinaryListHeap::printList()
{
    QStringList list;
    for (int i = 0; i < this->list.size; i++) {
        list.push_back(list[i]);
    }
    return list;
}