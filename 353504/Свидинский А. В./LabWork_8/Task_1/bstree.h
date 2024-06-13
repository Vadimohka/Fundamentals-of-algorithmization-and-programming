#ifndef BSTREE_H
#define BSTREE_H

#include <QVector>
#include "treenode.h"

template <typename T>
class BSTree {
public:
    BSTree() : root(nullptr) {}

    // void add(long key, const T &val) {
    //     root = addRec(root, key, val);
    // }

    void add(long key, const T &val) {
        // Проверяем, существует ли уже узел с таким ключом
        if (!find(key)) {
            root = addRec(root, key, val);
        }
    }

    bool find(long key) {
        return findRec(root, key);
    }

    void remove(long key) {
        root = removeRec(root, key);
    }

    QVector<long> inOrderTraverse() {
        QVector<long> keys;
        inOrderTraverseRec(root, keys);
        return keys;
    }

    void insertSubtree(TreeNode<T> *subtreeRoot) {
        if (subtreeRoot == nullptr) {
            return;
        }
        insertSubtreeRec(subtreeRoot);
    }

    void removeSubtree(TreeNode<T> *subtreeRoot) {
        if (subtreeRoot == nullptr) {
            return;
        }
        removeSubtreeRec(subtreeRoot);
    }

    TreeNode<T>* findLowestCommonAncestor(long key1, long key2) {
        return findLowestCommonAncestorRec(root, key1, key2);
    }

    TreeNode<T>* getRoot() {
        return root;
    }

    void balanceTree() {
        QVector<QPair<long, T>> sortedPairs;
        inOrderToVec(root, sortedPairs); // Нужно реализовать этот метод
        root = buildBalancedTree(sortedPairs, 0, sortedPairs.size() - 1);
    }

private:
    TreeNode<T> *root;

    TreeNode<T>* addRec(TreeNode<T> *node, long key, const T &val) {
        if (node == nullptr) {
            return new TreeNode<T>(key, val);
        }

        // Сравниваем значения, а не ключи
        if (val < node->data) {
            node->left_child = addRec(node->left_child, key, val);
        } else if (val > node->data) {
            node->right_child = addRec(node->right_child, key, val);
        }

        // Если значение уже существует, обновляем ключ
        else if (val == node->data) {
            node->key = key;
        }

        return node;
    }

    // TreeNode<T>* addRec(TreeNode<T> *node, long key, const T &val) {
    //     if (node == nullptr) {
    //         return new TreeNode<T>(key, val);
    //     }

    //     if (key < node->key) {
    //         node->left_child = addRec(node->left_child, key, val);
    //     } else if (key > node->key) {
    //         node->right_child = addRec(node->right_child, key, val);
    //     }

    //     return node;
    // }

    bool findRec(TreeNode<T> *node, long key) {
        if (node == nullptr) {
            return false;
        }

        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            return findRec(node->left_child, key);
        } else {
            return findRec(node->right_child, key);
        }
    }

    TreeNode<T>* removeRec(TreeNode<T> *node, long key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left_child = removeRec(node->left_child, key);
        } else if (key > node->key) {
            node->right_child = removeRec(node->right_child, key);
        } else {
            if (node->left_child == nullptr) {
                TreeNode<T> *temp = node->right_child;
                delete node;
                return temp;
            } else if (node->right_child == nullptr) {
                TreeNode<T> *temp = node->left_child;
                delete node;
                return temp;
            }

            TreeNode<T> *temp = findMin(node->right_child);
            node->key = temp->key;
            node->data = temp->data;
            node->right_child = removeRec(node->right_child, temp->key);
        }

        return node;
    }

    TreeNode<T>* findMin(TreeNode<T> *node) {
        while (node->left_child != nullptr) {
            node = node->left_child;
        }
        return node;
    }

    void inOrderTraverseRec(TreeNode<T> *node, QVector<long> &keys) {
        if (node != nullptr) {
            inOrderTraverseRec(node->left_child, keys);
            keys.push_back(node->key);
            inOrderTraverseRec(node->right_child, keys);
        }
    }

    void removeSubtreeRec(TreeNode<T> *subtreeRoot) {
        remove(subtreeRoot->key);
        if (subtreeRoot->right_child)
            removeSubtreeRec(subtreeRoot->right_child);
        if (subtreeRoot->left_child)
            removeSubtreeRec(subtreeRoot->left_child);
    }

    void insertSubtreeRec(TreeNode<T> *subtreeRoot) {
        add(subtreeRoot->key, subtreeRoot->data);
        if (subtreeRoot->right_child)
            insertSubtreeRec(subtreeRoot->right_child);
        if (subtreeRoot->left_child)
            insertSubtreeRec(subtreeRoot->left_child);
    }

    TreeNode<T>* findLowestCommonAncestorRec(TreeNode<T> *node, long key1, long key2) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->key > key1 && node->key > key2) {
            return findLowestCommonAncestorRec(node->left_child, key1, key2);
        }

        if (node->key < key1 && node->key < key2) {
            return findLowestCommonAncestorRec(node->right_child, key1, key2);
        }

        return node;
    }


    TreeNode<T>* buildBalancedTree(QVector<QPair<long, T>>& sortedPairs, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        TreeNode<T>* newNode = new TreeNode<T>(sortedPairs[mid].first, sortedPairs[mid].second);
        newNode->left_child = buildBalancedTree(sortedPairs, start, mid - 1);
        newNode->right_child = buildBalancedTree(sortedPairs, mid + 1, end);
        return newNode;
    }


    void inOrderToVec(TreeNode<T> *node, QVector<QPair<long, T>>& sortedPairs) {
        if (node != nullptr) {
            inOrderToVec(node->left_child, sortedPairs);
            sortedPairs.push_back(QPair<long, T>(node->key, node->data));
            inOrderToVec(node->right_child, sortedPairs);
        }
    }

};

#endif // BSTREE_H
