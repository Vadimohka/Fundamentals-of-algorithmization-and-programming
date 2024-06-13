#ifndef TREENODE_H
#define TREENODE_H

#include <QString>

struct TreeNode
{
    int key;
    QString str;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int, QString);
};

#endif // TREENODE_H
