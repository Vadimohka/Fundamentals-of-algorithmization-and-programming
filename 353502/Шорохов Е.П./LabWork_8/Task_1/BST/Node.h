//
// Created by shosh on 5/27/24.
//

#ifndef LABWORK_7_NODE_H
#define LABWORK_7_NODE_H




//Why do you deny the trees their purpose

#include <cstdint>
#include "QDebug"

class Node : public QObject {
    Q_OBJECT
public:
    int key;
    int height = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    QVector<int> nodes_vector;
    static int getHeight(Node *node);

    static int balanceFactor(Node *node);

    static void fixHeight(Node *node);

    Node *rotateLeft(Node *node);

    Node *rotateRight(Node *node);

    Node* rebalance(Node *root);

    Node *bigRotateLeft(Node *node);

    Node *bigRotateRight(Node *node);

    Node *search(Node *root, int key);

    Node *findMinimum(Node *root);

    Node *findMaximum(Node *root);

    Node *removeMinimum(Node *root);

    Node *removeMaximum(Node *root);

    Node *insert(Node *node, int key);

    Node* pop(Node *root, int key);


    void inorderTraverse(Node *root);

    void preorderTraverse(Node *root);

    void postorderTraverse(Node *root);


    void restoreOnTraverse(Node *root);

    int countOfNodes(Node *root);

    explicit Node(int k) {
        key = k;
        height = 0;
        left = nullptr;
        right = nullptr;
    };

};


#endif //LABWORK_7_NODE_H
