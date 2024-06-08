#pragma once

#include "AvlTree.h"

#include <QTreeWidget>
#include <limits>

class Solver : public AvlTree<QString> {

public:
    Solver() : AvlTree() {}

    int findByValue (const QString &value) {
        Node* node = searchByValue(root, value);
        return node ? node->key : -1;
    }

    void removeByValue(const QString &value) {
        Node *node = searchByValue(root, value);
        if (node)
            remove(node->key);
    }

    int lowestParentKey(int key1, int key2) {
        Node *lca = lowestCommonAncestor(root, key1, key2);
        if (lca == nullptr)
            return -1;

        Node *tmp = root;
        int min = tmp->key;
        while (tmp != nullptr) {
            if (min > tmp->key) 
                min = tmp->key;

            if (lca->key < tmp->key )
                tmp = tmp->left;
            else if (lca->key > tmp->key)
                tmp = tmp->right;
            else
                break;
        }

        return min;
    }

    void insertSubtree(const Solver &subtree) {
        QVector<Node *>nodes;
        subtree.storeNodes(subtree.root, nodes);

        for (auto node : nodes) {
            insert(node->key, node->value);
        }
    }

    void clearFrom(int key) {
        Node *node = search(root, key);
        if (node == root) {
            clear();
        } else if (node != nullptr) {
            clearSubTree(node);
        }
    }

    QVector<QPair<int, QString>> getPreorder() {
        QVector<QPair<int, QString>> result;
        preorderTraversal(root, result);
        return result;
    }

    QVector<QPair<int, QString>> getPostorder() {
        QVector<QPair<int, QString>> result;
        postorderTraversal(root, result);
        return result;
    }

    QVector<QPair<int, QString>> getInorder() {
        QVector<QPair<int, QString>> result;
        inorderTraversal(root, result);
        return result;
    }

    void visualize(QTreeWidget* treeWidget) {
        treeWidget->clear();
        if (root == nullptr) {
            return;
        }
        
        auto *item = new QTreeWidgetItem();
        item->setText(0, QString::number(root->key) + ": " + root->value);
        treeWidget->addTopLevelItem(item);
        addNodeToTreeWidget(treeWidget->topLevelItem(0), root->right);
        addNodeToTreeWidget(treeWidget->topLevelItem(0), root->left);
        treeWidget->expandAll();
    }

private:
    void clearSubTree(Node *node) {
        if (node != nullptr) {
            clearSubTree(node->left);
            clearSubTree(node->right);
            removeNodeNoBalance(root, node->key);
        }
    }

    Node* removeNodeNoBalance(Node* node, long k) {
        if (node == nullptr)
            return node;
        
        if (k < node->key) {
            node->left = removeNodeNoBalance(node->left, k);
        } else if (k > node->key) {
            node->right = removeNodeNoBalance(node->right, k);
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

            Node* tmp = findMinNode(node->right);
            node->key = tmp->key;
            node->value = tmp->value;
            node->right = removeNodeNoBalance(node->right, tmp->key);
        }

        return node;
    }

    Node* insertNodeNoBalance(Node* node, int key, QString value) {
        if (node == nullptr)
            return new Node(key, value);

        if (key < node->key)
            node->left = insertNode(node->left, key, value);
        else if (key > node->key)
            node->right = insertNode(node->right, key, value);
        else
            return node;

        return node;
    }

    Node* searchByValue(Node* node, QString value) const {
        if (!node)
            return nullptr;

        if (node->value == value)
            return node;

        Node* result = searchByValue(node->left, value);
        if (result)
            return result;

        return searchByValue(node->right, value);
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

    void storeNodes(Node* node, QVector<Node*>& nodes) const {
        if (node == nullptr) {
            return;
        }

        storeNodes(node->left, nodes);
        nodes.push_back(node);
        storeNodes(node->right, nodes);
    }

    Node* lowestCommonAncestor(Node* node, int key1, int key2) const {
        if (!node)
            return nullptr;

        if (key1 < node->key && key2 < node->key)
            return lowestCommonAncestor(node->left, key1, key2);
        if (key1 > node->key && key2 > node->key)
            return lowestCommonAncestor(node->right, key1, key2);

        Node* left = search(node, key1);
        Node* right = search(node, key2);
        if (left && right)
            return node;

        return nullptr;
    }

    void addNodeToTreeWidget(QTreeWidgetItem* parentItem, Node* node) {
        if (node == nullptr) {
            return;
        }

        QTreeWidgetItem* item = new QTreeWidgetItem(parentItem);
        item->setText(0, QString::number(node->key) + ": " + node->value);

        addNodeToTreeWidget(item, node->right);
        addNodeToTreeWidget(item, node->left);
    }
};