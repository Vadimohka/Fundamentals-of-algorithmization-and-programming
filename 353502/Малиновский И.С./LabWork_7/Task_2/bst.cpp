#include "bst.h"
#include <algorithm>

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::insert(int key, const std::string& data) {
    root = insert(root, key, data);
}

Node* BST::insert(Node* node, int key, const std::string& data) {
    if (node == nullptr) return new Node(key, data);

    if (key < node->key)
        node->left = insert(node->left, key, data);
    else if (key > node->key)
        node->right = insert(node->right, key, data);

    return node;
}

bool BST::search(int key, std::string& data) const {
    Node* node = search(root, key);
    if (node != nullptr) {
        data = node->data;
        return true;
    }
    return false;
}

Node* BST::search(Node* node, int key) const {
    if (node == nullptr || node->key == key)
        return node;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void BST::remove(int key) {
    root = remove(root, key);
}

Node* BST::remove(Node* node, int key) {
    if (node == nullptr) return node;

    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
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

        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->data = temp->data;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

Node* BST::findMin(Node* node) const {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void BST::clear() {
    clear(root);
    root = nullptr;
}

void BST::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

std::vector<std::string> BST::inorder() const {
    std::vector<std::string> result;
    inorder(root, result);
    return result;
}

void BST::inorder(Node* node, std::vector<std::string>& result) const {
    if (node != nullptr) {
        inorder(node->left, result);
        result.push_back(node->data);
        inorder(node->right, result);
    }
}

std::vector<std::string> BST::preorder() const {
    std::vector<std::string> result;
    preorder(root, result);
    return result;
}

void BST::preorder(Node* node, std::vector<std::string>& result) const {
    if (node != nullptr) {
        result.push_back(node->data);
        preorder(node->left, result);
        preorder(node->right, result);
    }
}

std::vector<std::string> BST::postorder() const {
    std::vector<std::string> result;
    postorder(root, result);
    return result;
}

void BST::postorder(Node* node, std::vector<std::string>& result) const {
    if (node != nullptr) {
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->data);
    }
}

int BST::maxDepth() const {
    return maxDepth(root);
}

int BST::maxDepth(Node* node) const {
    if (node == nullptr) return 0;
    return std::max(maxDepth(node->left), maxDepth(node->right)) + 1;
}

void BST::balance() {
    std::vector<Node*> nodes;
    storeBSTNodes(root, nodes);
    root = balance(nodes, 0, nodes.size() - 1);
}

void BST::storeBSTNodes(Node* node, std::vector<Node*>& nodes) {
    if (node == nullptr) return;

    storeBSTNodes(node->left, nodes);
    nodes.push_back(node);
    storeBSTNodes(node->right, nodes);
}

Node* BST::balance(std::vector<Node*>& nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* node = nodes[mid];

    node->left = balance(nodes, start, mid - 1);
    node->right = balance(nodes, mid + 1, end);

    return node;
}
