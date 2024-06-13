#ifndef TREENODE_H
#define TREENODE_H

#include <QString>

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int key;
    QString str;


    TreeNode(int, QString);
};

#endif // TREENODE_H
