#include "binarysearchtree.h"

#include <QDebug>

Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree(QObject* parent) : QObject(parent), root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    // Очистка памяти
}

void BinarySearchTree::add(int value) {
    root = addRecursive(root, value);
}

Node* BinarySearchTree::addRecursive(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = addRecursive(node->left, value);
    else if (value > node->data)
        node->right = addRecursive(node->right, value);

    return node;
}

void BinarySearchTree::remove(int value) {
    root = removeRecursive(root, value);
}

Node* BinarySearchTree::removeRecursive(Node* node, int value) {
    if (node == nullptr)
        return node;

    if (value < node->data)
        node->left = removeRecursive(node->left, value);
    else if (value > node->data)
        node->right = removeRecursive(node->right, value);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = removeRecursive(node->right, temp->data);
    }
    return node;
}

Node* BinarySearchTree::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* BinarySearchTree::find(int value) {
    return findRecursive(root, value);
}

Node* BinarySearchTree::findRecursive(Node* node, int value) {
    if (node == nullptr || node->data == value)
        return node;

    if (value < node->data)
        return findRecursive(node->left, value);

    return findRecursive(node->right, value);
}

void BinarySearchTree::traverse() {
    QString traversal;
    traverseRecursive(root, traversal);
    emit traversalCompleted(traversal);
}

void BinarySearchTree::traverseRecursive(Node* node, QString& traversal) {
    if (node != nullptr) {
        traverseRecursive(node->left, traversal);
        traversal += QString::number(node->data) + " ";
        traverseRecursive(node->right, traversal);
    }
}

void BinarySearchTree::insertSubtree(Node* subtreeRoot) {
    root = mergeTrees(root, subtreeRoot);
}

void BinarySearchTree::deleteSubtree(int value) {
    Node* subtreeRoot = find(value);
    root = removeRecursive(root, value);
    delete subtreeRoot;
}

Node* BinarySearchTree::mergeTrees(Node* tree1, Node* tree2) {
    if (!tree1)
        return tree2;
    if (!tree2)
        return tree1;
    addRecursive(tree1, tree2->data);
    mergeTrees(tree1, tree2->left);
    mergeTrees(tree1, tree2->right);
    delete tree2;
    return tree1;
}

void BinarySearchTree::insertBranch(int parentValue, int branchValue) {
    Node* parentNode = find(parentValue);
    if (parentNode) {
        addRecursive(parentNode, branchValue);
    }
}

void BinarySearchTree::deleteBranch(int parentValue, int branchValue) {
    Node* parentNode = find(parentValue);
    if (parentNode) {
        parentNode->left = removeRecursive(parentNode->left, branchValue);
        parentNode->right = removeRecursive(parentNode->right, branchValue);
    }
}

Node* BinarySearchTree::findLowestCommonAncestor(int value1, int value2) {
    return findLowestCommonAncestorRecursive(root, value1, value2);
}

Node* BinarySearchTree::findLowestCommonAncestorRecursive(Node* node, int value1, int value2) {
    if (!node)
        return nullptr;

    if (node->data > value1 && node->data > value2)
        return findLowestCommonAncestorRecursive(node->left, value1, value2);

    if (node->data < value1 && node->data < value2)
        return findLowestCommonAncestorRecursive(node->right, value1, value2);

    return node;
}
