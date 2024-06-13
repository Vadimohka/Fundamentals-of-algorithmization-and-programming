//
// Created by shosh on 5/27/24.
//

#ifndef LABWORK_7_NODE_H
#define LABWORK_7_NODE_H


#include <cstdint>
#include "QDebug"

enum Color {RED, BLACK};

class Node : public QObject {
Q_OBJECT
public:
    int key;
    Node *parent = this;
    Node *left = nullptr;
    Node *right = nullptr;
    Color color = BLACK;

    Node *rotateLeft(Node *node);

    Node *rotateRight(Node *node);

    Node *bigRotateLeft(Node *node);

    Node *bigRotateRight(Node *node);

    Node *search(Node *root, int key);

    Node *findMinimum(Node *root);

    Node *findMaximum(Node *root);

    Node *insert(Node *node, int key);

    Node *fixInsertion(Node *root);

    Node *pop(Node *root, int key);

    Node *fixDeleting(Node *node);

    void inorderTraverse(Node *root);

    void preorderTraverse(Node *root);

    void postorderTraverse(Node *root);


    explicit Node(int key, Color node_color) {
        this->key = key;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        this->color = node_color;
    };

};


#endif //LABWORK_7_NODE_H
