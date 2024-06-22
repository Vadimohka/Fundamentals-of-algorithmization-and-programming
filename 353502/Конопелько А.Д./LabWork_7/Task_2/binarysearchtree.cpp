#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
    model = new QStandardItemModel();
}

BinarySearchTree::~BinarySearchTree() {
    delete model;
}

void BinarySearchTree::insert(int key, const QString& data) {
    insert(root, key, data);
}

void BinarySearchTree::insert(int key, const QString& data) {
    node = new Node;
    node->key = key;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
}

bool BinarySearchTree::search(int key, QString& data) {
    return search(root, key, data);
}

bool BinarySearchTree::search(Node* node, int key, QString& data) {
    if (node == nullptr) return false;
    if (key == node->key) {
        data = node->data;
        return true;
    } else if (key < node->key) {
        return search(node->left, key, data);
    } else {
        return search(node->right, key, data);
    }
}

void BinarySearchTree::remove(int key) {
    root = remove(root, key);
}

Node* BinarySearchTree::remove(Node* node, int key) {
    if (node == nullptr) return node;

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
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
        node->key = temp->key;
        node->data = temp->data;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

Node* BinarySearchTree::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

void BinarySearchTree::balance(Node *&node)
{

}

int BinarySearchTree::countNodesInLeftSubtree() {
    if (root == nullptr) return 0;

    return countNodesInLeftSubtree(root->left);
}

int BinarySearchTree::countNodesInLeftSubtree(Node* node) {
    if (node == nullptr) return 0;

    return 1 + countNodesInLeftSubtree(node->left) + countNodesInLeftSubtree(node->right);
}

void BinarySearchTree::printInOrder() {
    printInOrder(root);
}

void BinarySearchTree::printInOrder(Node* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        qDebug() << node->key << ": " << node->data;
        printInOrder(node->right);
    }
}

void BinarySearchTree::printPreOrder() {
    printPreOrder(root);
}

void BinarySearchTree::printPreOrder(Node* node) {
    if (node != nullptr) {
        qDebug() << node->key << ": " << node->data;
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void BinarySearchTree::printPostOrder() {
    printPostOrder(root);
}

void BinarySearchTree::printPostOrder(Node* node) {
    if (node != nullptr) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        qDebug() << node->key << ": " << node->data;
    }
}

QStandardItemModel* BinarySearchTree::getTreeModel() {
    model->clear();
    updateModel(root, nullptr);
    return model;
}

void BinarySearchTree::updateModel(Node* node, QStandardItem* parentItem) {
    if (node != nullptr) {
        QStandardItem* item = new QStandardItem(QString("%1: %2").arg(node->key).arg(node->data));
        if (parentItem == nullptr) {
            model->appendRow(item);
        } else {
            parentItem->appendRow(item);
        }
        updateModel(node->left, item);
        updateModel(node->right, item);
    }
}
