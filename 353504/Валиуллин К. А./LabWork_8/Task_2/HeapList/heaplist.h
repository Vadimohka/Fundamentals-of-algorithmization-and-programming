#ifndef HEAPLIST_H
#define HEAPLIST_H


#pragma once
#include <memory>

class HeapNode {
public:
    int value;
    std::shared_ptr<HeapNode> left;
    std::shared_ptr<HeapNode> right;
    std::weak_ptr<HeapNode> parent;

    HeapNode(int val) : value(val) {}
};

class HeapList {
public:
    HeapList() = default;

    void insert(int value);
    int extractMax();
    int getMax() const;

    bool isEmpty() const { return !root; }

private:
    std::shared_ptr<HeapNode> root;

    void heapifyUp(std::shared_ptr<HeapNode> node);
    void heapifyDown(std::shared_ptr<HeapNode> node);
    std::shared_ptr<HeapNode> getLastNode() const;
    void removeLastNode();
};


#endif // HEAPLIST_H
