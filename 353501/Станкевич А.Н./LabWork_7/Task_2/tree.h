#ifndef TREE_H
#define TREE_H

#include <QVector>
#include <QPair>
#include "treenode.h"

class Tree {
public:
    TreeNode* root;
    TreeNode* insertUtil(TreeNode*, QPair<int, QString>);
    TreeNode* deleteUtil(TreeNode*, int);
    TreeNode* findMin(TreeNode*);
    TreeNode* findNode(TreeNode*, int);

    TreeNode* buildBalancedTree(QVector<QPair<int, QString>>&, int, int);
    Tree();
    TreeNode* getRoot();
    void buildTreeFromVector(QVector<QPair<int, QString>>);
    TreeNode * insert(QPair<int, QString>);
    int search(int);
    void remove(int);

    ~Tree();
    void destroyTree(TreeNode*);
    void preOrderToVec(TreeNode*, QVector<QPair<int, QString>> &);
    void postOrderToVec(TreeNode*, QVector<QPair<int, QString>> &);
    void inOrderToVec(TreeNode*, QVector<QPair<int, QString>> &);
    QString searchStringByKey(int);
    void balanceTree();
    QVector<QPair<int, QString>> preOrderToVec();
    QVector<QPair<int, QString>> postOrderToVec();
    QVector<QPair<int, QString>> inOrderToVec();

};

class Tree2 : public Tree{
public:
    int nodesWith2Children();
};

#endif // TREE_H
