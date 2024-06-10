#ifndef L8_T2_HEAPLIST_H
#define L8_T2_HEAPLIST_H

#include <memory>
#include <iostream>

struct Node {
    int value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::weak_ptr<Node> parent;

    Node(int value);
};

class HeapList {
private:
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> last;

    void putUp(std::shared_ptr<Node> node);
    void putDown(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getNextInsertPosition();
    std::shared_ptr<Node> getLastNode();

public:
    HeapList();
    void insert(int value);
    int extractMax();
    int getMax();
    bool isEmpty();
    void printHeap();
};


#endif //L8_T2_HEAPLIST_H
