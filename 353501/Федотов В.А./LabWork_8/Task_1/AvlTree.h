#pragma once

#include <QString>
#include <stdexcept>

template <typename T>
class AvlTree {
protected:
    struct Node {
        int key;
        T value;
        int height;
        Node* left;
        Node* right;

        Node(int key, T value)
            : key(key), value(value), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    AvlTree()
        : root(nullptr) {}

    void insert(int key, T value) {
        root = insertNode(root, key, value);
    }

    void remove(int key) {
        root = removeNode(root, key);
    }

    T& get(int key) const {
        Node* node = search(root, key);
        if (node)
            return node->value;
        else
            throw std::runtime_error("Key not found");
    }

    void clear() {
        root = clearTree(root);
        root = nullptr;
    }

protected:
    Node* clearTree(Node* node) {
        if (node) {
            node->left = clearTree(node->left);
            node->right = clearTree(node->right);
            Node* temp = node;
            node = balance(node);
            delete temp;
        }
        return node;
    }

    Node* insertNode(Node* node, int key, T value) {
        if (node == nullptr)
            return new Node(key, value);

        if (key < node->key)
            node->left = insertNode(node->left, key, value);
        else if (key > node->key)
            node->right = insertNode(node->right, key, value);
        else
            return node;

        node = balance(node);
        return node;
    }

    Node* removeNode(Node* node, int key) {
        if (node == nullptr)
            return nullptr;

        if (key < node->key) {
            node->left = removeNode(node->left, key);
        } else if (key > node->key) {
            node->right = removeNode(node->right, key);
        } else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* successor = findMinNode(node->right);
                node->key = successor->key;
                node->value = successor->value;
                node->right = removeNode(node->right, successor->key);
            }
        }

        node = balance(node);
        return node;
    }

    Node* search(Node* node, int key) const {
        if (!node || node->key == key) {
            return node;
        }

        if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    Node* balance(Node* node) {
        if (node == nullptr)
            return nullptr;

        updateHeight(node);
        int balanceFactor = getBalance(node);
        if (balanceFactor < -1) {
            if (getBalance(node->left) > 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        if (balanceFactor > 1) {
            if (getBalance(node->right) < 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->right) - getHeight(node->left) : 0;
    }

    void updateHeight(Node* node){
        if (node != nullptr) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    Node* findMinNode(Node* node) const {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};