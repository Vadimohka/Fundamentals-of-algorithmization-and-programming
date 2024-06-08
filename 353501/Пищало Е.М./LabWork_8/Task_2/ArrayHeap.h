#include <memory>

class ArrayHeap {
private:
  void grow() {
    capacity *= 2;
    std::unique_ptr<long[]> newHeap (new long [capacity]);
    for (int i = 0; i <= len; i++) {
      newHeap[i] = heap[i];
    }
    heap = std::move(newHeap);
  }

  int parent(int i)
  {
      return (i - 1) / 2;
  }

  void heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] < heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
  }

  void heapifyDown(int cur) {
    int left = cur * 2 + 1;
    int right = cur * 2 + 2;
    int largest = cur;
    if(left < capacity && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < capacity && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != cur){
        std::swap(heap[largest], heap[cur]);
        heapifyDown(largest);
    }
  }

public:
  ArrayHeap() {
    heap = std::make_unique<long[]>(16);
    len = 0;
    capacity = 16;
  }

  ~ArrayHeap() {}

  void push(long x) {
    if (len >= capacity)
      grow();

    len++;
    heap[len - 1] = x;
    heapifyUp(len - 1);
  };

  long pop() {
    if (len == 0)
      return 0;
    long res = heap[0];
    heap[0] = heap[len - 1];
    len--;
    heapifyDown(0);
    return res;
  };

  bool empty() {
    return len == 0;
  }

  void clear() {
    len = 0;
  }

  int getMax()
  {
      return heap[0];
  }

  int curSize()
  {
      return len;
  }
public:
  int len;
  int capacity = 0;
private:
  std::unique_ptr<long[]> heap;

};
