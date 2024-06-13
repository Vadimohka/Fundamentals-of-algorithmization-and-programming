#ifndef BINARYHEAP_MASSIVE_H
#define BINARYHEAP_MASSIVE_H

#include <memory>

template<typename T>
class binaryheap_massive
{
private:
    std::unique_ptr<T[]> _data;
    size_t _size;
    size_t _capacity;
    static const size_t INIT_CAPACITY = 16;

private:
    size_t heapify(size_t index);
    void grow();

public:
    binaryheap_massive();
    ~binaryheap_massive();

    void clear();
    void push(T value);
    T pop();
    T &max();
    size_t size();
    bool empty();
    bool is_full();
};

#endif // BINARYHEAP_MASSIVE_H
