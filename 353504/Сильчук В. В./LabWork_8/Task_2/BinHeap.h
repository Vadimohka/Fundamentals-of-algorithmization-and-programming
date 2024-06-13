#ifndef BINHEAP_H
#define BINHEAP_H

#include <cstddef>
#include <memory>

constexpr short INIT_CAPACITY = 16;

template<typename T>
class BinaryHeap
{
private:
    std::unique_ptr<T[]> _data;
    size_t _size;
    size_t _capacity;

private:
    size_t heapify(size_t index);
    void grow();
    bool is_full();

public:
    BinaryHeap();
    ~BinaryHeap();

    void clear();
    void push(T value);
    T pop();
    T &max();
    size_t size();
    bool empty();
};
#endif // BINHEAP_H
