#ifndef TREENODE_H
#define TREENODE_H

#include <QString>

class TreeNode {
public:
    int key;
    QString str;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int, QString);
};

#endif // TREENODE_H
