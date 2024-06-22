#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"
#include <QTreeView>
#include <QStandardItemModel>
#include <QString>
#include <QDebug>

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int key, const QString& data);
    bool search(int key, QString& data);
    void remove(int key);
    int countNodesInLeftSubtree();
    int countNodesInLeftSubtree(Node *node);

    void balance(); // Placeholder for balance method

    void printInOrder();
    void printPreOrder();
    void printPostOrder();

    QStandardItemModel* getTreeModel();

private:
    Node* root;

    void insert(Node* &node, int key, const QString& data);
    bool search(Node* node, int key, QString& data);
    Node* remove(Node* node, int key);
    Node* minValueNode(Node* node);
    void balance(Node* &node); // Placeholder for balance method

    void printInOrder(Node* node);
    void printPreOrder(Node* node);
    void printPostOrder(Node* node);
    void AVL_Tree::balanceTreeHelper(Node *&node)
    {
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


    QStandardItemModel* model;
    void updateModel(Node* node, QStandardItem* parentItem);
};

#endif // BINARYSEARCHTREE_H
