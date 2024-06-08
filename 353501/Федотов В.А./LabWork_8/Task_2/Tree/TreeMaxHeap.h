#pragma once

#include <memory>

class TreeMaxHeap {
protected:
    struct Node {
        int value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> root;
    int level;
    int levelIndex;

public:
    TreeMaxHeap() 
        : root(nullptr), level(0), levelIndex(0) {}

    void insert(int value) {
        if (level == 0) {
            root = std::make_shared<Node>();
            root->value = value;
            root->parent.reset();
            root->left.reset() ;
            root->right.reset() ;

            level++;
            levelIndex = 0;
            return;
        }

        std::shared_ptr<Node> current = root;
        for (int i = level - 1; i >= 0; i--) {
            int mask = (1 << i);
            if ((levelIndex & mask) != 0) {
                if (current->right == nullptr) {
                    current->right = std::make_shared<Node>();
                    current->right->parent = current;
                }
                current = current->right;
            } else {
                if (current->left == nullptr) {
                    current->left = std::make_shared<Node>();
                    current->left->parent = current;
                }
                current = current->left;
            }
        }

        current->value = value;
        levelIndex++;

        if (levelIndex == (1 << level)) {
            level++;
            levelIndex = 0;
        }

        heapifyUp(current);
    };

    int remove() {
        if (root == nullptr)
            return -1;
        
        int value = root->value;

        levelIndex--;
        if (levelIndex < 0) {
            level--;
            levelIndex = (1 << level) - 1;
        }

        if (level == 0) {
            root.reset();
            return value;
        }

        std::shared_ptr<Node> current = root;
        for (int i = level - 1; i >= 0; i--) {
            int mask = (1 << i);
            if ((levelIndex & mask) != 0)
                current = current->right;
            else
                current = current->left;
        }

        std::swap(current->value, root->value);
        std::shared_ptr<Node> parent = current->parent.lock();

        if (parent->left == current)
            parent->left.reset();
        
        if (parent->right == current)
            parent->right.reset();
        
        heapifyDown(root);

        return value;
    };

    bool empty() { return root == nullptr; }

    void clear() { root = nullptr; }

protected:
    void heapifyUp(std::shared_ptr<Node> node) {
        if (node->parent.lock() == nullptr)
            return;

        if (node->value > node->parent.lock()->value) {
            std::swap(node->value, node->parent.lock()->value);
            heapifyUp(node->parent.lock());
        }
    }

    void heapifyDown(std::shared_ptr<Node> node) {
        std::shared_ptr<Node> nextNode = node;
        int best = node->value;
        if (node->left) {
            if (node->left->value > best) {
                nextNode = node->left;
                best = node->left->value;
            }
        }

        if (node->right) {
            if (node->right->value > best) {
                nextNode = node->right;
                best = node->right->value;
            }
        }

        if (nextNode == node)
            return;

        std::swap(nextNode->value, node->value);
        heapifyDown(nextNode);
    }

};