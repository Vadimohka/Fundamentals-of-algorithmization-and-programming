#include "Heap.h"
#include <memory>

class ArrayHeap : public Heap {
private:
  void grow() {
    capacity *= 2;
    auto newHeap = std::make_unique<long[]>(capacity);
    for (int i = 0; i <= len; i++) {
      newHeap[i] = heap[i];
    }
    heap = std::move(newHeap);
  }

  void heapifyUp(int index) {
      if (index == 1) {
          return;
      }

      int parentIndex = getParentIndex(index);
      if (heap[index] > heap[parentIndex]) {
          std::swap(heap[index], heap[parentIndex]);
          heapifyUp(parentIndex);
      }
  }

  int getParentIndex(int index) {
      return index / 2;
  }

  void heapifyDown(int index) {
      int swapIndex = index;
      long best = heap[index];

      int leftIndex = getLeftChildIndex(index);
      if (leftIndex <= len && heap[leftIndex] > best) {
          swapIndex = leftIndex;
          best = heap[leftIndex];
      }

      int rightIndex = getRightChildIndex(index);
      if (rightIndex <= len && heap[rightIndex] > best) {
          swapIndex = rightIndex;
      }

      if (swapIndex != index) {
          std::swap(heap[index], heap[swapIndex]);
          heapifyDown(swapIndex);
      }
  }

  int getLeftChildIndex(int index) {
      return index * 2;
  }

  int getRightChildIndex(int index) {
      return index * 2 + 1;
  }

public:
  ArrayHeap() {
    heap = std::make_unique<long[]>(16);
    len = 0;
    capacity = 16;
  }
  
  virtual ~ArrayHeap() {}

  virtual void push(long value) {
      if (len + 1 >= capacity) {
          grow();
      }

      heap[++len] = value;
      heapifyUp(len);
  }

  virtual long pop() {
      if (len == 0) {
          return 0;
      }

      long maxValue = heap[1];
      heap[1] = heap[len--];
      heapifyDown(1);
      return maxValue;
  }

  virtual bool empty() {
      return len == 0;
  }

  void clear() {
    len = 0;
  }

  void inspect(HeapInspector *root) {
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

std::unique_ptr<Heap> createArrHeap() { return std::make_unique<ArrayHeap>(); };
