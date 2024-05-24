#ifndef TREENODE_H
#define TREENODE_H

#include <QString>

class TreeNode {
public:
    TreeNode(int key, QString data);
    TreeNode* left_child;
    TreeNode* right_child;
    int key;
    QString data;
};

#endif // TREENODE_H
