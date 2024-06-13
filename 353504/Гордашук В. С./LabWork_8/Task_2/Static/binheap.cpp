#include "binheap.h"

BinaryHeap::BinaryHeap() {}

void BinaryHeap::shiftUp(int i) {
    while (i > 0 && heap[parent(i)] < heap[i])
    {
        std::swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void BinaryHeap::shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l < heap.size() && heap[l] > heap[maxIndex])
    {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r < heap.size() && heap[r] > heap[maxIndex])
    {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(heap[i], heap[maxIndex]);
        shiftDown(maxIndex);
    }
}

void BinaryHeap::insert(int p)
{
    heap.push_back(p);
    shiftUp(heap.size() - 1);
}

int BinaryHeap::extractMax()
{
    int result = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    shiftDown(0);
    return result;
}

void BinaryHeap::remove(int i)
{
    if (i > heap.size() - 1) throw QException();
    heap[i] = heap[0] + 1;
    shiftUp(i);
    extractMax();
}

QString BinaryHeap::print()
{
    QString s;
    for (int i =0; i < heap.size(); ++i)
    {
        s += QString::number(heap[i]);
        if (i != heap.size() - 1) s += ' ';
    }
    return s;
}
