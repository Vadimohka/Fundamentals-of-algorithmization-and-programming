#include "Heap.h"
#include <memory>

class ArrayHeap : public Heap
{
private:
    void grow()
    {
        capacity *= 2;
        auto newHeap = std::make_unique<long[]>(capacity);
        for (int i = 0; i <= len; i++) {
            newHeap[i] = heap[i];
        }
        heap = std::move(newHeap);
    }

    void heapifyUp(int cur)
    {
        if (cur == 1)
            return;

        if (heap[cur] > heap[cur / 2]) {
            std::swap(heap[cur], heap[cur / 2]);
            heapifyUp(cur / 2);
        }
    }

    void heapifyDown(int cur)
    {
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
                best = heap[cur * 2 + 1];
            }
        }

        if (swapWith == cur)
            return;

        std::swap(heap[cur], heap[swapWith]);
        heapifyDown(swapWith);
    }

public:
    ArrayHeap()
    {
        heap = std::make_unique<long[]>(16);
        len = 0;
        capacity = 16;
    }

    virtual ~ArrayHeap() {}

    virtual void push(long x)
    {
        if (len + 1 >= capacity)
            grow();

        len++;
        heap[len] = x;
        heapifyUp(len);
    };

    virtual long pop()
    {
        if (len == 0)
            return 0;
        long res = heap[1];
        heap[1] = heap[len];
        len--;
        heapifyDown(1);
        return res;
    };

    virtual bool empty() { return len == 0; }

    void clear() { len = 0; }

    void inspect(HeapInspector *root)
    {
        for (int i = 1; i <= len; i++) {
            HeapInspector *cur = root->createChild();
            cur->setPos(i);
            cur->setVal(heap[i]);
        }
    }

private:
    std::unique_ptr<long[]> heap;
    int len;
    int capacity = 0;
};

std::unique_ptr<Heap> createArrHeap()
{
    return std::make_unique<ArrayHeap>();
};
