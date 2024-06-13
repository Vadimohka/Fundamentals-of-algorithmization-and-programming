#ifndef DERIVEDBST_H
#define DERIVEDBST_H

#include "bst.h"

class DerivedBST : public BST {
public:
    DerivedBST();
    ~DerivedBST();
    void balance();
    int countStartingWith(QChar letter) const;

private:
    Node* buildBalancedTree(QVector<QPair<int, QString>>& nodes, int start, int end);
    void storeInOrder(Node* node, QVector<QPair<int, QString>>& nodes);
    int countStartingWith(Node* node, QChar letter) const;
};

#endif // DERIVEDBST_H
