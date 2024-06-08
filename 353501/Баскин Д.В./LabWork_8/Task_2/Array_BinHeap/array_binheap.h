#ifndef ARRAY_BINHEAP_H
#define ARRAY_BINHEAP_H

#include <QVector>
#include <memory>

template<typename T>
class Array_BinHeap
{
    static const long long INITIAL_CAPACITY = 16;

    std::unique_ptr<T[]> heap;
    long long size;
    long long capacity;

    void grow()
    {
        if (!capacity)
        {
            ++capacity;
        }
        else
        {
            capacity *= 2;
        }

        auto replacement = std::make_unique<T[]>(capacity);
        for (int i = 0; i <= size; ++i)
        {
            replacement[i] = heap[i];
        }
        heap = std::move(replacement);
    }

    void heapifyUp(long long i)
    {
        if (i == 1)
        {
            return;
        }
        if (heap[i] > heap[i / 2])
        {
            std::swap(heap[i], heap[i / 2]);
            heapifyUp(i / 2);
        }
    }

    void heapifyDown(long long i)
    {
        int swap = i;
        T best = heap[i];
        if (i * 2 <= size && heap[i * 2] > best)
        {
            swap = i * 2;
            best = heap[swap];
        }
        if (i * 2 + 1  <= size && heap[i * 2 + 1] > best)
        {
            swap = i * 2 + 1;
        }
        if (swap == i)
        {
            return;
        }
        std::swap(heap[i], heap[swap]);
        heapifyDown(swap);
    }

public:
    Array_BinHeap()
    {
        heap = std::make_unique<T[]>(INITIAL_CAPACITY);
        size = 0;
        capacity = INITIAL_CAPACITY;
    }

    ~Array_BinHeap() {};

    bool empty()
    {
        return size == 0;
    }

    void clear()
    {
        size = 0;
    }

    void push(T element)
    {
        if (size + 1 >= capacity)
        {
            grow();
        }

        ++size;
        heap[size] = element;
        heapifyUp(size);
    }

    T pop()
    {
        if (!size)
        {
            return 0;
        }

        T element = heap[1];
        heap[1] = heap[size];
        --size;
        heapifyDown(1);
        return element;
    }

    QVector<T> toVector()
    {
        QVector<T> vec;
        for (int i = 1; i <= size; ++i)
        {
            vec.push_back(heap[i]);
        }
        return vec;
    }
};

#endif // ARRAY_BINHEAP_H
