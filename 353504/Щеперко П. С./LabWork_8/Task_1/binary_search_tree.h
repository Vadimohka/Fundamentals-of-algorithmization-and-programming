#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <QTreeWidgetItem>
#include <QString>
#include "node.h"

class BinarySearchTree
{
public:

    Node* root;

    BinarySearchTree();
    BinarySearchTree(QPair <int, QString> *arr, qsizetype size);
    ~BinarySearchTree();

    void add(Node *&node, int key, QString value);
    void add(int key, QString value);
    void insertSubtree(BinarySearchTree *subTree);
    void removeSubtree(Node *&subtreeRoot);
    void removeSubtree(BinarySearchTree *&subTree);

    void insertBranch(Node *&node, Node *branchNode, bool isLeftBranch);
    void insertBranch(Node *branchNode, bool isLeftBranch);
    void insertBranch(BinarySearchTree *branch, bool isLeftBranch);

    void removeBranch(Node *&node, Node *branchNode, bool isLeftBranch);
    void removeBranch(Node *branchNode, bool isLeftBranch);
    void removeBranch(BinarySearchTree *branch, bool isLeftBranch);

    void remove(Node *&node, int key);
    void remove(int key);
    void remove(Node *&node, int key, QString value);
    Node *find(Node *node, int key);
    Node *find(int key);

    Node *getMax(Node *&node);
    Node *getMin(Node *&node);

    void symmetricalTraverse();
    void reverseTraverse();

    void reverseTraverse(Node *&node);
    void straightTraverseCopy(Node *newNode);
    void reverseTraverseDelete(Node *node);

    Node *lowestCommonAncestor(Node *u, Node *v);
    int lowestCommonAncestor(int u, int v);
    int depth(Node *&node);

    void fillTreeWidget(QTreeWidgetItem *&parent, Node *node);

private:
    void symmetricalTraverse(Node *&node);
};

#endif // BINARY_SEARCH_TREE_H
