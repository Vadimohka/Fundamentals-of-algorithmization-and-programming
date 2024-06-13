#ifndef LIST_HEAP_H
#define LIST_HEAP_H

#include <memory>
#include <vector>
#include <stdexcept>

struct ListNode {
    int value;
    std::shared_ptr<ListNode> left;
    std::shared_ptr<ListNode> right;
    std::weak_ptr<ListNode> parent;

    ListNode(int val) : value(val), left(nullptr), right(nullptr), parent() {}
};

class ListHeap {
public:
    ListHeap();
    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;

private:
    std::shared_ptr<ListNode> root;
    std::vector<std::weak_ptr<ListNode>> nodes;
    void heapifyUp(std::shared_ptr<ListNode> node);
    void heapifyDown(std::shared_ptr<ListNode> node);
    std::shared_ptr<ListNode> getLastNode() const;
};

#endif // LIST_HEAP_H
