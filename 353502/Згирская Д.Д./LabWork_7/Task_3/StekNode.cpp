//
// Created by zgdarya on 5/30/24.
//

#include "StekNode.h"

StekNode::StekNode() {
    next = nullptr;
    previous = nullptr;
}

StekNode::StekNode(int value) {
    this->value = value;
    next = nullptr;
    previous = nullptr;
}
