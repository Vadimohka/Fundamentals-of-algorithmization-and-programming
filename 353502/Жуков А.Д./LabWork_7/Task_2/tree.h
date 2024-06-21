#ifndef TREE_H
#define TREE_H

#include <QVector>
#include <QPair>
#include "treenode.h"

class Tree {
protected:
    TreeNode* root;

    TreeNode* insertUtil(TreeNode*, QPair<int, QString>);

    TreeNode* deleteUtil(TreeNode*, int);

    TreeNode* findMin(TreeNode*);

    TreeNode* findNode(TreeNode*, int);

    void destroyTree(TreeNode*);

    void preOrderToVec(TreeNode*, QVector<QPair<int, QString>> &);

    void postOrderToVec(TreeNode*, QVector<QPair<int, QString>> &);

    void inOrderToVec(TreeNode*, QVector<QPair<int, QString>> &);

    TreeNode* buildBalancedTree(QVector<QPair<int, QString>>&, int, int);

public:
    Tree();

    TreeNode* getRoot();

    void buildTreeFromVector(QVector<QPair<int, QString>>);

    TreeNode * insert(QPair<int, QString>);

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
