//
// Created by zgdarya on 5/28/24.
//

#include "AVLTree.h"

void AVLTree::preorderWalk(Node *node) {
    if (node) {
        preorderWalk(node->left);
        qDebug() << node->value;
        preorderWalk(node->right);
    }
    return;
}

void AVLTree::postorderWalk(Node *node){
    if (node) {
        postorderWalk(node->right);
        qDebug() << node->value;
        postorderWalk(node->left);
    }
    return;
}

Node* AVLTree::insert(Node *node, long key) {
    /*if (node == nullptr)
        return new Node(key);

    if (node->value == key)
        return node;

    if (key < node->value) {
        if (node->left == nullptr) {
            node->left = new Node;
            node->left->value = key;
        } else {
            node->right = insert(node->left, key);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node;
            node->right->value = key;
        } else {
            node->right = insert(node->right, key);
        }
    }

    if (node->left != nullptr && node->right != nullptr)
        node->height = 1 + std::max(node->left->height, node->right->height);
    else if (node->left != nullptr && node->right == nullptr)
        node->height = 1 + node->left->height;
    else if (node->left == nullptr && node->right != nullptr)
        node->height = 1 + node->right->height;
    else
        node->height = 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->value)
        return rightRotate(node);

    if (balance < -1 && key > node->right->value)
        return leftRotate(node);

    if (balance > 1 && key > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;*/

    if (node == nullptr) return new Node(key);

    if (key < node->value)
        node->left = insert(node->left, key);
    else if (key > node->value)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->value)
        return rotateRight(node);

    if (balance < -1 && key > node->right->value)
        return rotateLeft(node);

    if (balance > 1 && key > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node *AVLTree::createAVLTree(std::map<long, std::string> database) {
    std::vector<longl> numbers;
    for (auto name: database) {
       numbers.push_back(name.first);
    }

    Node *root= new Node(numbers[0]);
    root->left = nullptr;
    root->right = nullptr;
    root->value = numbers[0];

    for (longl i = 1; i < numbers.size(); ++i) {
       root = insert(root, numbers[i]);
    }

    return root;
}

bool AVLTree::contains(Node *node, long key) {
    if (node == nullptr)
        return false;

    if (node->value == key)
        return true;
    if (key < node->value)
        return contains(node->left, key);
    else
        return contains(node->right, key);
}

Node *AVLTree::deleteNode(Node *node, long key) {
    if (node == nullptr)
        return node;

    if (node->left != nullptr && key < node->value) {
        if (key != node->left->value)
            deleteNode(node->left, key);
        else {
            if (node->left->right != nullptr) {
                if (node->left->left == nullptr) {
                    node->left = node->left->right;
                } else if (node->left->left != nullptr) {
                    Node *leftNode = node->left->left;
                    Node *parent = nullptr;
                    if (leftNode->right == nullptr)
                        parent = node->left;
                    while (leftNode->right != nullptr) {
                        if (leftNode->right->right == nullptr)
                            parent = leftNode;
                        leftNode = leftNode->right;
                    }
                    node->left->value = leftNode->value;
                    parent->left = nullptr;
                }
            } else {
                node->left = node->left->left != nullptr ? node->left->left : nullptr;
            }
        }
        return node;
    }

    if (node->right != nullptr && key > node->value) {
        if (key != node->right->value)
            deleteNode(node->right, key);
        else {
            if (node->right->right != nullptr) {
                if (node->right->left == nullptr) {
                    node->right = node->right->right;
                } else if (node->right->left != nullptr) {
                    Node *leftNode = node->right->left;
                    Node *parent = nullptr;
                    if (leftNode->right == nullptr)
                        parent = node->right;
                    while (leftNode->right != nullptr) {
                        if (leftNode->right->right == nullptr)
                            parent = leftNode;
                        leftNode = leftNode->right;
                    }
                    node->right->value = leftNode->value;
                    parent->left = nullptr;
                }
            } else {
                node->right = node->right->left != nullptr ? node->right->left : nullptr;
            }
        }

        return node;
    }
}

int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

void AVLTree::increaseOrder(Node* node, std::vector<int> &keys) {
    if (node) {
        increaseOrder(node->left, keys);
        keys.push_back(node->value);
        increaseOrder(node->right, keys);
    }
}
