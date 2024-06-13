#include "heaplist.h"
#include <queue>
#include <stdexcept>

void HeapList::insert(int value) {
    auto newNode = std::make_shared<HeapNode>(value);
    if (!root) {
        root = newNode;
        return;
    }

    std::queue<std::shared_ptr<HeapNode>> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        auto current = nodes.front();
        nodes.pop();

        if (!current->left) {
            current->left = newNode;
            newNode->parent = current;
            heapifyUp(newNode);
            return;
        } else if (!current->right) {
            current->right = newNode;
            newNode->parent = current;
            heapifyUp(newNode);
            return;
        } else {
            nodes.push(current->left);
            nodes.push(current->right);
        }
    }
}

int HeapList::extractMax() {
    if (!root) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = root->value;
    auto lastNode = getLastNode();
    if (lastNode == root) {
        root.reset();
    } else {
        root->value = lastNode->value;
        removeLastNode();
        heapifyDown(root);
    }
    return maxValue;
}

int HeapList::getMax() const {
    if (!root) {
        throw std::runtime_error("Heap is empty");
    }
    return root->value;
}

void HeapList::heapifyUp(std::shared_ptr<HeapNode> node) {
    while (auto parent = node->parent.lock()) {
        if (node->value <= parent->value) {
            break;
        }
        std::swap(node->value, parent->value);
        node = parent;
    }
}

void HeapList::heapifyDown(std::shared_ptr<HeapNode> node) {
    while (node) {
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

std::shared_ptr<HeapNode> HeapList::getLastNode() const {
    if (!root) return nullptr;

    std::queue<std::shared_ptr<HeapNode>> nodes;
    nodes.push(root);
    std::shared_ptr<HeapNode> lastNode;

    while (!nodes.empty()) {
        lastNode = nodes.front();
        nodes.pop();

        if (lastNode->left) nodes.push(lastNode->left);
        if (lastNode->right) nodes.push(lastNode->right);
    }

    return lastNode;
}

void HeapList::removeLastNode() {
    if (!root) return;

    std::queue<std::shared_ptr<HeapNode>> nodes;
    nodes.push(root);
    std::shared_ptr<HeapNode> lastNode;
    std::shared_ptr<HeapNode> parent;

    while (!nodes.empty()) {
        lastNode = nodes.front();
        nodes.pop();

        if (lastNode->left) {
            parent = lastNode;
            nodes.push(lastNode->left);
        }
        if (lastNode->right) {
            parent = lastNode;
            nodes.push(lastNode->right);
        }
    }

    if (parent->right) {
        parent->right.reset();
    } else if (parent->left) {
        parent->left.reset();
    }
}
