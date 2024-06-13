#include "priorityqueue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    heap = std::make_unique<T[]>(16);
    len = 0;
    capacity = 16;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {}

template<typename T>
void PriorityQueue<T>::grow() {
    capacity *= 2;
    auto newHeap = std::make_unique<T[]>(capacity);
    for (int i = 1; i <= len; i++) {
        newHeap[i] = heap[i];
    }
    heap = std::move(newHeap);
}

template<typename T>
void PriorityQueue<T>::heapifyUp(int cur) {
    if (cur == 1)
        return;

    if (heap[cur] > heap[cur / 2]) {
        std::swap(heap[cur], heap[cur / 2]);
        heapifyUp(cur / 2);
    }
}

template<typename T>
void PriorityQueue<T>::heapifyDown(int cur) {
    int swapWith = cur;
    T best = heap[cur];
    if (cur * 2 <= len) {
        if (heap[cur * 2] > best) {
            swapWith = cur * 2;
            best = heap[cur * 2];
        }
    }

    if (cur * 2 + 1 <= len) {
        if (heap[cur * 2 + 1] > best) {
            swapWith = cur * 2 + 1;
        }
    }

    if (swapWith == cur)
        return;

    std::swap(heap[cur], heap[swapWith]);
    heapifyDown(swapWith);
}

template<typename T>
void PriorityQueue<T>::push(T x) {
    if (len + 1 >= capacity)
        grow();

    ++len;
    heap[len] = x;
    heapifyUp(len);
}

template<typename T>
T PriorityQueue<T>::pop() {
    if (len == 0)
        return 0;
    T res = heap[1];
    heap[1] = heap[len];
    len--;
    heapifyDown(1);
    return res;
}

template<typename T>
bool PriorityQueue<T>::empty() {
    return len == 0;
}

template<typename T>
void PriorityQueue<T>::clear() {
    len = 0;
}

template<typename T>
T PriorityQueue<T>::getMax()
{
    return heap[1];
}

template<typename T>
T PriorityQueue<T>::getMin()
{
    return heap[len];
}

template<typename T>
QVector<T> PriorityQueue<T>::toVec() {
    QVector<T> arr;
    for (int i = 1; i <= len; ++i) {
        arr.push_back(heap[i]);
    }
    return arr;
}
