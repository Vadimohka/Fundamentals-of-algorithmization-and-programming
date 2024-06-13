//
// Created by shosh on 5/27/24.
//

//But why? It is superior to BST

#include "Node.h"

int Node::getHeight(Node *node) {
    return node ? node->height : 0;
}

int Node::balanceFactor(Node *node) {
    return getHeight(node->right) - getHeight(node->left);
}

void Node::fixHeight(Node *node) {
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);
    node->height = ((left_height > right_height ? left_height : right_height) + 1);
}

Node *Node::rotateLeft(Node *node) {
    Node *new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    fixHeight(node);
    fixHeight(new_root);
    return new_root;
}

Node *Node::rotateRight(Node *node) {
    Node *new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    fixHeight(new_root);
    fixHeight(node);
    return new_root;
}

Node *Node::bigRotateLeft(Node *node) {
    rotateRight(node->right);
    rotateLeft(node);
    return nullptr;
}

Node *Node::bigRotateRight(Node *node) {
    rotateLeft(node->left);
    rotateRight(node);
    return node->right->left;
}

Node *Node::search(Node* root, int k) {
    if (root == nullptr || k == root->key) {
        return root;
    }
    if (k < root->key) {
       return search(root->left, k);
    } else {
        return search(root->right, k);
    }
}

Node* Node::insert(Node *node, int k) {
    if (node == nullptr) {
        return new Node(k);
    }
    else if (k < node->key) {
        node->left = insert(node->left, k);
    } else if (k > node->key) {
        node->right = insert(node->right, k);
    } else {
        return node;
    }
    fixHeight(node);
    return rebalance(node);
}

Node* Node::rebalance(Node *root) {
    if (balanceFactor(root) == 2) {
        if (balanceFactor(root->right) < 0) {
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    }
    if (balanceFactor(root) == -2) {
        if (balanceFactor(root->left) > 0) {
            root->left = rotateLeft(root->left);
        }
        return rotateRight(root);
    }
    return root;
}

Node* Node::pop(Node *root,int k) {
    if (root == nullptr) {
        return root;
    }
    if (k < root->key) {
        root->left = pop(root->left, k);
    } else if (k > root->key) {
        root->right = pop(root->right, k);
    } else {
        Node *left_tree = root->left;
        Node *right_tree = root->right;
        delete root;
        if (right_tree == nullptr) {
            return left_tree;
        }
        Node *replacement = findMinimum(right_tree);
        replacement->right = removeMinimum(right_tree);
        replacement->left = left_tree;
        fixHeight(replacement);
        return rebalance(replacement);
    }
    fixHeight(root);
    return rebalance(root);
}

Node *Node::findMinimum(Node *root) {
    return root->left ? findMinimum(root->left) : root;
}

Node *Node::findMaximum(Node *root) {
    return root->right ? findMaximum(root->right) : root;
}

Node *Node::removeMinimum(Node *root) {
    if (root->left == nullptr) {
        return root->right;
    }
    root->left = removeMinimum(root->left);
    fixHeight(root);
    return rebalance(root);
}

Node *Node::removeMaximum(Node *root) {
    if (root->right == nullptr) {
        return root->left;
    }
    root->right = removeMaximum(root->right);
    fixHeight(root);
    rebalance(root);
    return root;
}

void Node::inorderTraverse(Node *root) {
    if (root != nullptr) {
        inorderTraverse(root->left);
        qDebug() << root->key;
        inorderTraverse(root->right);
    }
}

void Node::preorderTraverse(Node *root) {
    if (root != nullptr) {
        qDebug() << root->key;
        this->nodes_vector.push_back(root->key);
        if (root->left != nullptr) {
            preorderTraverse(root->left);
        }
        if (root->right != nullptr) {
            preorderTraverse(root->right);
        }
    }
}

void Node::postorderTraverse(Node *root) {
    if (root != nullptr) {
        if (root->left != nullptr) {
            preorderTraverse(root->left);
        }
        if (root->right != nullptr) {
            preorderTraverse(root->right);
        }
        qDebug() << root->key;
    }
}

int Node::countOfNodes(Node *root) {
    int count = 0;
    if (root == nullptr) {
        return 0;
    }
    int left_count = countOfNodes(root->left->left);
    int right_count = countOfNodes(root->left->right);
    return left_count + right_count + 1;
}

void Node::restoreOnTraverse(Node *root) {
    if (root != nullptr) {
        qDebug() << root->key;
        if (root->left != nullptr) {
            restoreOnTraverse(root->left);
        }
        if (root->right != nullptr) {
            restoreOnTraverse(root->right);
        }
    }}
