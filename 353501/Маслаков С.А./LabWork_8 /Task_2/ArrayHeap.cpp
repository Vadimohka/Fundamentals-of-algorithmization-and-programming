#include "ArrayHeap.h"

ArrayHeap::ArrayHeap() {}

void ArrayHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int ArrayHeap::extractMax() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = heap.front();
    heap.front() = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxValue;
}

int ArrayHeap::getMax() const {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap.front();
}

bool ArrayHeap::isEmpty() const {
    return heap.empty();
}

void ArrayHeap::printHeap() const {
    for (int value : heap) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void ArrayHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] <= heap[parentIndex]) {
            break;
        }
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
    }
}

void ArrayHeap::heapifyDown(int index) {
    int size = heap.size();
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest == index) {
            break;
        }
        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}
void ArrayHeap::showHeapOnTreeWidget(QTreeWidget* treeWidget) {
    treeWidget->clear();
    showHeapRecursive(treeWidget->invisibleRootItem(), 0);
}

void ArrayHeap::showHeapRecursive(QTreeWidgetItem* parent, int index) {
    if (index >= heap.size()) {
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem(parent);
    item->setText(0, QString::number(heap[index]));

    showHeapRecursive(item, 2 * index + 1); // левый ребенок
    showHeapRecursive(item, 2 * index + 2); // правый ребенок
}
void ArrayHeap::clearHeap() {
    heap.clear();
}