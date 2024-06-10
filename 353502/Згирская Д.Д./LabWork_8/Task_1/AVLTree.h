#ifndef L8_T1_AVLTREE_H
#define L8_T1_AVLTREE_H


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
    static void preorderTraverse(Node *node);

    static void postorderTraverse(Node *node);

    static Node *findParent(Node *node, longl key);

    static Node* findCommonParent(Node *node, longl key1, longl key2);

    static Node* add(Node *node, longl key);

    static Node* addNode(Node *node, Node* keyNode);

    static Node *createAVLTree(std::map<longl, std::string> database);

    static bool find(Node *node, longl key);

    static Node *remove(Node *node, longl key);

    static int height(Node* node);

    static int getBalance(Node* node);

    static Node* rotateRight(Node* y);

    static Node* rotateLeft(Node* x);

    static void increaseOrder(Node* node, std::vector<int> &keys);

    //static void calculate

};

#endif //L7_T2_AVLTREE_H
