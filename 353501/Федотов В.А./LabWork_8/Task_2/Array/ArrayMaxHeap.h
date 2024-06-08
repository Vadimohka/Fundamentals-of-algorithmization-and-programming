#include <memory>
#include <stdexcept>
#include <utility>

class ArrayMaxHeap {
protected:
    std::unique_ptr<int[]> heap;
    int capacity;
    int size;

    int leftChild(int parentIdx) { return 2 * parentIdx + 1; }
    int rightChild(int parentIdx) { return 2 * parentIdx + 2; }
    int parent(int childIdx) { return (childIdx - 1) / 2; }

public:
    ArrayMaxHeap() {
        heap = std::make_unique<int[]>(16);
        size = 0;
        capacity = 16;
    }

    void insert(const int &value) {
        if (size == capacity)
            resize();
        
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int remove() {
        if (size == 0) 
            throw std::runtime_error("Heap is empty");

        int maxElement = heap[0];
        heap[0] = heap[size--];
        if (size > 0)
            heapifyDown(0);

        return maxElement;
    }

    bool isEmpty() const { return size == 0; }

protected:
    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void resize() {
        capacity *= 2;
        std::unique_ptr<int[]> newHeap = std::make_unique<int[]>(capacity);
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }
        heap = std::move(newHeap);
    }

};
