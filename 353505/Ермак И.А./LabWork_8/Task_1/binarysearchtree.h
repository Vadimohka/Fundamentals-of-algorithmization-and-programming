#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <QObject>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

class BinarySearchTree : public QObject {
    Q_OBJECT

public:
    explicit BinarySearchTree(QObject* parent = nullptr);
    ~BinarySearchTree();
    Node* findLowestCommonAncestorRecursive(Node* node, int value1, int value2);
    void deleteBranch(int parentValue, int branchValue);
    Node* findLowestCommonAncestor(int value1, int value2);
    void insertBranch(int parentValue, int branchValue);
    void deleteSubtree(int value);
    void insertSubtree(Node* subtreeRoot);
    Node* mergeTrees(Node* tree1, Node* tree2);
    void add(int value);
    void remove(int value);
    Node* find(int value);
    void traverse();

signals:
    void traversalCompleted(QString traversal);

private:
    Node* root;

    Node* addRecursive(Node* node, int value);
    Node* removeRecursive(Node* node, int value);
    Node* minValueNode(Node* node);
    Node* findRecursive(Node* node, int value);
    void traverseRecursive(Node* node, QString& traversal);
};

#endif // BINARYSEARCHTREE_H
