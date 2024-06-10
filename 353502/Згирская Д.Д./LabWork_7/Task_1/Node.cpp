//
// Created by zgdarya on 5/30/24.
//

#include "Node.h"

Node::Node(int value) {
    this->value = value;
    next = nullptr;
    previous = nullptr;
}

Node::Node() {
    next = nullptr;
    previous = nullptr;
}
