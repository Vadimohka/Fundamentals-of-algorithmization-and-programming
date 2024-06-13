#ifndef BSTNODE_H
#define BSTNODE_H

#include <QString>

class BSTNode {
public:
    QString data;
    int key;
    BSTNode* left;
    BSTNode* right;

    BSTNode(QString data, int key);
};

#endif // BSTNODE_H
