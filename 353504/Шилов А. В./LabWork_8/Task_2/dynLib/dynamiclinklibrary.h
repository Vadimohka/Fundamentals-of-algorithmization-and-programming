#ifndef DYNAMICLINKLIBRARY_H
#define DYNAMICLINKLIBRARY_H

#include "DynamicLinkLibrary_global.h"
#include <QVector>
#include <QString>
#include <QQueue>
#include <memory>

class DYNAMICLINKLIBRARY_EXPORT DynamicLinkLibrary
{
public:
    DynamicLinkLibrary();
};

template<typename T>
class DYNAMICLINKLIBRARY_EXPORT PriorityTree {
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
    std::shared_ptr<ListNode> getRoot() { return root; }

    QVector<T> traverse();
    QVector<T> traversePriorityOrder();
    QVector<T> traverseLevelOrder();
};

#endif // DYNAMICLINKLIBRARY_H
