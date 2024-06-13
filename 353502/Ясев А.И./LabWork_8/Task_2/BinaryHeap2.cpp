#include "BinaryHeap2.h"

#include <queue>
#include <stdexcept>

template<typename T>
std::shared_ptr<typename BinaryHeap2<T>::Node> BinaryHeap2<T>::getLastNode()
{
    if (empty()) {
        return nullptr;
    }

    std::queue<std::shared_ptr<Node>> queue;
    queue.push(_root);
    std::shared_ptr<Node> lastNode;

    while (!queue.empty()) {
        lastNode = queue.front();
        queue.pop();

        if (lastNode->left) {
            queue.push(lastNode->left);
        }

        if (lastNode->right) {
            queue.push(lastNode->right);
        }
    }

    return lastNode;
}

template<typename T>
void BinaryHeap2<T>::removeLastNode()
{
    if (empty()) {
        return;
    }

    auto lastNode = getLastNode();
    auto parent = lastNode->parent.lock();

    if (parent) {
        if (parent->left == lastNode) {
            parent->left = nullptr;
        } else if (parent->right == lastNode) {
            parent->right = nullptr;
        }
    }

    --_size;
}

template<typename T>
void BinaryHeap2<T>::sift_up(std::shared_ptr<Node> node)
{
    while (node->parent.lock() && node->value > node->parent.lock()->value) {
        std::swap(node->value, node->parent.lock()->value);
        node = node->parent.lock();
    }
}

template<typename T>
void BinaryHeap2<T>::sift_down(std::shared_ptr<Node> node)
{
    while (true) {
        auto left = node->left;
        auto right = node->right;
        auto largest = node;

        if (left && left->value > largest->value) {
            largest = left;
        }

        if (right && right->value > largest->value) {
            largest = right;
        }

        if (largest != node) {
            std::swap(node->value, largest->value);
            node = largest;
        } else {
            break;
        }
    }
}

template<typename T>
BinaryHeap2<T>::BinaryHeap2()
    : _root(nullptr)
    , _size(0)
{}

template<typename T>
BinaryHeap2<T>::~BinaryHeap2()
{
    clear();
}

template<typename T>
void BinaryHeap2<T>::clear()
{
    _root.reset();
    _size = 0;
}

template<typename T>
void BinaryHeap2<T>::push(T value)
{
    auto newNode = std::make_shared<Node>(value);
    if (empty()) {
        _root = newNode;
    } else {
        std::queue<std::shared_ptr<Node>> q;
        q.push(_root);
        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            if (!current->left) {
                current->left = newNode;
                newNode->parent = current;
                break;
            } else if (!current->right) {
                current->right = newNode;
                newNode->parent = current;
                break;
            } else {
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
    ++_size;
    sift_up(newNode);
}

template<typename T>
T BinaryHeap2<T>::pop()
{
    if (empty()) {
        throw std::out_of_range("Heap is empty");
    }

    T maxValue = _root->value;
    auto lastNode = getLastNode();
    if (_root == lastNode) {
        _root = nullptr;
        --_size;
    } else {
        _root->value = lastNode->value;
        removeLastNode();
        sift_down(_root);
    }

    return maxValue;
}

template<typename T>
T &BinaryHeap2<T>::max()
{
    if (empty()) {
        throw std::out_of_range("Heap is empty");
    }

    return _root->value;
}

template<typename T>
size_t BinaryHeap2<T>::size()
{
    return _size;
}

template<typename T>
bool BinaryHeap2<T>::empty()
{
    return _size == 0;
}

template class BinaryHeap2<int32_t>;
