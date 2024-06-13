#ifndef BINARYHEAPLIST_H
#define BINARYHEAPLIST_H

#include "Dynamic_global.h"
#include <memory>
#include <queue>
#include <QDebug>
#include <QTreeWidget>
#include <QException>

class Node {
public:
    int value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::weak_ptr<Node> parent;

    Node(int _value) : value(_value) {}
};

class DYNAMIC_EXPORT BinaryHeapList
{
private:
    std::shared_ptr<Node> root;
    void siftUp(std::shared_ptr<Node> node);
    void siftDown(std::shared_ptr<Node> node);


public:
    BinaryHeapList();
    void insert(int value);
    void remove();
    QString printHeap();
    int front();
    void printHeapToTreeWidget(QTreeWidget *treeWidget);
};

#endif // BINARYHEAPLIST_H
