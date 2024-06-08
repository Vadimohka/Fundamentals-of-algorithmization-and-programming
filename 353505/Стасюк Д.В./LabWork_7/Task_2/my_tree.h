#ifndef MY_TREE_H
#define MY_TREE_H

#include "tree_node.h"
#include <QVector>
#include <QPair>

class my_tree
{
public:
    my_tree();
    ~my_tree();
    tree_node* getRoot();
    void insert(QPair<int, QString> pair);
    int search(int key);
    QString searchStringByKey(int key);
    void remove(int key);
    QVector<QPair<int, QString>> getPreOrder();
    QVector<QPair<int, QString>> getPostOrder();
    QVector<QPair<int, QString>> getInOrder();
    void buildTreeFromVector(QVector<QPair<int, QString>> data);
    void balanceTree();

    void countLeavesPerLevel(tree_node* node, QVector<int>& leafCounts, int level);
    QVector<int> getLeavesPerLevel();

private:
    tree_node* root;
    tree_node* insertNode(tree_node* node, QPair<int, QString> pair);
    tree_node* deleteNode(tree_node* node, int key);
    tree_node* findMinimum(tree_node* node);
    tree_node* findNodeByKey(tree_node* node, int key);
    void destroySubTree(tree_node* node);
    void preOrderTraversal(tree_node* node, QVector<QPair<int, QString>>& vec);
    void postOrderTraversal(tree_node* node, QVector<QPair<int, QString>>& vec);
    void inOrderTraversal(tree_node* node, QVector<QPair<int, QString>>& vec);
    tree_node* buildBalancedTreeHelper(QVector<QPair<int, QString>>& sortedPairs, int start, int end);
};

#endif // MY_TREE_H
