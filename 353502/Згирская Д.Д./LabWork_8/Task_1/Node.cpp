//
// Created by zgdarya on 6/5/24.
//

#include "Node.h"

Node::Node() {
    left = nullptr;
    right = nullptr;
    height = 1;
}

Node::Node(longl it) {
    this->left = nullptr;
    this->right = nullptr;
    this->value = it;
    height = 1;
}