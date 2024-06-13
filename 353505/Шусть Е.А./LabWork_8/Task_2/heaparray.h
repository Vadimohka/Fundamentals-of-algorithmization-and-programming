#ifndef HEAPARRAY_H
#define HEAPARRAY_H

#include <QVector>
#include <QTreeWidget>
#include <QTreeWidgetItem>

template <typename T>
class HeapArray {
public:
    HeapArray();
    HeapArray(int capacity);
    ~HeapArray() = default;

    void insert(T key);
    void remove(T key);
    T extractMax();
    T getMax();
    // QString printHeap() const;
    QString inOrder();

    void addNodeToTree(T data, QTreeWidget *tree);
    void addNodeToTree(int index, QTreeWidgetItem *parentItem, QString prefix);
    void update(QTreeWidget *tree);

private:
    QVector<T> heap;
    int size;
    int capacity;

    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const { return (2 * i + 1); }
    int right(int i) const { return (2 * i + 2); }

    void heapifyUp(int i);
    void heapifyDown(int i);
};

template<typename T>
HeapArray<T>::HeapArray()
{
    size = 0;
    capacity = 100;
    heap.resize(capacity);
}

template <typename T>
HeapArray<T>::HeapArray(int capacity) : size(0), capacity(capacity) {
    heap.resize(capacity);
}

template <typename T>
void HeapArray<T>::insert(T key) {
    if (size == capacity) {
        throw std::overflow_error("Heap overflow");
    }
    size++;
    int i = size - 1;
    heap[i] = key;

    heapifyUp(i);
}

template<typename T>
void HeapArray<T>::remove(T key)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (heap[i] == key)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        throw std::invalid_argument("Key not found");
    }
    heap[index] = heap[size - 1];
    size--;
    heapifyDown(index);
}

template <typename T>
T HeapArray<T>::extractMax() {
    if (size <= 0) {
        throw std::underflow_error("Heap underflow");
    }
    if (size == 1) {
        size--;
        return heap[0];
    }

    T root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return root;
}

template<typename T>
T HeapArray<T>::getMax()
{
    if (size <= 0)
    {
        throw std::underflow_error("Heap underflow");
    }
    return heap[0];
}

template<typename T>
QString HeapArray<T>::inOrder()
{
    QString result;
    for (int i = 0; i < size; i++)
    {
        result += QString::number(heap[i]) + " ";
    }
    return result;
}

template <typename T>
void HeapArray<T>::heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] < heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void HeapArray<T>::heapifyDown(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < size && heap[l] > heap[largest]) {
        largest = l;
    }
    if (r < size && heap[r] > heap[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

template <typename T>
void HeapArray<T>::addNodeToTree(T data, QTreeWidget *tree) {
    insert(data);
    tree->clear();
    if (size == 0) return;

    auto *item = new QTreeWidgetItem(tree);
    addNodeToTree(0, item, "Root: ");
}

template <typename T>
void HeapArray<T>::addNodeToTree(int index, QTreeWidgetItem *parentItem, QString prefix) {
    if (index < size) {
        parentItem->setText(0, prefix + QString::number(heap[index]));

        int leftIndex = left(index);
        int rightIndex = right(index);

        if (leftIndex < size) {
            QTreeWidgetItem *leftItem = new QTreeWidgetItem();
            parentItem->addChild(leftItem);
            addNodeToTree(leftIndex, leftItem, "Left: ");
        }

        if (rightIndex < size) {
            QTreeWidgetItem *rightItem = new QTreeWidgetItem();
            parentItem->addChild(rightItem);
            addNodeToTree(rightIndex, rightItem, "Right: ");
        }
    }
}

template<typename T>
void HeapArray<T>::update(QTreeWidget *tree)
{
    tree->clear();
    auto* item = new QTreeWidgetItem(tree);
    addNodeToTree(0, item, "Root: ");
}

#endif // HEAPARRAY_H
