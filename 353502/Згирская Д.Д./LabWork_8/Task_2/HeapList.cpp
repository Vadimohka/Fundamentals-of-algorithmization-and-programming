#include "HeapList.h"
#include <queue>
#include <stdexcept>


Node::Node(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
}

HeapList::HeapList() {
    root = nullptr;
    last = nullptr;
}

void HeapList::putUp(std::shared_ptr<Node> node) {
    while (node->parent.lock() && node->value > node->parent.lock()->value) {
        std::swap(node->value, node->parent.lock()->value);
        node = node->parent.lock();
    }
}

void HeapList::putDown(std::shared_ptr<Node> node) {
    while (node->left || node->right) {
        std::shared_ptr<Node> largerChild;

        if (node->left && node->right) {
            largerChild = (node->left->value > node->right->value) ? node->left : node->right;
        } else if (node->left) {
            largerChild = node->left;
        } else {
            largerChild = node->right;
        }

        if (node->value < largerChild->value) {
            std::swap(node->value, largerChild->value);
            node = largerChild;
        } else {
            break;
        }
    }
}

std::shared_ptr<Node> HeapList::getNextInsertPosition() {
    if (!root) {
        return nullptr;
    }

    std::queue<std::shared_ptr<Node>> q;
    q.push(root);

    while (!q.empty()) {
        std::shared_ptr<Node> current = q.front();
        q.pop();

        if (!current->left) {
            return current;
        } else {
            q.push(current->left);
        }

        if (!current->right) {
            return current;
        } else {
            q.push(current->right);
        }
    }

    return nullptr;
}

std::shared_ptr<Node> HeapList::getLastNode() {
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

void HeapList::insert(int value) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(value);

    if (!root) {
        root = newNode;
        last = newNode;
    } else {
        std::shared_ptr<Node> parent = getNextInsertPosition();
        newNode->parent = parent;

        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        last = newNode;
        putUp(newNode);
    }
}

int HeapList::extractMax() {
    if (!root) {
        return 0;
    }

    int maxValue = root->value;

    if (root == last) {
        root = nullptr;
        last = nullptr;
    } else {
        std::shared_ptr<Node> lastNode = getLastNode();
        root->value = lastNode->value;

        if (lastNode->parent.lock()->left == lastNode) {
            lastNode->parent.lock()->left = nullptr;
        } else {
            lastNode->parent.lock()->right = nullptr;
        }

        last = getLastNode();
        putDown(root);
    }

    return maxValue;
}

int HeapList::getMax() {
    if (!root) {
        throw std::runtime_error("Heap is empty");
    }

    return root->value;
}

bool HeapList::isEmpty() {
    return !root;
}

void HeapList::printHeap() {
    if (!root) {
        std::cout << "Heap is empty" << std::endl;
        return;
    }

    std::queue<std::shared_ptr<Node>> q;
    q.push(root);

    while (!q.empty()) {
        std::shared_ptr<Node> current = q.front();
        q.pop();

        std::cout << current->value << " ";

        if (current->left) {
            q.push(current->left);
        }

        if (current->right) {
            q.push(current->right);
        }
    }
}
