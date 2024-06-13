#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class BinaryHeapArray {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild, rightChild, largestChild;
        while (true) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            largestChild = index;

            if (leftChild < heap.size() && heap[leftChild] > heap[largestChild]) {
                largestChild = leftChild;
            }

            if (rightChild < heap.size() && heap[rightChild] > heap[largestChild]) {
                largestChild = rightChild;
            }

            if (largestChild == index) {
                break;
            }

            std::swap(heap[index], heap[largestChild]);
            index = largestChild;
        }
    }

public:
    BinaryHeapArray() {}

    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        T maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElement;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    BinaryHeapArray<int> heap;
    heap.insert(3);
    heap.insert(2);
    heap.insert(1);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    while (!heap.isEmpty()) {
        std::cout << heap.extractMax() << " ";
    }

    return 0;
}
