#include "heaplist.h"
#include <queue>
#include <stdexcept>

HeapList::HeapList() : root(nullptr) {}

void HeapList::insert(int value) {
    auto newNode = std::make_shared<Node>(value);
    if (!root) {
        root = newNode;
    } else {
        auto parent = findParentForNewNode();
        newNode->parent = parent;
        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    nodeList.push_back(newNode);
    heapifyUp(newNode);
}

int HeapList::extractMax() {
    if (!root) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = root->value;
    auto lastNode = getLastNode();
    if (lastNode == root) {
        root = nullptr;
    } else {
        root->value = lastNode->value;
        auto parent = lastNode->parent.lock();
        if (parent->left == lastNode) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        heapifyDown(root);
    }
    return maxValue;
}

bool HeapList::isEmpty() const {
    return !root;
}

void HeapList::heapifyUp(std::shared_ptr<Node> node) {
    while (node->parent.lock()) {
        auto parent = node->parent.lock();
        if (node->value <= parent->value) {
            break;
        }
        std::swap(node->value, parent->value);
        node = parent;
    }
}

void HeapList::heapifyDown(std::shared_ptr<Node> node) {
    while (node->left || node->right) {
        auto largerChild = node->left;
        if (node->right && node->right->value > node->left->value) {
            largerChild = node->right;
        }
        if (node->value >= largerChild->value) {
            break;
        }
        std::swap(node->value, largerChild->value);
        node = largerChild;
    }
}

std::shared_ptr<HeapList::Node> HeapList::getLastNode() {
    if (!root) {
        return nullptr;
    }
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);
    std::shared_ptr<Node> lastNode;
    while (!q.empty()) {
        lastNode = q.front();
        q.pop();
        if (lastNode->left) {
            q.push(lastNode->left);
        }
        if (lastNode->right) {
            q.push(lastNode->right);
        }
    }
    return lastNode;
}

std::shared_ptr<HeapList::Node> HeapList::findParentForNewNode() {
    if (!root) {
        return nullptr;
    }
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (!node->left || !node->right) {
            return node;
        }
        q.push(node->left);
        q.push(node->right);
    }
    return nullptr;
}

size_t HeapList::size() const {
    return nodeList.size();
}

std::vector<int> HeapList::Data() const {
    std::vector<int> values;
    for (const auto& weakNode : nodeList) {
        if (auto node = weakNode.lock()) {
            values.push_back(node->value);
        }
    }
    return values;
}
