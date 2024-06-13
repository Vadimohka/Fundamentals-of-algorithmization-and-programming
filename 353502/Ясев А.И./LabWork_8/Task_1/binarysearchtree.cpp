#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

Node* BinarySearchTree::insert(Node* node, int key, const QString& value) {
    if (node == nullptr) {
        return new Node(key, value);
    }

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else if (key > node->key) {
        node->right = insert(node->right, key, value);
    } else {
        node->value = value;
    }

    return node;
}

void BinarySearchTree::insert(int key, const QString& value) {
    root = insert(root, key, value);
}

Node* BinarySearchTree::remove(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (node->left && node->right) {
            Node* minNode = node->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            node->key = minNode->key;
            node->value = minNode->value;
            node->right = remove(node->right, minNode->key);
        } else if (node->left) {
            node = node->left;
        } else if (node->right) {
            node = node->right;
        } else {
            delete node;
            node = nullptr;
        }
    }

    return node;
}

void BinarySearchTree::remove(int key) {
    root = remove(root, key);
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

QString BinarySearchTree::search(int key) {
    Node* node = search(root, key);
    return node ? node->value : "";
}

void BinarySearchTree::traverseInOrder(Node* node, QVector<QPair<int, QString>>& result) {
    if (node) {
        traverseInOrder(node->left, result);
        result.push_back(QPair<int, QString>(node->key, node->value));
        traverseInOrder(node->right, result);
    }
}

QVector<QPair<int, QString>> BinarySearchTree::traverseInOrder() {
    QVector<QPair<int, QString>> result;
    traverseInOrder(root, result);
    return result;
}

void BinarySearchTree::traversePreOrder(Node* node, QVector<QPair<int, QString>>& result) {
    if (node) {
        result.push_back(QPair<int, QString>(node->key, node->value));
        traversePreOrder(node->left, result);
        traversePreOrder(node->right, result);
    }
}

QVector<QPair<int, QString>> BinarySearchTree::traversePreOrder() {
    QVector<QPair<int, QString>> result;
    traversePreOrder(root, result);
    return result;
}

void BinarySearchTree::traversePostOrder(Node* node, QVector<QPair<int, QString>>& result) {
    if (node) {
        traversePostOrder(node->left, result);
        traversePostOrder(node->right, result);
        result.push_back(QPair<int, QString>(node->key, node->value));
    }
}

QVector<QPair<int, QString>> BinarySearchTree::traversePostOrder() {
    QVector<QPair<int, QString>> result;
    traversePostOrder(root, result);
    return result;
}

Node* BinarySearchTree::balance(const QVector<QPair<int, QString>>& nodes, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* node = new Node(nodes[mid].first, nodes[mid].second);
    node->left = balance(nodes, start, mid - 1);
    node->right = balance(nodes, mid + 1, end);
    return node;
}

void BinarySearchTree::balance() {
    QVector<QPair<int, QString>> nodes = traverseInOrder();
    clear(root);
    root = balance(nodes, 0, nodes.size() - 1);
}

void BinarySearchTree::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

Node* BinarySearchTree::getRoot(){
    return root;
}

void BinarySearchTree::traverseByValue(Node* node, QVector<QPair<int, QString>>& result) {
    if (node) {
        traverseByValue(node->left, result);
        result.push_back(QPair<int, QString>(node->key, node->value));
        traverseByValue(node->right, result);
    }
}

QVector<QPair<int, QString>> BinarySearchTree::traverseByValue() {
    QVector<QPair<int, QString>> result;
    traverseByValue(root, result);
    std::sort(result.begin(), result.end());

    return result;
}
