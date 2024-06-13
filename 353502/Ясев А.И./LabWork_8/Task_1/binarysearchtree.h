#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "node.h"
#include <QVector>

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int key, const QString& value);
    void remove(int key);
    QString search(int key);
    QVector<QPair<int, QString>> traverseInOrder();
    QVector<QPair<int, QString>> traversePreOrder();
    QVector<QPair<int, QString>> traversePostOrder();
    void balance();

    Node* getRoot();

    QVector<QPair<int, QString>> traverseByValue();

private:
    Node* root;

    Node* insert(Node* node, int key, const QString& value);
    Node* remove(Node* node, int key);
    Node* search(Node* node, int key);
    void traverseInOrder(Node* node, QVector<QPair<int, QString>>& result);
    void traversePreOrder(Node* node, QVector<QPair<int, QString>>& result);
    void traversePostOrder(Node* node, QVector<QPair<int, QString>>& result);
    Node* balance(const QVector<QPair<int, QString>>& nodes, int start, int end);
    void clear(Node* node);

    void traverseByValue(Node* node, QVector<QPair<int, QString>>& result);
};

#endif // BINARYSEARCHTREE_H
