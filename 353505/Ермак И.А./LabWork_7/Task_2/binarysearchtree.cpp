#include "binarysearchtree.h"
#include <vector>
#include <algorithm>


BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::insert(QString data, int key) {
    root = insert(root, data, key);
}

Node* BinarySearchTree::insert(Node* node, QString data, int key) {
    if (node == nullptr) {
        return new Node(data, key);
    }
    if (key < node->key) {
        node->left = insert(node->left, data, key);
    } else {
        node->right = insert(node->right, data, key);
    }
    return node;
}

Node* BinarySearchTree::search(int key) {
    return search(root, key);
}

Node* BinarySearchTree::search(Node* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

void BinarySearchTree::remove(int key) {
    bool success = false;
    root = remove(root, key, success);
}

Node* BinarySearchTree::remove(Node* node, int key, bool& success) {
    if (node == nullptr) return node;

    if (key < node->key) {
        node->left = remove(node->left, key, success);
    } else if (key > node->key) {
        node->right = remove(node->right, key, success);
    } else {
        success = true;
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->data = temp->data;
        node->right = remove(node->right, temp->key, success);
    }
    return node;
}

Node* BinarySearchTree::findMin(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

void BinarySearchTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

QString BinarySearchTree::getPreOrder() {
    return getPreOrder(root);
}

QString BinarySearchTree::getPreOrder(Node* node) {
    if (node == nullptr) {
        return "";
    }
    return node->data + " " + getPreOrder(node->left) + getPreOrder(node->right);
}

QString BinarySearchTree::getInOrder() {
    return getInOrder(root);
}

QString BinarySearchTree::getInOrder(Node* node) {
    if (node == nullptr) {
        return "";
    }
    return getInOrder(node->left) + node->data + " " + getInOrder(node->right);
}

QString BinarySearchTree::getPostOrder() {
    return getPostOrder(root);
}

QString BinarySearchTree::getPostOrder(Node* node) {
    if (node == nullptr) {
        return "";
    }
    return getPostOrder(node->left) + getPostOrder(node->right) + node->data + " ";
}

QString BinarySearchTree::countLeavesPerLevel() {
    const int height = 10;
    int leaves[height] = {0};
    QString result;

    countLeavesPerLevel(root, 0, leaves, result);

    return result;
}

void BinarySearchTree::countLeavesPerLevel(Node* node, int level, int* leaves, QString& result) {
    if (node == nullptr) return;

    if (node->left == nullptr && node->right == nullptr) {
        leaves[level]++;
    }
    countLeavesPerLevel(node->left, level + 1, leaves, result);
    countLeavesPerLevel(node->right, level + 1, leaves, result);

    if (level == 0) {
        for (int i = 0; i < 10; ++i) {
            if (leaves[i] != 0) {
                result += "Level " + QString::number(i) + ": " + QString::number(leaves[i]) + " leaves\n";
            }
        }
    }
}

void BinarySearchTree::balance() {
    std::vector<Node*> nodes = storeInOrder(root);
    root = buildBalancedTree(nodes, 0, nodes.size() - 1);
}

std::vector<Node*> BinarySearchTree::storeInOrder(Node* node) {
    std::vector<Node*> nodes;
    if (node != nullptr) {
        std::vector<Node*> leftNodes = storeInOrder(node->left);
        nodes.insert(nodes.end(), leftNodes.begin(), leftNodes.end());
        nodes.push_back(node);
        std::vector<Node*> rightNodes = storeInOrder(node->right);
        nodes.insert(nodes.end(), rightNodes.begin(), rightNodes.end());
    }
    return nodes;
}

Node* BinarySearchTree::buildBalancedTree(std::vector<Node*>& nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* node = nodes[mid];

    node->left = buildBalancedTree(nodes, start, mid - 1);
    node->right = buildBalancedTree(nodes, mid + 1, end);

    return node;
}

Node* BinarySearchTree::getRoot() {
    return root;
}
