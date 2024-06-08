#include "BST.h"
#include <random>
#include <QTreeWidget>
#ifndef LAB7_BSTUI_H
#define LAB7_BSTUI_H
class BSTui : public BST<int,QString>{
public:
    static QString generateRandomString(int length) {
        const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, static_cast<int>(characters.size() - 1));

        QString result;
        result.reserve(length);
        for (int i = 0; i < length; ++i) {
            result += characters[dis(gen)];
        }
        return result;
    }
    BSTui() : BST(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> keyDist(0, 100);
        for (int i = 0; i < 20; ++i) {
            int key = keyDist(gen);
            QString value = generateRandomString(5);
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
    void insertSubTree(BSTui tree){
        insert(tree.root->key,tree.root->value);
    }
    void removeSubTree(Node<int,QString>* tree,QString a){
        if(a == "r"){
            clearTree(tree->right);
            tree->right = nullptr;
        }else if (a == "l"){
            clearTree(tree->left);
            tree->left = nullptr;
        }
    }
};
#endif //LAB7_BSTUI_H
