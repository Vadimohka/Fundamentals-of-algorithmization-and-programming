#ifndef TREE_H
#define TREE_H

#include <QVector>
#include <QPair>
#include "treenode.h"

class Tree {
protected:
    TreeNode* root;

    TreeNode* insertUtil(TreeNode* node, QPair<int, QString> pair);
    TreeNode* deleteUtil(TreeNode *node, int key);
    TreeNode* findMin(TreeNode* node);
    TreeNode* findNode(TreeNode* node, int key);
    void destroyTree(TreeNode* node, int key);
    void preOrderToVec(TreeNode* node, QVector<QPair<int, QString>>& vec);
    void postOrderToVec(TreeNode* node, QVector<QPair<int, QString>> &vec);
    void inOrderToVec(TreeNode* node, QVector<QPair<int, QString>>& vec);
    TreeNode* buildBalancedTree(QVector<QPair<int, QString>>& sortedPairs, int start, int end);

public:
    Tree();
    TreeNode* getRoot();
    void buildTreeFromVector(QVector<QPair<int, QString>> a);
    TreeNode* insert(QPair<int, QString> pair);
    int search(int);
    void remove(int);
    QVector<QPair<int, QString>> preOrderToVec();
    QVector<QPair<int, QString>> postOrderToVec();
    QVector<QPair<int, QString>> inOrderToVec();
    ~Tree();
    QString searchStringByKey(int);
    void balanceTree();
};

#endif // TREE_H
