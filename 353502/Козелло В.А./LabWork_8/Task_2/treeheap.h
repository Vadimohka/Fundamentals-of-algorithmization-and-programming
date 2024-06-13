#ifndef TREEHEAP_H
#define TREEHEAP_H

#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
struct Node
{
    T value;
    std::weak_ptr<Node> parent;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    explicit Node(T val)
        : value(val)
        , left(nullptr)
        , right(nullptr)
    {}
};

template<typename T>
class TreeHeap
{
    std::shared_ptr<Node<T>> root;

    void heapifyUp(std::shared_ptr<Node<T>> node)
    {
        while (auto parent = node->parent.lock()) {
            if (node->value < parent->value) {
                std::swap(node->value, parent->value);
                node = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(std::shared_ptr<Node<T>> node)
    {
        while (node->left || node->right) {
            std::shared_ptr<Node<T>> smallest = node;
            if (node->left && node->left->value < smallest->value) {
                smallest = node->left;
            }
            if (node->right && node->right->value < smallest->value) {
                smallest = node->right;
            }
            if (smallest != node) {
                std::swap(node->value, smallest->value);
                node = smallest;
            } else {
                break;
            }
        }
    }

public:
    TreeHeap()
        : root(nullptr)
    {}

    void insert(T value)
    {
        auto newNode = std::make_shared<Node<T>>(value);

        if (!root) {
            root = newNode;
        } else {
            std::shared_ptr<Node<T>> current = root;
            while (current->left && current->right) {
                if (current->left->left && current->left->right) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            newNode->parent = current;
            if (!current->left) {
                current->left = newNode;
            } else {
                current->right = newNode;
            }
        }

        heapifyUp(newNode);
    }

    T extractMin()
    {
        if (!root) {
            throw std::underflow_error("Heap is empty");
        }

        int minValue = root->value;

        std::shared_ptr<Node<T>> lastNode = root;
        while (lastNode->left || lastNode->right) {
            if (lastNode->left && lastNode->right) {
                if (!lastNode->right->left && !lastNode->right->right) {
                    lastNode = lastNode->right;
                } else {
                    lastNode = lastNode->left;
                }
            } else {
                lastNode = lastNode->left ? lastNode->left : lastNode->right;
            }
        }

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
        }

        if (root) {
            heapifyDown(root);
        }
        return minValue;
    }

    bool isEmpty() const { return !root; }
};

#endif // TREEHEAP_H
