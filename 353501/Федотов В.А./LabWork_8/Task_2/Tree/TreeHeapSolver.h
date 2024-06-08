#pragma once

#include "TreeMaxHeap.h"

#include <QString>
#include <memory>
#include <qtreewidget.h>

class TreeHeapSolver : public TreeMaxHeap {
public:
    TreeHeapSolver() : TreeMaxHeap() {}

    void visualize(QTreeWidget* treeWidget) {
        treeWidget->clear();
        if (root == nullptr) {
            return;
        }
        
        auto *item = new QTreeWidgetItem();
        item->setText(0, QString::number(root->value));
        treeWidget->addTopLevelItem(item);
        addNodeToTreeWidget(treeWidget->topLevelItem(0), root->right);
        addNodeToTreeWidget(treeWidget->topLevelItem(0), root->left);
        treeWidget->expandAll();
    }

private:
    void addNodeToTreeWidget(QTreeWidgetItem* parentItem, std::shared_ptr<Node> node) {
        if (node == nullptr) {
            return;
        }

        QTreeWidgetItem* item = new QTreeWidgetItem(parentItem);
        item->setText(0, QString::number(node->value));

        addNodeToTreeWidget(item, node->right);
        addNodeToTreeWidget(item, node->left);
    }
};