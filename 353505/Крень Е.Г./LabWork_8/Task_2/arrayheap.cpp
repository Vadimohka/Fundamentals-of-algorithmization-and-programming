#include "arrayheap.h"

void ArrayHeap::grow() {
    if (capacity == 0) ++capacity;
    else capacity *= 2;
    auto newHeap = std::make_unique<long[]>(capacity);
    for (int i = 0; i <= len; i++) {
        newHeap[i] = heap[i];
    }
    heap = std::move(newHeap);
}

void ArrayHeap::heapifyUp(int cur) {
    if (cur == 1)
        return;

    if (heap[cur] > heap[cur / 2]) {
        std::swap(heap[cur], heap[cur / 2]);
        heapifyUp(cur / 2);
    }
}

void ArrayHeap::heapifyDown(int cur) {
    int swapWith = cur;
    int best = heap[cur];
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

ArrayHeap::ArrayHeap() {
    heap = std::make_unique<long[]>(16);
    len = 0;
    capacity = 16;
}

ArrayHeap::~ArrayHeap() {}

void ArrayHeap::push(long x) {
    if (len + 1 >= capacity)
        grow();

    ++len;
    heap[len] = x;
    heapifyUp(len);
}

long ArrayHeap::pop() {
    if (len == 0)
        return 0;
    long res = heap[1];
    heap[1] = heap[len];
    len--;
    heapifyDown(1);
    return res;
}

bool ArrayHeap::empty() {
    return len == 0;
}

void ArrayHeap::clear() {
    len = 0;
}

QVector<long> ArrayHeap::toVec(){
    QVector<long> arr;
    for (int i = 1; i <= len; ++i) {
        arr.push_back(heap[i]);
    }
    return arr;
}
