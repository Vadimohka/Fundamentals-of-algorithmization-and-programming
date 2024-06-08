#ifndef BINTREE_H
#define BINTREE_H

#include <QString>
#include <QVector>

class BinaryTree {
public:
    class Data {
    public:
        QString info;
        int key;
        Data* LeftChild;
        Data* RightChild;

        Data(QString initInfo, int initKey){
            info = initInfo;
            key = initKey;
            LeftChild = nullptr;
            RightChild = nullptr;
        }
    };
private:
    void insertInTree(int key, QString info, Data* &tree) {
        if (tree == nullptr) tree = new Data(info, key);
        else if (key <= tree->key) insertInTree(key, info, tree->LeftChild);
        else insertInTree(key, info, tree->RightChild);
    }

    QString findInTree(int key, Data* tree) {
        if (tree == nullptr) return "";
        if (tree->key == key) return tree->info;
        if (key > tree->key) return findInTree(key, tree->RightChild);
        else return findInTree(key, tree->LeftChild);
    }

    void removeFromTree(int key, Data* tree, Data*& parent, int side) {
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
            }

            else if (tree->LeftChild == nullptr) {
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
            }

            else {
                Data* successor = findMin(tree->RightChild);
                tree->key = successor->key;
                tree->info = successor->info;
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

    int calcLeavesOfTree(Data* tree) {
        if (tree == nullptr) return 1;
        return calcLeavesOfTree(tree->LeftChild) + calcLeavesOfTree(tree->RightChild);
    }

    void preOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        result.push_back(QString::number(node->key) + " " + node->info);
        preOrder(node->LeftChild, result);
        preOrder(node->RightChild, result);
    }

    void inOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        inOrder(node->LeftChild, result);
        result.push_back(QString::number(node->key) + " " + node->info);
        inOrder(node->RightChild, result);
    }

    void postOrder(Data* node, QVector<QString>& result) {
        if (node == nullptr) return;
        postOrder(node->LeftChild, result);
        postOrder(node->RightChild, result);
        result.push_back(QString::number(node->key) + " " + node->info);
    }
public:
    Data* root = nullptr;

    BinaryTree() {}

    BinaryTree(QVector<QPair<int, QString>> info) {
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

#endif // BINTREE_H
