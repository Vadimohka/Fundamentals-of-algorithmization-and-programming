#pragma once

#include "bst.h"

class Solver : public BinarySearchTree {

public:
    Solver() : BinarySearchTree() {}

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

    int numNodesInLeftmostBranch() {
        int result = 0;
        Node *current = root->left;
        while (current != nullptr) {
            current = current->left;
            result++;
        }

        return result;
    }

private:
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