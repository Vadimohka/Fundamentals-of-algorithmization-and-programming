#ifndef BSTTREE_H
#define BSTTREE_H

#include "QtWidgets/qgraphicsscene.h"
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <iostream>
#include <string>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    explicit Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BSTTree {
public:
    BSTTree() : root(nullptr) {}
    BSTTree(const BSTTree& other) : root(copyTree(other.root)) {}
    BSTTree(BSTTree&& other) noexcept : root(other.root) {
        other.root = nullptr;
    }
    BSTTree& operator=(const BSTTree& other) {
        if (this != &other) {
            clear(root);
            root = copyTree(other.root);
        }
        return *this;
    }
    ~BSTTree() {
        clear(root);
    }

    void insert(T data) {
        root = insertRecursive(root, data);
    }
    void insert(const BSTTree& other) {
        insertRecursive(root, other.root);
    }
    Node<T>* getRoot() const { return root; }
    void print() const {
        printRecursive(root);
    }
    std::string toString() const {
        std::string result;
        toStringRecursive(root, result);
        return result;
    }
    void remove(T data) {
        root = removeRecursive(root, data);
    }
    void remove(const BSTTree& other) {
        removeRecursive(root, other.root);
    }
    void clear() {
        clear(root);
    }
    T LCA(T a, T b) const {
        return LCARecursive(root, a, b)->data;
    }
    bool find(T data) const {
        return findRecursive(root, data);
    }
    void drawTree(QGraphicsScene* scene, Node<T>* node, int x, int y, int level) const {
        drawTreeRecursive(scene, node, x, y, level);
    }
    void color(QGraphicsScene* scene, Node<T>* node, int x, int y, int level, int value) const {
        colorRecursive(scene, node, x, y, level, value);
    }

private:
    Node<T>* root;

    Node<T>* copyTree(Node<T>* node) const {
        if (node == nullptr) {
            return nullptr;
        }
        Node<T>* newNode = new Node<T>(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    Node<T>* insertRecursive(Node<T>* node, T data) {
        if (node == nullptr) {
            return new Node<T>(data);
        }
        if (data < node->data) {
            node->left = insertRecursive(node->left, data);
        } else {
            node->right = insertRecursive(node->right, data);
        }
        return node;
    }

    void insertRecursive(Node<T>*& node, Node<T>* other) {
        if (other == nullptr) {
            return;
        }
        insert(other->data);
        insertRecursive(node, other->left);
        insertRecursive(node, other->right);
    }

    void printRecursive(Node<T>* node) const {
        if (node == nullptr) {
            return;
        }
        printRecursive(node->left);
        std::cout << node->data << "-->";
        printRecursive(node->right);
    }

    void toStringRecursive(Node<T>* node, std::string& result) const {
        if (node == nullptr) {
            return;
        }
        toStringRecursive(node->left, result);
        result += std::to_string(node->data) + "-->";
        toStringRecursive(node->right, result);
    }

    Node<T>* removeRecursive(Node<T>* node, T data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = removeRecursive(node->left, data);
        } else if (data > node->data) {
            node->right = removeRecursive(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node<T>* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node<T>* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node<T>* temp = findMin(node->right);
                node->data = temp->data;
                node->right = removeRecursive(node->right, temp->data);
            }
        }
        return node;
    }

    void removeRecursive(Node<T>*& node, Node<T>* other) {
        if (other == nullptr) {
            return;
        }
        remove(other->data);
        removeRecursive(node, other->left);
        removeRecursive(node, other->right);
    }

    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void clear(Node<T>*& node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }

    Node<T>* LCARecursive(Node<T>* node, T a, T b) const {
        if (node == nullptr || node->data == a || node->data == b) {
            return node;
        }
        Node<T>* left = LCARecursive(node->left, a, b);
        Node<T>* right = LCARecursive(node->right, a, b);
        if (left != nullptr && right != nullptr) {
            return node;
        }
        return left != nullptr ? left : right;
    }

    bool findRecursive(Node<T>* node, T data) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == data) {
            return true;
        }
        if (data < node->data) {
            return findRecursive(node->left, data);
        }
        return findRecursive(node->right, data);
    }

    void drawTreeRecursive(QGraphicsScene* scene, Node<T>* node, int x, int y, int level) const {
        if (node == nullptr) {
            return;
        }
        int offset = 100 / (level + 1);
        scene->addRect(x, y, 40, 40);
        QGraphicsTextItem* text = scene->addText(QString::number(node->data));
        text->setPos(x + 11, y + 7);
        if (node->left) {
            scene->addLine(x + 20, y + 40, x - offset + 20, y + 80);
            drawTreeRecursive(scene, node->left, x - offset, y + 80, level + 1);
        }
        if (node->right) {
            scene->addLine(x + 20, y + 40, x + offset + 20, y + 80);
            drawTreeRecursive(scene, node->right, x + offset, y + 80, level + 1);
        }
    }

#endif // BSTTREE_H
