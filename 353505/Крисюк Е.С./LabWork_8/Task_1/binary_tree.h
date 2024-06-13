#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QString>
#include <QVector>
#include <QPair>
#include <algorithm>

template <typename T>

class Binary_tree {

public:
    class Node {
    public:
        T key;
        Node* left;
        Node* right;

        Node(T k){
            key = k;
            left = nullptr;
            right = nullptr;
        }
    };

private:
    void Insert(T key, Node* &tree) {
        if (tree == nullptr){
            tree = new Node(key);
        }

        else if (key <= tree->key) {

            Insert(key, tree->left);
        }

        else {
            Insert(key, tree->right);
        }
    }

    void remove(T key, Node* &tree, Node* parent = nullptr, int side = 0) {
        if (tree == nullptr) {
            return;
        }

        if (key < tree->key) {
            remove(key, tree->left, tree, -1);

        }
        else if (key > tree->key) {
            remove(key, tree->right, tree, 1);
        }
        else {
            if (!tree -> left && !tree -> right) {
                if (parent == nullptr) {
                    delete tree;
                    root = nullptr;
                }

                else {

                    if (side == -1) {
                        parent -> left = nullptr;
                    }

                    else if (side == 1) {
                        parent -> right = nullptr;
                    }
                    delete tree;
                }

            }

            else if (!tree -> left) {
                Node* temp = tree;

                if (!parent) {
                    root = tree -> right;
                    delete temp;

                }
                else {
                    if (side == -1){
                        parent->left = tree->right;
                    }

                    else if (side == 1) {
                        parent -> right = tree -> right;
                    }

                    delete temp;
                }
            }
            else if (!tree -> right) {
                Node* temp = tree;
                if (parent == nullptr) {
                    root = tree->left;
                    delete temp;
                } else {
                    if (side == -1) parent->left = tree->left;
                    else if (side == 1) parent->right = tree->left;
                    delete temp;
                }
            } else {
                Node* successor = findMin(tree->right);
                tree->key = successor->key;
                remove(successor->key, tree->right, tree, 1);
            }
        }
    }

    Node* findMin(Node* node)
    {
        while (node -> left) {
            node = node->left;
        }

        return node;
    }

    int height(Node* node) {

        if (node == nullptr)
            return 0;

        return 1 + std::max(height(node->left), height(node->right));
    }

    void Balance_tree(Node* &node) {
        if (node == nullptr) return;

        int balanceFactor = height(node->left) - height(node->right);

        if (balanceFactor > 1) {
            if (height(node->left->left) >= height(node->left->right)) {
                rotateRight(node);
            } else {
                rotateLeft(node->left);
                rotateRight(node);
            }
        }
        else if (balanceFactor < -1) {
            if (height(node->right->right) >= height(node->right->left)) {
                rotateLeft(node);
            } else {
                rotateRight(node->right);
                rotateLeft(node);
            }
        }

        Balance_tree(node->left);
        Balance_tree(node->right);
    }

    void rotateLeft(Node* &node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
    }

    void rotateRight(Node* &node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
    }

    void clearTree(Node* node) {
        if (node != nullptr) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }

    Node* find_ancestor(Node* node, T n1, T n2) {
        if (node == nullptr) return nullptr;

        if (node->key > n1 && node->key > n2)

            return find_ancestor(node->left, n1, n2);

        if (node->key < n1 && node->key < n2)

            return find_ancestor(node->right, n1, n2);


        return node;
    }

public:
    Node* root = nullptr;

    Binary_tree() {}

    Binary_tree(QVector<T> keys) {
        for (T el : keys)
            insert(el);
    }

    void insert(T key) {
        Insert(key, root);
    }

    T find(T key) {
        Node* result = findNode(key, root);
        return result ? result->key : T();
    }

    Node* findNode(T key, Node* tree) {
        if (tree == nullptr) return nullptr;
        if (tree->key == key) return tree;
        if (key > tree->key) return findNode(key, tree->right);
        else return findNode(key, tree->left);
    }

    void remove(T key) {
        remove(key, root);
    }

    void balanceTree() {
        Balance_tree(root);
    }

    void insertSubtree(Node* subtree, T parentKey) {
        Node* parentNode = findNode(parentKey, root);
        if (parentNode) {
            if (parentNode->left == nullptr) parentNode->left = subtree;
            else if (parentNode->right == nullptr) parentNode->right = subtree;
        }
    }

    void remove_subtree(T key) {
        Node* node = findNode(key, root);
        if (node) {
            clearTree(node);
        }
    }

    void insert_branch(Node* branch, T parentKey) {
        insertSubtree(branch, parentKey);
    }

    void remove_branch(T key) {
        remove_subtree(key);
    }

    void insertAtPosition(T key, Node* position) {
        if (position == nullptr) return;
        Insert(key, position);
    }

    Node* find_ancestor(T n1, T n2) {
        return find_ancestor(root, n1, n2);
    }
};

#endif // BINARYTREE_H
