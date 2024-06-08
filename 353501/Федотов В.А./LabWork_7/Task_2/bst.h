#pragma once

#include <qcontainerfwd.h>
#include <qlist.h>
#include <QString>
#include <QVector>
#include <QTreeWidget>
#include <qlogging.h>
#include <qtreewidget.h>


class BinarySearchTree {
protected:
    struct Node {
        int key;
        QString value;
        Node *left;
        Node *right;

        Node(int key, QString value) 
            : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node *root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key, const QString& value) {
        root = insertHelper(root, key, value);
    }

    QString find(int key) {
        Node *result = findHelper(root, key);
        if (result != nullptr) {
            return result->value;
        }
        return "";
    }

    void remove(int key) {
        root = removeHelper(root, key);
    }

    int countNodes(Node *node) {
        if (node == nullptr)
            return 0;

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void balance() {
        QVector<Node*> nodes;
        storeNodes(root, nodes);

        root = buildBalancedTree(nodes, 0, nodes.size() - 1);
    }

protected:
    Node *insertHelper(Node *node, int key, QString value) {
        if (node == nullptr)
            return new Node(key, value);

        if (key < node->key) {
            node->left = insertHelper(node->left, key, value);
        } else {
            node->right = insertHelper(node->right, key, value);
        }

        return node;
    }

    Node *findHelper(Node *node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return findHelper(node->left, key);
        } else {
            return findHelper(node->right, key);
        }
    }

    Node *removeHelper(Node *node, int key) {
        if (node == nullptr) 
            return node;

        if (key < node->key) {
            node->left = removeHelper(node->left, key);
        } else if (key > node->key) {
            node->right = removeHelper(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            } else if (node->right == nullptr) {
                Node *tmp = node->left;
                delete node;
                return tmp;
            }

            Node *temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = removeHelper(node->right, temp->key);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void preorderTraversal(Node* node, QVector<QPair<int, QString>>& result) {
        if (node != nullptr) {
            result.push_back(QPair<int, QString>(node->key, node->value));
            preorderTraversal(node->left, result);
            preorderTraversal(node->right, result);
        }
    }

    void postorderTraversal(Node* node, QVector<QPair<int, QString>>& result) {
        if (node != nullptr) {
            postorderTraversal(node->left, result);
            postorderTraversal(node->right, result);
            result.push_back(QPair<int, QString>(node->key, node->value));
        }
    }

    void inorderTraversal(Node* node, QVector<QPair<int, QString>>& result) {
        if (node != nullptr) {
            inorderTraversal(node->left, result);
            result.push_back(QPair<int, QString>(node->key, node->value));
            inorderTraversal(node->right, result);
        }
    }

    void storeNodes(Node* node, QVector<Node*>& nodes) {
        if (node == nullptr) {
            return;
        }

        storeNodes(node->left, nodes);
        nodes.push_back(node);
        storeNodes(node->right, nodes);
    }

    Node* buildBalancedTree(QVector<Node*>& nodes, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        Node* node = nodes[mid];

        node->left = buildBalancedTree(nodes, start, mid - 1);
        node->right = buildBalancedTree(nodes, mid + 1, end);

        return node;
    }

};