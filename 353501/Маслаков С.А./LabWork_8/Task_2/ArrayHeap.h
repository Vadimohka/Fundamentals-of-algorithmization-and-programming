#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

#include <vector>
#include <memory>
#include <iostream>
#include <QTreeWidget>
#include <QTreeWidgetItem>
class ArrayHeap {
public:
    ArrayHeap();

    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;
    void printHeap() const;
    void showHeapOnTreeWidget(QTreeWidget* treeWidget);
    void showHeapRecursive(QTreeWidgetItem* parent, int index);
    void clearHeap();
private:
    std::vector<int> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif // ARRAY_HEAP_H