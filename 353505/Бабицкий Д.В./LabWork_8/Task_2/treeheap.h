#ifndef TREEHEAP_H
#define TREEHEAP_H

#include <climits>
#include <memory>
#include <queue>


class TreeHeap {
public:
    struct Node {
        int data;
        std::shared_ptr<Node> leftSon;
        std::shared_ptr<Node> rightSon;
        std::weak_ptr<Node> parent;

        Node(int d);
    };

private:
    void siftDown(std::shared_ptr<Node> node);
    void siftUp(std::shared_ptr<Node> node);
    std::shared_ptr<Node> findInsertionNode();
    std::shared_ptr<Node> findLastNode();

public:
    std::shared_ptr<Node> root;

    TreeHeap();
    void insert(int key);
    int extractMax();
};



#endif // TREEHEAP_H
