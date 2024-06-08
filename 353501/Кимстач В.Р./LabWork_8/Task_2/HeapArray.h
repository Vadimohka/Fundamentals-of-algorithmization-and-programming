#ifndef TASK2_HEAPARRAY_H
#define TASK2_HEAPARRAY_H

#include <memory>
#include <vector>

class HeapArray {
    size_t _capacity;
    size_t _size;
    std::unique_ptr<int[]> heap;

    void siftUp(int i);
    void siftDown(int i);
    void reserve();

    int findValue(int i, int value);

public:
    HeapArray();

    void add(int value);
    int getMax();
    void ExtractMax();
    void increaseElement(int i, int delta);
    void decreaseElement(int i, int delta);

    void increaseValue(int value, int delta);
    void decreaseValue(int value, int delta);

    int size();
    void clear();
    std::vector<int> GetHeap();
};


#endif //TASK2_HEAPARRAY_H
