#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "node.cpp"
#include <utility>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QLineEdit>


template <typename T, typename U>
class Tree
{
public:

    Node<T, U>* root;

    Tree();
    Tree(std::pair<T, U> *arr, std::size_t size);
    ~Tree();

    void add(Node<T, U> *&node, T key, U value);
    void add(T key, U value);
    void insertSubtree(Tree<T, U> *subTree);
    void removeSubtree(Node<T, U>*& subtreeRoot);
    void removeSubtree(Tree<T, U> *&subTree);

    void insertBranch(Node<T, U> *& node, Node<T, U> *branchNode, bool isLeftBranch);
    void insertBranch(Node<T, U> *branchNode, bool isLeftBranch);
    void insertBranch(Tree<T, U> *branch, bool isLeftBranch);

    void removeBranch(Node<T, U> *& node, Node<T, U> *branchNode, bool isLeftBranch);
    void removeBranch(Node<T, U> *branchNode, bool isLeftBranch);
    void removeBranch(Tree<T, U> *branch, bool isLeftBranch);

    void remove(Node<T, U> *&node, T key);
    void remove(T key);
    void remove(Node<T, U> *&node, T key, U value);
    Node<T, U>* find(Node<T, U>* node, T key);
    Node<T, U>* find(T key);

    Node<T, U>* getMax(Node<T, U> *&node);
    Node<T, U>* getMin(Node<T, U> *&node);

    void symmetricalTraverse();
    void reverseTraverse();

    void symmetricalTraverse(Node<T, U> *&node);
    void reverseTraverse(Node<T, U> *&node);
    void straightTraverseCopy(Node<T, U> *newNode);
    void reverseTraverseDelete(Node<T, U> *newNode);

    Node<T, U>* lowestCommonAncestor(Node<T, U>* u, Node<T, U>* v);
    T lowestCommonAncestor(T u, T v);
    int depth(Node<T, U> *&node);




    void fillTreeWidget(QTreeWidgetItem *&parent, Node<T, U> *node);

};

#endif // TREE_H
