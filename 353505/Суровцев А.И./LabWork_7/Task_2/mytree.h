#ifndef MYTREE_H
#define MYTREE_H

#include <QVector>
#include <QPair>
#include "treenode.h"

class MyTree {
public:
    MyTree();
    ~MyTree();
    TreeNode* getRoot();
    void insert(QPair<int, QString> pair);
    int search(int key);
    QString searchStringByKey(int key);
    void remove(int key);
    QVector<QPair<int, QString>> getPreOrder();
    QVector<QPair<int, QString>> getPostOrder();
    QVector<QPair<int, QString>> getInOrder();
    void buildTreeFromVector(QVector<QPair<int, QString>> data);
    void balanceTree();

    void countLeavesPerLevel(TreeNode* node, QVector<int>& leafCounts, int level);
    QVector<int> getLeavesPerLevel();

private:
    TreeNode* root;
    TreeNode* insertNode(TreeNode* node, QPair<int, QString> pair);
    TreeNode* deleteNode(TreeNode* node, int key);
    TreeNode* findMinimum(TreeNode* node);
    TreeNode* findNodeByKey(TreeNode* node, int key);
    void destroySubTree(TreeNode* node);
    void preOrderTraversal(TreeNode* node, QVector<QPair<int, QString>>& vec);
    void postOrderTraversal(TreeNode* node, QVector<QPair<int, QString>>& vec);
    void inOrderTraversal(TreeNode* node, QVector<QPair<int, QString>>& vec);
    TreeNode* buildBalancedTreeHelper(QVector<QPair<int, QString>>& sortedPairs, int start, int end);
};

#endif // MYTREE_H
