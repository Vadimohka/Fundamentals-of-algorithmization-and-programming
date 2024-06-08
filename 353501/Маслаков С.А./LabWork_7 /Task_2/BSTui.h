#include "BST.h"
#include <random>
#include <QTreeWidget>
#ifndef LAB7_BSTUI_H
#define LAB7_BSTUI_H
class BSTui : public BST<int,QString>{
public:
    BSTui(QVector<QString> a) : BST(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> keyDist(0, 100);
        for (int i = 0; i < a.size(); ++i) {
            int key = keyDist(gen);
            QString value = a[i];
            insert(key, value);
        }
    }
    void visualizer(QTreeWidget *treeWidget) {
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
    void addNodeToTreeWidget(QTreeWidgetItem* parentItem, Node<int,QString>* node){
        if (node == nullptr) {
            return;
        }
        QTreeWidgetItem* item = new QTreeWidgetItem(parentItem);
        item->setText(0, QString::number(node->key) + ": " + node->value);

        addNodeToTreeWidget(item, node->right);
        addNodeToTreeWidget(item, node->left);
    }

};
#endif //LAB7_BSTUI_H
