#ifndef L7_T2_AVLTREE_H
#define L7_T2_AVLTREE_H

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <QDebug>
#include "Node.h"

class AVLTree {
private:

public:
    static void preorderWalk(Node *node);

    static void postorderWalk(Node *node);

    /*static Node *findParent(Node *node, longl key) {
        if (node == nullptr)
            return nullptr;

        Node *newNode = new Node;
        newNode->right = node->right;
        newNode->left = node->left;
        newNode->value = node->value;

        if (node->left != nullptr) {
            if (node->left->value == key) {
                return node;
            } else
                node = findParent(node->left->left, key);

            if (node != nullptr)
                return node;
        }

        if (newNode->right != nullptr) {
            if (newNode->right->value == key) {
                return newNode;
            } else
                newNode = findParent(newNode->right, key);

            return newNode;
        }
    }*/

    static Node* insert(Node *node, longl key);

    static Node *createAVLTree(std::map<longl, std::string> database);

    static bool contains(Node *node, longl key);

    static Node *deleteNode(Node *node, longl key);

    static int height(Node* node);

    static int getBalance(Node* node);

    static Node* rotateRight(Node* y);

    static Node* rotateLeft(Node* x);

    static void increaseOrder(Node* node, std::vector<int> &keys);

    //static void calculate

};

#endif //L7_T2_AVLTREE_H
