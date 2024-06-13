#ifndef BST_H
#define BST_H

#include <iostream>
#include <QString>
#include <vector>
#include <algorithm>
#include <QTextEdit>

struct Data {
    QString string;
    int key;
};

struct Node {
    Data data;
    Node* left;
    Node* right;
    int height;

};
class BST {
public:

    Node* root = nullptr;
    Node* add(Node* root, Data x);
    Node* remove(Node* root, int key);

    Node* findLeft(Node* node);
    Node* search(Node* root, int key);
    void printInorder(Node* root,QTextEdit& textEdit);
    void printPreorder (Node *root,QTextEdit& textEdit);
    void printPostorder(Node* root,QTextEdit& textEdit);
    void clear(Node* root);
    Node* balance(Node* node);
    int getBalance(Node* node);
    int getHeight(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* findAncestor(Node* root, int key1, int key2);
    Node* insertAt(Node* root, Data data, std::vector<int> path);
    Node* removeBrunch(Node* root, int key);
    void removeSubtree(Node*& root, Node* subtree);
    void insertSubtree(Node *&root, Node* subtree);

};
#endif // BST_H
