#include "binaryheaparray.h"

BinaryHeapArray::BinaryHeapArray() {}

BinaryHeapArray::~BinaryHeapArray()
{

}

void BinaryHeapArray::insert(int value)
{
    heap.push_back(std::make_shared<int>(value));
    heapify_up(heap.size() - 1);
}

int BinaryHeapArray::extract_min()
{
    if (heap.empty()) {
        return -1; // or throw an exception if appropriate
    }

    std::shared_ptr<int> min_value = heap.front().lock();
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    heapify_down(0);

    return *min_value;
}

bool BinaryHeapArray::is_empty() const
{
    return heap.empty();
}

void BinaryHeapArray::heapify_up(size_t index)
{
    size_t parent = (index - 1) / 2;

    while (index > 0 && heap[index].lock() < heap[parent].lock()) {
        std::swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void BinaryHeapArray::heapify_down(size_t index)
{
    size_t smallest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < heap.size() && heap[left].lock() < heap[smallest].lock()) {
        smallest = left;
    }

    if (right < heap.size() && heap[right].lock() < heap[smallest].lock()) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapify_down(smallest);
    }
}
