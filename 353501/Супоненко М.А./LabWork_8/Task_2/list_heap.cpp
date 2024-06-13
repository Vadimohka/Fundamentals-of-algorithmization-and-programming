#include "list_heap.h"

ListHeap::ListHeap() : root(nullptr) {}

void ListHeap::insert(int value) {
    auto newNode = std::make_shared<ListNode>(value);
    if (!root) {
        root = newNode;
    } else {
        auto parent = nodes[(nodes.size() - 1) / 2].lock();
        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        newNode->parent = parent;
    }
    nodes.push_back(newNode);
    heapifyUp(newNode);
}

int ListHeap::extractMax() {
    if (isEmpty()) throw std::runtime_error("Heap is empty");
    int max = root->value;
    auto lastNode = getLastNode();
    root->value = lastNode->value;
    auto parent = lastNode->parent.lock();
    if (parent->left == lastNode) {
        parent->left = nullptr;
    } else {
        parent->right = nullptr;
    }
    nodes.pop_back();
    heapifyDown(root);
    return max;
}

int ListHeap::getMax() const {
    if (isEmpty()) throw std::runtime_error("Heap is empty");
    return root->value;
}

bool ListHeap::isEmpty() const {
    return nodes.empty();
}

void ListHeap::heapifyUp(std::shared_ptr<ListNode> node) {
    while (node->parent.lock() && node->value > node->parent.lock()->value) {
        std::swap(node->value, node->parent.lock()->value);
        node = node->parent.lock();
    }
}

void ListHeap::heapifyDown(std::shared_ptr<ListNode> node) {
    while (node->left || node->right) {
        auto largest = node;
        if (node->left && node->left->value > largest->value) {
            largest = node->left;
        }
        if (node->right && node->right->value > largest->value) {
            largest = node->right;
        }
        if (largest == node) break;
        std::swap(node->value, largest->value);
        node = largest;
    }
}

std::shared_ptr<ListNode> ListHeap::getLastNode() const {
    return nodes.back().lock();
}
