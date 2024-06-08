

// binarytree.h
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    void buildTreeFromArray(const QStringList& data, const QList<int>& keys);
    void balanceTree();
    void addNode(const QString& info, int key);
    Node* findNode(int key);
    void removeNode(int key);
    void printInOrder(QStringList& result);
    void printPreOrder(QStringList& result);
    void printPostOrder(QStringList& result);
    void swapMaxMinKeys();

private:
    Node* root;
    void deleteTree(Node* node);
    void addNodePrivate(Node*& node, const QString& info, int key);
    Node* removeNodePrivate(Node* node, int key);
    void printInOrderPrivate(Node* node, QStringList& result);
    void printPreOrderPrivate(Node* node, QStringList& result);
    void printPostOrderPrivate(Node* node, QStringList& result);
    Node* findMinNode(Node* node);
    Node* findMaxNode(Node* node);
};

#endif // BINARYTREE_H
