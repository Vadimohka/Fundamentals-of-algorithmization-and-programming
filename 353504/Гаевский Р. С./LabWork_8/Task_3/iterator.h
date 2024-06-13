#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <memory>

template <typename K, typename V>
class Iterator {
public:
    std::shared_ptr<Node<K, V>> cur;

    Iterator(std::shared_ptr<Node<K, V>> root) : cur(root) {
        if(!cur) return;
        while (cur->left != nullptr)
            cur = cur->left;
    }

    Node<K, V>* operator->() { return cur.get(); }

    Node<K, V>& operator*() { return *cur; }

    Iterator& operator++() {
        if (!cur)
            return *this;

        if (cur->right != nullptr) {
            cur = cur->right;
            while (cur->left != nullptr)
                cur = cur->left;
        } else {
            auto parent = cur->parent.lock();
            while (parent != nullptr && parent->right == cur) {
                cur = parent;
                parent = cur->parent.lock();
            }
            cur = parent; // Move to parent
        }

        return *this;
    }

    bool operator==(const Iterator &other) const {
        return cur == other.cur;
    }

    bool operator!=(const Iterator &other) const { return !(*this == other); }
};

#endif // ITERATOR_H
