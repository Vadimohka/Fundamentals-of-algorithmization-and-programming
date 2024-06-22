#include "binaryheaplist.h"

BinaryHeapList::BinaryHeapList() : root(nullptr) {}

void BinaryHeapList::insert(int value) {
    auto newNode = std::make_shared<Node>(value);
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

int BinaryHeapList::extractMax() {
    if (!root) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = root->value;
    auto lastNode = getLastNode();
    if (root == lastNode) {
        root.reset();
    } else {
        root->value = lastNode->value;
        auto parent = lastNode->parent.lock();
        if (parent->right == lastNode) {
            parent->right.reset();
        } else {
            parent->left.reset();
        }
        heapifyDown(root);
    }
    nodes.pop_back();
    return maxValue;
}

int BinaryHeapList::getMax() const {
    if (!root) {
        throw std::runtime_error("Heap is empty");
    }
    return root->value;
}

bool BinaryHeapList::isEmpty() const {
    return !root;
}

void BinaryHeapList::heapifyUp(std::shared_ptr<Node> node) {
    while (auto parent = node->parent.lock()) {
        if (node->value <= parent->value) {
            break;
        }
        std::swap(node->value, parent->value);
        node = parent;
    }
}

void BinaryHeapList::heapifyDown(std::shared_ptr<Node> node) {
    while (node->left || node->right) {
        auto largest = node;
        if (node->left && node->left->value > largest->value) {
            largest = node->left;
        }
        if (node->right && node->right->value > largest->value) {
            largest = node->right;
        }
        if (largest == node) {
            break;
        }
        std::swap(node->value, largest->value);
        node = largest;
    }
}

std::shared_ptr<BinaryHeapList::Node> BinaryHeapList::getLastNode() const {
    return nodes.back().lock();
}

void BinaryHeapList::removeLastNode() {
    nodes.pop_back();
}
