#ifndef HEAPLIST_H
#define HEAPLIST_H

#include "HeapList_global.h"
#include <memory>
#include <vector>


class HEAPLIST_EXPORT HeapList
{
public:
    HeapList();
    size_t size() const;
    std::vector<int> Data() const;
    void insert(int value);
    int extractMax();
    bool isEmpty() const;

private:
    struct Node {
        int value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(int val) : value(val) {}
    };

    std::shared_ptr<Node> root;
    std::vector<std::weak_ptr<Node>> nodeList;

    void heapifyUp(std::shared_ptr<Node> node);
    void heapifyDown(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getLastNode();
    void removeLastNode();
    std::shared_ptr<Node> findParentForNewNode();
};

#endif // HEAPLIST_H

