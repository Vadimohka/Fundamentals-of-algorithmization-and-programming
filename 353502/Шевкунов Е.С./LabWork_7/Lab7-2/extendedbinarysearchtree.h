#ifndef EXTENDED_BINARY_SEARCH_TREE_H
#define EXTENDED_BINARY_SEARCH_TREE_H

#include "binarysearchtree.h"

class ExtendedBinarySearchTree : public BinarySearchTree {
public:
    int countLeftSubtreeNodes() {
        if (!root || !root->left) return 0;
        return countNodesRec(root->left);
    }

private:
    int countNodesRec(Node* node) {
        if (!node) return 0;
        return 1 + countNodesRec(node->left) + countNodesRec(node->right);
    }
};

#endif // EXTENDED_BINARY_SEARCH_TREE_H
