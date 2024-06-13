#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data) {
       parent = left = right = nullptr;
       color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;

protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixInsertRBTree(Node *&, Node *&);
    void fixDeleteRBTree(Node *&, Node *&);
    void inorderHelper(Node *node);
    Node* BSTInsert(Node* root, Node *pt);
    void deleteNodeHelper(Node *node, int key);
    bool isLeafNode(Node* node); // Add this line


public:
    RedBlackTree();
    void insertValue(int data);
    void deleteValue(int data);
    void inorder();
    Node* getRoot();
    Node* find(Node* root, int key) ;
};

#endif // REDBLACKTREE_H
