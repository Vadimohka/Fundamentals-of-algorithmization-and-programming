#ifndef HEAPLIST_H
#define HEAPLIST_H

#include <memory>
#include <utility>

template <class T>
class LHeap
{
private:
    struct Node{
        int priority;
        T value;

        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;

        Node(int prio, const T& val) : value(val), priority(prio) {}
        Node(int prio, T&& val) : value(std::move(val)), priority(prio) {}
    };

    std::shared_ptr<Node> _root;
    std::shared_ptr<Node> _last;
    size_t _size = 0;

    void siftUp(std::shared_ptr<Node> node) {
        while (auto parent = node->parent.lock()) {
            if (node->priority > parent->priority) {
                std::swap(node->value, parent->value);
                std::swap(node->priority, parent->priority);
                node = parent;
            } else {
                return;
            }
        }
    }

    void siftDown(std::shared_ptr<Node> node) {
        while (node && node->left) {
            auto kid = node->left;
            if (node->right && node->right->priority > kid->priority) {
                kid = node->right;
            }
            if (kid->priority > node->priority) {
                std::swap(node->value, kid->value);
                std::swap(node->priority, kid->priority);
                node = kid;
            } else {
                break;
            }
        }
    }

    void add(int priority, T value) {
        auto newNode = std::make_shared<Node>(value, priority);

        if (!_root) {
            _root = newNode;
            _last = newNode;
            ++_size;
            return;
        }

        auto parent = _last;
        while (parent->parent.lock() && parent == parent->parent.lock()->left) {
            parent = parent->parent.lock();
        }

        if (parent->parent.lock()) {
            parent = parent->parent.lock()->left;
        }

        while (parent->right) {
            parent = parent->right;
        }

        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        newNode->parent = parent;
        _last = newNode;

        siftUp(newNode);
        ++_size;
    }

    T& getMax() {
        if (!_root) {

        }
        return _root->value;
    }

    void popMax() {
        if (!_root) {

        }
        if (_root == _last) {
            _root = nullptr;
            _last = nullptr;
            --_size;
            return;
        }

        auto lastValue = _last->value;
        int lastPriority = _last->priority;

        auto parent = _last->parent.lock();
        if (parent->right == _last) {
            parent->right = nullptr;
        } else {
            parent->left = nullptr;
        }

        _root->value = lastValue;
        _root->priority = lastPriority;

        _last = findNewLast_pop(_root);

        --_size;
        siftDown(_root);
    }

};
#endif // HEAPLIST_H
