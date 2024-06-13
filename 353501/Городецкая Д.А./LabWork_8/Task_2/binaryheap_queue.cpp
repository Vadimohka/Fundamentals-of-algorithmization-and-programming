#include "binaryheap_queue.h"

template<typename T>
void binaryheap_queue<T>::sift_up(std::shared_ptr<Node> node)
{
    while (node->parent.lock() && node->value > node->parent.lock()->value) {
        std::swap(node->value, node->parent.lock()->value);
        node = node->parent.lock();
    }
}

template<typename T>
void binaryheap_queue<T>::sift_down(std::shared_ptr<Node> node)
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
binaryheap_queue<T>::binaryheap_queue()
    : _root(nullptr)
    , _size(0)
{}

template<typename T>
binaryheap_queue<T>::~binaryheap_queue()
{
    clear();
}

template<typename T>
void binaryheap_queue<T>::clear()
{
    _root.reset();
    _size = 0;
}

template<typename T>
void binaryheap_queue<T>::push(T value)
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
T binaryheap_queue<T>::pop()
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
T &binaryheap_queue<T>::max()
{
    if (empty()) {
        throw std::out_of_range("Heap is empty");
    }

    return _root->value;
}

template<typename T>
size_t binaryheap_queue<T>::size()
{
    return _size;
}

template<typename T>
bool binaryheap_queue<T>::empty()
{
    return _size == 0;
}

template class binaryheap_queue<int32_t>;
