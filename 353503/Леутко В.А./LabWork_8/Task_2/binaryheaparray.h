#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H

#include <memory>
#include <vector>

class BinaryHeapArray {
public:
    BinaryHeapArray();
    ~BinaryHeapArray();
    void insert(int value);
    int extract_min();
    bool is_empty() const;

private:
    std::vector<std::weak_ptr<int>> heap;
    void heapify_up(size_t index);
    void heapify_down(size_t index);

#endif // BINARYHEAPARRAY_H
