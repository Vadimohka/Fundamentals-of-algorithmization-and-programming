#ifndef BSTREE_H
#define BSTREE_H

#include <QVector>
#include "treenode.h"

template<typename T>
class BSTree
{
public:
    BSTree()
        : root(nullptr)
    {}

    void add(long key, const T &val) { root = addRec(root, key, val); }

    bool find(long key) { return findRec(root, key); }

    void remove(long key) { root = removeRec(root, key); }

    QVector<long> inOrderTraverse()
    {
        QVector<long> keys;
        inOrderTraverseRec(root, keys);
        return keys;
    }

    QVector<long> preOrderTraverse()
    {
        QVector<long> keys;
        preOrderTraverseRec(root, keys);
        return keys;
    }

    QVector<long> postOrderTraverse()
    {
        QVector<long> keys;
        postOrderTraverseRec(root, keys);
        return keys;
    }

    void insertSubtree(TreeNode<T> *subtreeRoot)
    {
        if (subtreeRoot == nullptr) {
            return;
        }
        insertSubtreeRec(subtreeRoot);
    }

    void removeSubtree(TreeNode<T> *subtreeRoot)
    {
        if (subtreeRoot == nullptr) {
            return;
        }
        removeSubtreeRec(subtreeRoot);
    }

    TreeNode<T> *findLowestCommonAncestor(long key1, long key2)
    {
        return findLowestCommonAncestorRec(root, key1, key2);
    }

    TreeNode<T> *getRoot() { return root; }

private:
    TreeNode<T> *root;

    TreeNode<T> *addRec(TreeNode<T> *node, long key, const T &val)
    {
        if (node == nullptr) {
            return new TreeNode<T>(key, val);
        }

        if (key < node->key) {
            node->left_child = addRec(node->left_child, key, val);
        } else if (key > node->key) {
            node->right_child = addRec(node->right_child, key, val);
        }

        return node;
    }

    bool findRec(TreeNode<T> *node, long key)
    {
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

    TreeNode<T> *removeRec(TreeNode<T> *node, long key)
    {
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

    TreeNode<T> *findMin(TreeNode<T> *node)
    {
        while (node->left_child != nullptr) {
            node = node->left_child;
        }
        return node;
    }

    void inOrderTraverseRec(TreeNode<T> *node, QVector<long> &keys)
    {
        if (node != nullptr) {
            inOrderTraverseRec(node->left_child, keys);
            keys.push_back(node->key);
            inOrderTraverseRec(node->right_child, keys);
        }
    }

    void preOrderTraverseRec(TreeNode<T> *node, QVector<long> &keys)
    {
        if (node != nullptr) {
            keys.append(node->key);
            preOrderTraverseRec(node->left_child, keys);
            preOrderTraverseRec(node->right_child, keys);
        }
    }

    void postOrderTraverseRec(TreeNode<T> *node, QVector<long> &keys)
    {
        if (node != nullptr) {
            postOrderTraverseRec(node->left_child, keys);
            postOrderTraverseRec(node->right_child, keys);
            keys.append(node->key);
        }
    }

    void removeSubtreeRec(TreeNode<T> *subtreeRoot)
    {
        remove(subtreeRoot->key);
        if (subtreeRoot->right_child)
            removeSubtreeRec(subtreeRoot->right_child);
        if (subtreeRoot->left_child)
            removeSubtreeRec(subtreeRoot->left_child);
    }

    void insertSubtreeRec(TreeNode<T> *subtreeRoot)
    {
        add(subtreeRoot->key, subtreeRoot->data);
        if (subtreeRoot->right_child)
            insertSubtreeRec(subtreeRoot->right_child);
        if (subtreeRoot->left_child)
            insertSubtreeRec(subtreeRoot->left_child);
    }

    TreeNode<T> *findLowestCommonAncestorRec(TreeNode<T> *node, long key1, long key2)
    {
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
};

#endif // BSTREE_H
