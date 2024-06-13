#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H

#include <QVector>
#include <climits>

class BinaryHeapArray
{
private:
    void siftDown(int i)
    {
        while (2 * i + 1 < heap.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if (right < heap.size() && heap[right] > heap[left])
                j = right;
            if (heap[i] >= heap[j])
                break;
            std::swap(heap[i], heap[j]);
            i = j;
        }
    }

    void siftUp(int i)
    {
        while (heap[i] > heap[(i - 1) / 2]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

public:
    QVector<int> heap;

    void insert(int key)
    {
        heap.resize(heap.size() + 1);
        heap[heap.size() - 1] = key;
        siftUp(heap.size() - 1);
    }

    int extractMax()
    {
        if (heap.size() == 0)
            return INT_MAX;
        int max = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.resize(heap.size() - 1);
        siftDown(0);
        return max;
    }
};

#endif // BINARYHEAPARRAY_H
