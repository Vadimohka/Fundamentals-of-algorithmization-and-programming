#ifndef TREE_H
#define TREE_H

#include <QString>
#include <iostream>

struct Node {
    QString data;
    int key;
    Node* left;
    Node* right;

    Node(QString d, int k) : data(d), key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(QString data, int key);
    void balance();
    Node* search(int key);
    void remove(int key);
    QString getPreOrder();
    QString getInOrder();
    QString getPostOrder();
    QString countLeavesPerLevel();
    Node* getRoot();

private:
    Node* root;

    Node* insert(Node* node, QString data, int key);
    Node* search(Node* node, int key);
    Node* remove(Node* node, int key, bool& success);
    Node* findMin(Node* node);
    void destroyTree(Node* node);
    QString getPreOrder(Node* node);
    QString getInOrder(Node* node);
    QString getPostOrder(Node* node);
    void countLeavesPerLevel(Node* node, int level, int* leaves, QString& result);

    Node* balance(Node* node);
    std::vector<Node*> storeInOrder(Node* node);
    Node* buildBalancedTree(std::vector<Node*>& nodes, int start, int end);
};

#endif // TREE_H
