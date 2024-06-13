#include "deletingbranchbst.h"

void deletingBranchBST::removeSubtree(int key) {
    BSTNode* parent = nullptr;
    BSTNode* node = root;
    while (node != nullptr && node->key != key) {
        parent = node;
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (node == nullptr) {
        return;
    }

    deleteSubtree(node);

    if (parent == nullptr) {
        root = nullptr;
    } else if (parent->left == node) {
        parent->left = nullptr;
    } else {
        parent->right = nullptr;
    }
}

void deletingBranchBST::deleteSubtree(BSTNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}
