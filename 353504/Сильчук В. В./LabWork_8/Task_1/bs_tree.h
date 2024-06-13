#ifndef BS_TREE_H
#define BS_TREE_H

#include <QVector>
#include "tree_node.h"

template <typename T>
class BSTree {
public:
    BSTree() : root(nullptr) {}

    void add(long key, const T &val) {
        root = addRec(root, key, val);
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

    QVector<long> preOrderTraverse() {
        QVector<long> keys;
        preOrderTraverseRec(root, keys);
        return keys;
    }

    QVector<long> postOrderTraverse() {
        QVector<long> keys;
        postOrderTraverseRec(root, keys);
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
private:
    TreeNode<T> *root;

    TreeNode<T>* addRec(TreeNode<T> *node, long key, const T &val) {
        if (node == nullptr) {
            return new TreeNode<T>(key, val);
        }

        if (key < node->key) {
            node->leftchild = addRec(node->leftchild, key, val);
        } else if (key > node->key) {
            node->rightchild = addRec(node->rightchild, key, val);
        }

        return node;
    }

    bool findRec(TreeNode<T> *node, long key) {
        if (node == nullptr) {
            return false;
        }

        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            return findRec(node->leftchild, key);
        } else {
            return findRec(node->rightchild, key);
        }
    }

    TreeNode<T>* removeRec(TreeNode<T> *node, long key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->leftchild = removeRec(node->leftchild, key);
        } else if (key > node->key) {
            node->rightchild = removeRec(node->rightchild, key);
        } else {
            if (node->leftchild == nullptr) {
                TreeNode<T> *temp = node->rightchild;
                delete node;
                return temp;
            } else if (node->rightchild == nullptr) {
                TreeNode<T> *temp = node->leftchild;
                delete node;
                return temp;
            }

            TreeNode<T> *temp = findMin(node->rightchild);
            node->key = temp->key;
            node->data = temp->data;
            node->rightchild = removeRec(node->rightchild, temp->key);
        }

        return node;
    }

    TreeNode<T>* findMin(TreeNode<T> *node) {
        while (node->leftchild != nullptr) {
            node = node->leftchild;
        }
        return node;
    }

    void inOrderTraverseRec(TreeNode<T> *node, QVector<long> &keys) {
        if (node != nullptr) {
            inOrderTraverseRec(node->leftchild, keys);
            keys.push_back(node->key);
            inOrderTraverseRec(node->rightchild, keys);
        }
    }

    void preOrderTraverseRec(TreeNode<T> *node, QVector<long> &keys) {
        if (node != nullptr) {
            keys.append(node->key);
            preOrderTraverseRec(node->leftchild, keys);
            preOrderTraverseRec(node->rightchild, keys);
        }
    }

    void postOrderTraverseRec(TreeNode<T> *node, QVector<long> &keys) {
        if (node != nullptr) {
            postOrderTraverseRec(node->leftchild, keys);
            postOrderTraverseRec(node->rightchild, keys);
            keys.append(node->key);
        }
    }

    void removeSubtreeRec(TreeNode<T> *subtreeRoot) {
        remove(subtreeRoot->key);
        if (subtreeRoot->rightchild)
            removeSubtreeRec(subtreeRoot->rightchild);
        if (subtreeRoot->leftchild)
            removeSubtreeRec(subtreeRoot->leftchild);
    }

    void insertSubtreeRec(TreeNode<T> *subtreeRoot) {
        add(subtreeRoot->key, subtreeRoot->data);
        if (subtreeRoot->rightchild)
            insertSubtreeRec(subtreeRoot->rightchild);
        if (subtreeRoot->leftchild)
            insertSubtreeRec(subtreeRoot->leftchild);
    }

    TreeNode<T>* findLowestCommonAncestorRec(TreeNode<T> *node, long key1, long key2) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->key > key1 && node->key > key2) {
            return findLowestCommonAncestorRec(node->leftchild, key1, key2);
        }

        if (node->key < key1 && node->key < key2) {
            return findLowestCommonAncestorRec(node->rightchild, key1, key2);
        }

        return node;
    }
};

#endif // BS_TREE_H
