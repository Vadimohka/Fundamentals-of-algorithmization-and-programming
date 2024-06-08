
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <QString>
#include <QVector>
#include <QPair>
#include <algorithm>

template <typename T> class BST {
public:
    class Data {
    public:
        T key;
        Data* leftSon;
        Data* rightSon;

        Data(T initKey){
            key = initKey;
            leftSon = nullptr;
            rightSon = nullptr;
        }
    };

private:
    void insertInTree(T key, Data* &tree) {
        if (tree == nullptr) tree = new Data(key);
        else if (key <= tree->key) insertInTree(key, tree->leftSon);
        else insertInTree(key, tree->rightSon);
    }

    void removeFromTree(T key, Data* &tree, Data* parent = nullptr, int side = 0) {
        if (tree == nullptr) return;

        if (key < tree->key) {
            removeFromTree(key, tree->leftSon, tree, -1);
        } else if (key > tree->key) {
            removeFromTree(key, tree->rightSon, tree, 1);
        } else {
            if (tree->leftSon == nullptr && tree->rightSon == nullptr) {
                if (parent == nullptr) {
                    delete tree;
                    root = nullptr;
                } else {
                    if (side == -1) parent->leftSon = nullptr;
                    else if (side == 1) parent->rightSon = nullptr;
                    delete tree;
                }
            } else if (tree->leftSon == nullptr) {
                Data* temp = tree;
                if (parent == nullptr) {
                    root = tree->rightSon;
                    delete temp;
                } else {
                    if (side == -1) parent->leftSon = tree->rightSon;
                    else if (side == 1) parent->rightSon = tree->rightSon;
                    delete temp;
                }
            } else if (tree->rightSon == nullptr) {
                Data* temp = tree;
                if (parent == nullptr) {
                    root = tree->leftSon;
                    delete temp;
                } else {
                    if (side == -1) parent->leftSon = tree->leftSon;
                    else if (side == 1) parent->rightSon = tree->leftSon;
                    delete temp;
                }
            } else {
                Data* successor = findMin(tree->rightSon);
                tree->key = successor->key;
                removeFromTree(successor->key, tree->rightSon, tree, 1);
            }
        }
    }

    Data* findMin(Data* node) {
        while (node->leftSon != nullptr) {
            node = node->leftSon;
        }
        return node;
    }

    int height(Data* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->leftSon), height(node->rightSon));
    }

    void balanceTreeHelper(Data* &node) {
        if (node == nullptr) return;

        int balanceFactor = height(node->leftSon) - height(node->rightSon);

        if (balanceFactor > 1) {
            if (height(node->leftSon->leftSon) >= height(node->leftSon->rightSon)) {
                rotateRight(node);
            } else {
                rotateLeft(node->leftSon);
                rotateRight(node);
            }
        }
        else if (balanceFactor < -1) {
            if (height(node->rightSon->rightSon) >= height(node->rightSon->leftSon)) {
                rotateLeft(node);
            } else {
                rotateRight(node->rightSon);
                rotateLeft(node);
            }
        }

        balanceTreeHelper(node->leftSon);
        balanceTreeHelper(node->rightSon);
    }

    void rotateLeft(Data* &node) {
        Data* temp = node->rightSon;
        node->rightSon = temp->leftSon;
        temp->leftSon = node;
        node = temp;
    }

    void rotateRight(Data* &node) {
        Data* temp = node->leftSon;
        node->leftSon = temp->rightSon;
        temp->rightSon = node;
        node = temp;
    }

    void clearTree(Data* node) {
        if (node != nullptr) {
            clearTree(node->leftSon);
            clearTree(node->rightSon);
            delete node;
        }
    }

    void preOrder(Data* node, QVector<T>& result) {
        if (node == nullptr) return;
        result.push_back(node->key);
        preOrder(node->leftSon, result);
        preOrder(node->rightSon, result);
    }

    void inOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        inOrder(node->leftSon, result);
        result.push_back(node->key);
        inOrder(node->rightSon, result);
    }

    void postOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        postOrder(node->leftSon, result);
        postOrder(node->rightSon, result);
        result.push_back(node->key);
    }

    Data* findLCA(Data* node, T n1, T n2) {
        if (node == nullptr) return nullptr;

        if (node->key > n1 && node->key > n2) return findLCA(node->leftSon, n1, n2);

        if (node->key < n1 && node->key < n2) return findLCA(node->rightSon, n1, n2);

        return node;
    }

public:
    Data* root = nullptr;

    BST() {}

    BST(QVector<T> keys) {
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
        if (key > tree->key) return findNode(key, tree->rightSon);
        else return findNode(key, tree->leftSon);
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
            if (parentNode->leftSon == nullptr) parentNode->leftSon = subtree;
            else if (parentNode->rightSon == nullptr) parentNode->rightSon = subtree;
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

#endif // BINARYSEARCHTREE_H
