#include <memory>

class DynamicHeap {
public:
    DynamicHeap();
    ~DynamicHeap();

    bool isEmpty() const;
    void insert(long value);
    long getMax() const;
    int currentSize() const;
    long extractMax();
    void clearHeap();

private:
    void siftDown(int index);
    void siftUp(int index);
    int getParentIndex(int index) const;
    void resizeHeap();

    int size;
    int maxCapacity;
    const int initialCapacity = 16;
    std::unique_ptr<long[]> heap;
};

