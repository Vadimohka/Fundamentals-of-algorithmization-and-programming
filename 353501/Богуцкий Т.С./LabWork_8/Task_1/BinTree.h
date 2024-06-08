#ifndef BINTREE_H
#define BINTREE_H

#include <QString>
#include <QVector>
#include <QPair>
#include <algorithm>

template <typename T> class BinaryTree {
public:
    class Data {
    public:
        T key;
        Data* LeftChild;
        Data* RightChild;

        Data(T initKey){
            key = initKey;
            LeftChild = nullptr;
            RightChild = nullptr;
        }
    };

private:
    void insertInTree(T key, Data* &tree) {
        if (tree == nullptr) tree = new Data(key);
        else if (key <= tree->key) insertInTree(key, tree->LeftChild);
        else insertInTree(key, tree->RightChild);
    }

    void removeFromTree(T key, Data* &tree, Data* parent = nullptr, int side = 0) {
        if (tree == nullptr) return;

        if (key < tree->key) {
            removeFromTree(key, tree->LeftChild, tree, -1);
        } else if (key > tree->key) {
            removeFromTree(key, tree->RightChild, tree, 1);
        } else {
            if (tree->LeftChild == nullptr && tree->RightChild == nullptr) {
                if (parent == nullptr) {
                    delete tree;
                    root = nullptr;
                } else {
                    if (side == -1) parent->LeftChild = nullptr;
                    else if (side == 1) parent->RightChild = nullptr;
                    delete tree;
                }
            } else if (tree->LeftChild == nullptr) {
                Data* temp = tree;
                if (parent == nullptr) {
                    root = tree->RightChild;
                    delete temp;
                } else {
                    if (side == -1) parent->LeftChild = tree->RightChild;
                    else if (side == 1) parent->RightChild = tree->RightChild;
                    delete temp;
                }
            } else if (tree->RightChild == nullptr) {
                Data* temp = tree;
                if (parent == nullptr) {
                    root = tree->LeftChild;
                    delete temp;
                } else {
                    if (side == -1) parent->LeftChild = tree->LeftChild;
                    else if (side == 1) parent->RightChild = tree->LeftChild;
                    delete temp;
                }
            } else {
                Data* successor = findMin(tree->RightChild);
                tree->key = successor->key;
                removeFromTree(successor->key, tree->RightChild, tree, 1);
            }
        }
    }

    Data* findMin(Data* node) {
        while (node->LeftChild != nullptr) {
            node = node->LeftChild;
        }
        return node;
    }

    int height(Data* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->LeftChild), height(node->RightChild));
    }

    void balanceTreeHelper(Data* &node) {
        if (node == nullptr) return;

        int balanceFactor = height(node->LeftChild) - height(node->RightChild);

        if (balanceFactor > 1) {
            if (height(node->LeftChild->LeftChild) >= height(node->LeftChild->RightChild)) {
                rotateRight(node);
            } else {
                rotateLeft(node->LeftChild);
                rotateRight(node);
            }
        }
        else if (balanceFactor < -1) {
            if (height(node->RightChild->RightChild) >= height(node->RightChild->LeftChild)) {
                rotateLeft(node);
            } else {
                rotateRight(node->RightChild);
                rotateLeft(node);
            }
        }

        balanceTreeHelper(node->LeftChild);
        balanceTreeHelper(node->RightChild);
    }

    void rotateLeft(Data* &node) {
        Data* temp = node->RightChild;
        node->RightChild = temp->LeftChild;
        temp->LeftChild = node;
        node = temp;
    }

    void rotateRight(Data* &node) {
        Data* temp = node->LeftChild;
        node->LeftChild = temp->RightChild;
        temp->RightChild = node;
        node = temp;
    }

    void clearTree(Data* node) {
        if (node != nullptr) {
            clearTree(node->LeftChild);
            clearTree(node->RightChild);
            delete node;
        }
    }

    void preOrder(Data* node, QVector<T>& result) {
        if (node == nullptr) return;
        result.push_back(node->key);
        preOrder(node->LeftChild, result);
        preOrder(node->RightChild, result);
    }

    void inOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        inOrder(node->LeftChild, result);
        result.push_back(node->key);
        inOrder(node->RightChild, result);
    }

    void postOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        postOrder(node->LeftChild, result);
        postOrder(node->RightChild, result);
        result.push_back(node->key);
    }

    Data* findLCA(Data* node, T n1, T n2) {
        if (node == nullptr) return nullptr;

        if (node->key > n1 && node->key > n2) return findLCA(node->LeftChild, n1, n2);

        if (node->key < n1 && node->key < n2) return findLCA(node->RightChild, n1, n2);

        return node;
    }

public:
    Data* root = nullptr;

    BinaryTree() {}
    BinaryTree(QVector<T> keys) {
        for (T el : keys)
            insert(el);
    }

    void insert(T key) {
        insertInTree(key, root);
    }

    T find(T key) {
        Data* result = findNode(key, root);
        return result ? result->key : T();
    }

    Data* findNode(T key, Data* tree) {
        if (tree == nullptr) return nullptr;
        if (tree->key == key) return tree;
        if (key > tree->key) return findNode(key, tree->RightChild);
        else return findNode(key, tree->LeftChild);
    }

    void remove(T key) {
        removeFromTree(key, root);
    }

    QVector<QString> preOrderTraversal() {
        QVector<QString> result;
        preOrder(root, result);
        return result;
    }

    QVector<QString> inOrderTraversal() {
        QVector<QString> result;
        inOrder(root, result);
        return result;
    }

    QVector<QString> postOrderTraversal() {
        QVector<QString> result;
        postOrder(root, result);
        return result;
    }

    void balanceTree() {
        balanceTreeHelper(root);
    }

    void insertSubtree(Data* subtree, T parentKey) {
        Data* parentNode = findNode(parentKey, root);
        if (parentNode) {
            if (parentNode->LeftChild == nullptr) parentNode->LeftChild = subtree;
            else if (parentNode->RightChild == nullptr) parentNode->RightChild = subtree;
        }
    }

    void removeSubtree(T key) {
        Data* node = findNode(key, root);
        if (node) {
            clearTree(node);
        }
    }

    void insertBranch(Data* branch, T parentKey) {
        insertSubtree(branch, parentKey);
    }

    void removeBranch(T key) {
        removeSubtree(key);
    }

    void insertAtPosition(T key, Data* position) {
        if (position == nullptr) return;
        insertInTree(key, position);
    }

    Data* findLCA(T n1, T n2) {
        return findLCA(root, n1, n2);
    }
};

#endif // BINTREE_H
