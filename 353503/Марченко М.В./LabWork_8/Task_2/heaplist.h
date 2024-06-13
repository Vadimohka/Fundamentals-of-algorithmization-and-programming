#ifndef HEAPLIST_H
#define HEAPLIST_H

#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class HeapList {
public:
    void push(const T& value) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if (!root) {
            root = newNode;
        } else {
            insertNode(newNode, root, 0);
        }
    }

    void pop() {
        if (!root) return;
        if (!root->left && !root->right) {
            root.reset();
            return;
        }
        std::shared_ptr<Node> largestChild = getLargestChild(root);
        root->value = largestChild->value;
        removeNode(largestChild, root, 0);
    }

    const T& top() const {
        return root->value;
    }

    bool empty() const {
        return !root;
    }
    void clear() {
        root.reset();
    }

private:
    struct Node {
        T value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;

        Node(const T& v) : value(v) {}
    };

    std::shared_ptr<Node> root;

    void insertNode(std::shared_ptr<Node> newNode, std::shared_ptr<Node> currentNode, int depth) {
        if (depth % 2 == 0) {
            if (!currentNode->left) {
                currentNode->left = newNode;
                newNode->parent = currentNode;
            } else {
                insertNode(newNode, currentNode->left, depth + 1);
            }
        } else {
            if (!currentNode->right) {
                currentNode->right = newNode;
                newNode->parent = currentNode;
            } else {
                insertNode(newNode, currentNode->right, depth + 1);
            }
        }
        siftUp(newNode);
    }

    void removeNode(std::shared_ptr<Node> nodeToRemove, std::shared_ptr<Node> currentNode, int depth) {
        if (depth % 2 == 0) {
            if (currentNode->left == nodeToRemove) {
                currentNode->left.reset();
            } else {
                removeNode(nodeToRemove, currentNode->left, depth + 1);
            }
        } else {
            if (currentNode->right == nodeToRemove) {
                currentNode->right.reset();
            } else {
                removeNode(nodeToRemove, currentNode->right, depth + 1);
            }
        }
        siftDown(currentNode);
    }

    std::shared_ptr<Node> getLargestChild(std::shared_ptr<Node> node) {
        if (!node->left && !node->right) return node;
        if (!node->left) return node->right;
        if (!node->right) return node->left;
        return (node->left->value > node->right->value) ? node->left : node->right;
    }

    void siftUp(std::shared_ptr<Node> node) {
        while (node->parent.lock() && node->value > node->parent.lock()->value) {
            std::swap(node->value, node->parent.lock()->value);
            node = node->parent.lock();
        }
    }

    void siftDown(std::shared_ptr<Node> node) {
        std::shared_ptr<Node> largestChild = getLargestChild(node);
        while (largestChild && largestChild->value > node->value) {
            std::swap(node->value, largestChild->value);
            node = largestChild;
            largestChild = getLargestChild(node);
        }
    }
};

#endif // HEAPLIST_H
