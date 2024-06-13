#ifndef BRANCHBST_H
#define BRANCHBST_H

#include <QTreeWidget>

#include "bst.h"

class BranchBST: public BST<QString>
{
    QTreeWidget* widget;
public:
    BranchBST(): BST(){}

    void deleteBrunch(int key){
        root = deleteBrunch(key, root);
    }

    void setTreeWidget(QTreeWidget* widget){
        this->widget = widget;
    }

    void setTree(){
        widget->clear();
        QTreeWidgetItem *item = new QTreeWidgetItem(widget);
        item->setText(0, QString::number(root->key)+'.'+root->value);
        item->addChild(buildTree(root->right, item));
        item->addChild(buildTree(root->left, item));
        widget->addTopLevelItem(item);
    }


private:

    QTreeWidgetItem* buildTree(Node* node, QTreeWidgetItem* parent){
        if(node == nullptr){
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0, "NULL");
            return item;
        }
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        item->setText(0, QString::number(node->key)+'.'+node->value);
        item->addChild(buildTree(node->right, item));
        item->addChild(buildTree(node->left, item));
        return item;
    }

    Node* deleteBrunch(int key, Node* node){
        if(node == nullptr){
            return nullptr;
        }
        if(key < node->key){
            node->left = deleteBrunch(key, node->left);
        }
        else if(key > node->key){
            node->right = deleteBrunch(key, node->right);
        }
        else if(key == node->key){
            delete node;
            node = nullptr;
            return node;
        }
        while(qAbs(height(node->right) - height(node->left)) > 1){
            node = balance(node);
        }
        return node;
    }
};

#endif // BRANCHBST_H
