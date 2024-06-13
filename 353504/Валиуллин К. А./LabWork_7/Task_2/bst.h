#ifndef BST_H
#define BST_H

#include "bstnode.h"
#include <QString>
#include <QList>

class BST {
public:
    BST();
    void insert(QString data, int key);
    bool contains(int key) const;
    QString search(int key);
    void remove(int key);
    void balance();
    QList<QString> inOrder();
    QList<QString> preOrder();
    QList<QString> postOrder();
    BSTNode* getRoot() const;

protected:
    BSTNode* root;
    BSTNode* insertRec(BSTNode* node, const QString& data, int key);
    bool containsRec(BSTNode* node, int key) const;

    void inOrderTraversal(BSTNode* node, QList<QString>& result);
    void preOrderTraversal(BSTNode* node, QList<QString>& result);
    void postOrderTraversal(BSTNode* node, QList<QString>& result);
    BSTNode* insert(BSTNode* node, QString data, int key);
    BSTNode* search(BSTNode* node, int key);
    BSTNode* remove(BSTNode* node, int key);
    BSTNode* findMin(BSTNode* node);
    BSTNode* balanceTree(QList<BSTNode*>& nodes, int start, int end);
    void storeBSTNodes(BSTNode* root, QList<BSTNode*>& nodes);
};

#endif // BST_H
