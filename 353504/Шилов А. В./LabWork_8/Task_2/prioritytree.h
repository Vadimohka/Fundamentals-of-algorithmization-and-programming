#ifndef PRIORITYTREE_H
#define PRIORITYTREE_H

#include <QVector>
#include <QQueue>
#include <memory>

template<typename T>
class PriorityTree {
private:
    struct ListNode {
        T data;
        std::weak_ptr<ListNode> parent;
        std::shared_ptr<ListNode> left;
        std::shared_ptr<ListNode> right;
    };

    std::shared_ptr<ListNode> root;
    int level;
    int level_i;

    void heapifyUp(std::shared_ptr<ListNode> node);

    void heapifyDown(std::shared_ptr<ListNode> cur);

    void traverse(std::shared_ptr<ListNode> node, QVector<T>& result);

    void traversePriorityOrderHelper(std::shared_ptr<ListNode> node, QVector<T>& result);

public:
    PriorityTree();

    ~PriorityTree() {}

    void push(T x);

    T pop();

    bool empty() { return root == nullptr; }

    void clear() { root = nullptr; }

    std::shared_ptr<ListNode> getRoot() {
        return root;
    }

    QVector<T> traverse();

    QVector<T> traversePriorityOrder();

    QVector<T> traverseLevelOrder();
};

#endif // PRIORITYTREE_H
