#include "heaplist.h"

HeapList::HeapList() : root(nullptr) {}

void HeapList::insert(int key) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(key);
    if (!head) {
        head = tail = newNode;
        root = newNode;
    } else {
        tail->next = newNode;
        newNode->parent = tail;
        if (!tail->parent.lock() || tail->parent.lock()->right == tail) {
            newNode->parent = tail;
            tail->right = newNode;
        } else {
            newNode->parent = tail->parent;
            tail->parent.lock()->left = newNode;
        }
        tail = newNode;
    }
    heapifyUp(newNode);
}

int HeapList::extractMax() {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }

    int max = root->key;
    if (head == tail) {
        head.reset();
        tail.reset();
        root.reset();
    } else {
        std::shared_ptr<Node> lastNode = getLastNode();
        root->key = lastNode->key;
        removeLastNode();
        heapifyDown(root);
    }
    return max;
}

int HeapList::getMax() const {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }
    return root->key;
}

bool HeapList::isEmpty() const {
    return root == nullptr;
}

void HeapList::heapifyUp(std::shared_ptr<Node> node) {
    while (auto parent = node->parent.lock()) {
        if (node->key <= parent->key) break;
        std::swap(node->key, parent->key);
        node = parent;
    }
}

void HeapList::heapifyDown(std::shared_ptr<Node> node) {
    while (node->left) {
        std::shared_ptr<Node> largerChild = node->left;
        if (node->right && node->right->key > node->left->key) {
            largerChild = node->right;
        }
        if (node->key >= largerChild->key) {
            break;
        }
        std::swap(node->key, largerChild->key);
        node = largerChild;
    }
}

std::shared_ptr<HeapList::Node> HeapList::getLastNode() const {
    return tail;
}

void HeapList::removeLastNode() {
    if (tail == head) {
        head.reset();
        tail.reset();
        root.reset();
    } else {
        std::shared_ptr<Node> lastNode = tail;
        std::shared_ptr<Node> parent = lastNode->parent.lock();
        if (parent->right == lastNode) {
            parent->right.reset();
        } else {
            parent->left.reset();
        }
        tail = parent;
        tail->next.reset();
    }
}
