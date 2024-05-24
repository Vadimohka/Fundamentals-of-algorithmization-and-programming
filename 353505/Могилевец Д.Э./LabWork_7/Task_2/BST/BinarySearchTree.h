#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <QString>
#include <QVector>

class BST {
public:
    class Data {
    public:
        QString info;
        int key;
        Data* leftSon;
        Data* rightSon;

        Data(QString initInfo, int initKey){
            info = initInfo;
            key = initKey;
            leftSon = nullptr;
            rightSon = nullptr;
        }
    };
private:
    void insertInTree(int key, QString info, Data* &tree) {
        if (tree == nullptr) tree = new Data(info, key);
        else if (key <= tree->key) insertInTree(key, info, tree->leftSon);
        else insertInTree(key, info, tree->rightSon);
    }

    QString findInTree(int key, Data* tree) {
        if (tree == nullptr) return "";
        if (tree->key == key) return tree->info;
        if (key > tree->key) return findInTree(key, tree->rightSon);
        else return findInTree(key, tree->leftSon);
    }

    void removeFromTree(int key, Data* tree, Data*& parent, int side) {
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
            }

            else if (tree->leftSon == nullptr) {
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
            }

            else {
                Data* successor = findMin(tree->rightSon);
                tree->key = successor->key;
                tree->info = successor->info;
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

    int calcLeavesOfTree(Data* tree) {
        if (tree == nullptr) return 1;
        return calcLeavesOfTree(tree->leftSon) + calcLeavesOfTree(tree->rightSon);
    }

    void preOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        result.push_back(QString::number(node->key) + " " + node->info);
        preOrder(node->leftSon, result);
        preOrder(node->rightSon, result);
    }

    void inOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        inOrder(node->leftSon, result);
        result.push_back(QString::number(node->key) + " " + node->info);
        inOrder(node->rightSon, result);
    }

    void postOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        postOrder(node->leftSon, result);
        postOrder(node->rightSon, result);
        result.push_back(QString::number(node->key) + " " + node->info);
    }
public:
    Data* root = nullptr;

    BST() {}

    BST(QVector<QPair<int, QString>> info) {
        for (QPair<int, QString> el : info)
            insert(el.first, el.second);
    }

    void insert(int key, QString info) {
        insertInTree(key, info, root);
    }
    QString find(int key) {
        return findInTree(key, root);
    }
    void remove(int key) {
        Data* a = nullptr;
        removeFromTree(key, root, a, 1);
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

    int calcLeaves() {
        return calcLeavesOfTree(root);
    }
};

#endif // BINARYSEARCHTREE_H
