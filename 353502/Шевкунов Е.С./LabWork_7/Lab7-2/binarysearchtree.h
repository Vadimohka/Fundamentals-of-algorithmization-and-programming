#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <QString>
#include <QVector>
#include <QTextStream>

class BinarySearchTree {
public:
    struct Node {
        QString data;
        int key;
        Node *left, *right;

        Node(const QString& data, int key) : data(data), key(key), left(nullptr), right(nullptr) {}
    };

    BinarySearchTree() : root(nullptr) {}

    void insert(const QString& data, int key) {
        root = insertRec(root, data, key);
    }

    void insertFromVector(const QVector<QPair<QString, int>>& vec) {
        for (const auto& pair : vec) {
            insert(pair.first, pair.second);
        }
    }

    Node* search(int key) {
        return searchRec(root, key);
    }

    void remove(int key) {
        root = removeRec(root, key);
    }

    void printInOrder(QTextStream& out) {
        inOrderRec(root, out);
    }

    void printPreOrder(QTextStream& out) {
        preOrderRec(root, out);
    }

    void printPostOrder(QTextStream& out) {
        postOrderRec(root, out);
    }

public:
    Node* root;

private:
    Node* insertRec(Node* node, const QString& data, int key) {
        if (!node) return new Node(data, key);
        if (key < node->key)
            node->left = insertRec(node->left, data, key);
        else
            node->right = insertRec(node->right, data, key);
        return node;
    }

    Node* searchRec(Node* node, int key) {
        if (!node || node->key == key) return node;
        if (key < node->key)
            return searchRec(node->left, key);
        return searchRec(node->right, key);
    }

    Node* removeRec(Node* node, int key) {
        if (!node) return node;

        if (key < node->key)
            node->left = removeRec(node->left, key);
        else if (key > node->key)
            node->right = removeRec(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = removeRec(node->right, temp->key);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    void inOrderRec(Node* node, QTextStream& out) {
        if (node) {
            inOrderRec(node->left, out);
            out << node->key << ": " << node->data << "\n";
            inOrderRec(node->right, out);
        }
    }

    void preOrderRec(Node* node, QTextStream& out) {
        if (node) {
            out << node->key << ": " << node->data << "\n";
            preOrderRec(node->left, out);
            preOrderRec(node->right, out);
        }
    }

    void postOrderRec(Node* node, QTextStream& out) {
        if (node) {
            postOrderRec(node->left, out);
            postOrderRec(node->right, out);
            out << node->key << ": " << node->data << "\n";
        }
    }
};

#endif // BINARY_SEARCH_TREE_H
