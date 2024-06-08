#ifndef AVLTREE_H
#define AVLTREE_H

#include <QMessageBox>
#include "qtextbrowser.h"
#include <cmath>
#include <string>
using namespace std;
class AVLTree
{
public:
    AVLTree()
        : root{nullptr}
    {}

    void insertFromArr(int keys[], string values[], int size)
    {
        for (int i = 0; i < size; i++) {
            root = insert(root, keys[i], values[i]);
            root = balance(root);
        }
    }

    //добавление новой записи
    void insert(int key, string value) { root = insert(root, key, value); }

    //поиск по ключу
    string find(int key) { return find(root, key); }

    //удаление по ключу
    bool remove(int key)
    {
        bool wasRemoved;
        root = remove(root, key, wasRemoved);
        return wasRemoved;
    }

    //прямой обход
    void printPreOrder(QTextBrowser *browser) { printPreOrder(browser, root); }

    //обратный обход
    void printPostOrder(QTextBrowser *browser) { printPostOrder(browser, root); }

    //по ключу
    void printInOrder(QTextBrowser *browser) { printInOrder(browser, root); }

    vector<int> nodesPerLevel()
    {
        vector<int> counts;
        nodesPerLevel(root, 0, counts);
        return counts;
    }

public:
    struct Node
    {
        int key;
        string value;
        Node *left;
        Node *right;
        int height;

        Node(int k, string v)
            : key(k)
            , value(v)
            , left(nullptr)
            , right(nullptr)
            , height(0)
        {}
    };

    Node *root;

    string find(Node *node, int key)
    {
        if (node == nullptr) {
            return "No found";
        }
        if (key < node->key) {
            return find(node->left, key);
        } else if (key > node->key) {
            return find(node->right, key);
        } else {
            return node->value;
        }
    }

    Node *insert(Node *node, int key, string value)
    {
        if (node == nullptr) {
            return balance(new Node(key, value));
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value;
        }
        updateHeight(node);
        return balance(node);
    }

    Node *remove(Node *node, int key, bool &wasRemoved)
    {
        if (node == nullptr) {
            wasRemoved = false;
            return nullptr;
        }

        if (key < node->key) {
            node->left = remove(node->left, key, wasRemoved);
        } else if (key > node->key) {
            node->right = remove(node->right, key, wasRemoved);
        } else {
            wasRemoved = true;
            if (node->left == nullptr || node->right == nullptr) {
                Node *temp = node->left ? node->left : node->right;
                if (temp == nullptr) { //нет потомков
                    temp = node;
                    node = nullptr;
                } else { //есть один потомок
                    *node = *temp;
                }
                delete temp;
                temp = nullptr;
            } else { //есть два потомка
                Node *temp = minValueNode(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = remove(node->right, temp->key, wasRemoved);
            }
        }
        if (node == nullptr) {
            return nullptr;
        }
        updateHeight(node);
        return balance(node);
    }

    //узел с минимальным ключом
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    int height(Node *node) { return node == nullptr ? 0 : node->height; }

    void updateHeight(Node *node)
    {
        int leftH = height(node->left);
        int rightH = height(node->right);
        node->height = (leftH > rightH ? leftH : rightH) + 1;
    }

    Node *rotateRight(Node *node)
    {
        Node *leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;
        updateHeight(node);
        updateHeight(leftChild);
        return leftChild;
    }

    Node *rotateLeft(Node *node)
    {
        Node *rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;
        updateHeight(node);
        updateHeight(rightChild);
        return rightChild;
    }

    int getBalanceFactor(Node *node) { return height(node->left) - height(node->right); }

    Node *balance(Node *node)
    {
        updateHeight(node);
        int balanceF = getBalanceFactor(node);
        if (balanceF > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        if (balanceF < -1) {
            if (getBalanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        return node;
    }

    void printPreOrder(QTextBrowser *browser, Node *node)
    {
        if (node != nullptr) {
            browser->append(QString::number(node->key) + " : "
                            + QString::fromStdString(node->value));
            printPreOrder(browser, node->left);
            printPreOrder(browser, node->right);
        }
    }

    void printPostOrder(QTextBrowser *browser, Node *node)
    {
        if (node != nullptr) {
            printPostOrder(browser, node->left);
            printPostOrder(browser, node->right);
            browser->append(QString::number(node->key) + " : "
                            + QString::fromStdString(node->value));
        }
    }

    void printInOrder(QTextBrowser *browser, Node *node)
    {
        if (node != nullptr) {
            printInOrder(browser, node->left);
            browser->append(QString::number(node->key) + " : "
                            + QString::fromStdString(node->value));
            printInOrder(browser, node->right);
        }
    }

    void nodesPerLevel(Node *node, size_t level, vector<int> &counts)
    {
        if (node == nullptr) {
            return;
        }
        if (level >= counts.size()) {
            counts.resize(level + 1);
        }
        counts[level]++;
        nodesPerLevel(node->left, level + 1, counts);
        nodesPerLevel(node->right, level + 1, counts);
    }
};

#endif // AVLTREE_H
