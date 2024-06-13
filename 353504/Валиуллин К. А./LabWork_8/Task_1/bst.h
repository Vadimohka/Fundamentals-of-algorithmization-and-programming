#ifndef BST_H
#define BST_H

#include "node.h"
#include <QString>
#include <QVector>
#include <QDebug>

class BST {
private:
    Node* root;

    Node* add(Node* node, int value, QString& message);
    Node* remove(Node* node, int value, QString& message);
    Node* find(Node* node, int value);
    void traverse(Node* node, QVector<int>& elements);
    Node* findLCA(Node* node, int n1, int n2);

public:
    BST() : root(nullptr) {}

    void add(int value);
    void remove(int value);
    Node* find(int value);
    QVector<int> traverse();
    Node* findLCA(int n1, int n2);

    void insertSubtree(Node* subtree);
    void removeSubtree(Node* subtree);

    QString getMessageForAdd(int value);
    QString getMessageForRemove(int value);
    QString getMessageForInsertSubtree(Node* subtree);
    QString getMessageForRemoveSubtree(Node* subtree);

    void insertAtPosition(int parentValue, int value, bool asLeftChild);

    void insertBranch(Node* branch, int parentValue, bool asLeftChild);
    void removeBranch(int branchValue);
};

#endif // BST_H
