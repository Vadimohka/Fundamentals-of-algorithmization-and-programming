#ifndef BST_H
#define BST_H

#include "qtextbrowser.h"
#include <string>
using namespace std;

class BST
{
public:
    struct Node
    {
        int key;
        string value;
        Node *left;
        Node *right;

        Node(int k, string v)
            : key(k)
            , value(v)
            , left(nullptr)
            , right(nullptr)
        {}
    };

    Node *root;

    BST()
        : root(nullptr)
    {}

    void insertFromArr(int keys[], string values[], int size)
    {
        for (int i = 0; i < size; i++) {
            root = insert(root, keys[i], values[i]);
        }
    }

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

    Node *insert(Node *node, int key, string value)
    {
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

    void insert(int key, string value) { root = insert(root, key, value); }

    string find(Node *node, int key)
    {
        if (node == nullptr) {
            return "Not found";
        }
        if (key < node->key) {
            return find(node->left, key);
        } else if (key > node->key) {
            return find(node->right, key);
        } else {
            return node->value;
        }
    }

    string find(int key) { return find(root, key); }

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
            if (node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                node = nullptr;
                return temp;
            } else if (node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                node = nullptr;
                return temp;
            } else {
                Node *temp = minValueNode(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = remove(node->right, temp->key, wasRemoved);
            }
        }
        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (/*current &&*/ current->left != nullptr) {
            current = current->left;
        }
        return current;
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

#endif // BST_H
