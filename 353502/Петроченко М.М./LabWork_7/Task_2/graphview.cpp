//
// Created by acryoz on 25.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GraphView.h" resolved

#include "graphview.h"

TreeNode::TreeNode(int number, int x, int y) : number(number), x(x), y(y) {}

TreeGraph::TreeGraph(QWidget* parent)
    : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
    this->root = nullptr;
    setScene(scene);
}

void TreeGraph::insertIntoTree(std::pair<int, QString> kv) {
    this->tree_.insert(kv);
    this->upd();
}

void TreeGraph::deleteFromTree(int key) {
    this->tree_.del(key);
    this->upd();
}

int TreeGraph::calculateSubtreeWidth(AVLTree<int, QString>::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(calculateSubtreeWidth(node->left),
                        calculateSubtreeWidth(node->right));
}

void TreeGraph::addSubtree(TreeNode*& root, AVLTree<int, QString>::Node* node,
                           int x, int y, int horizontalOffset) {
    if (node == nullptr) {
        return;
    }
    root = new TreeNode(node->kv.first, x, y);
    int leftWidth = calculateSubtreeWidth(node->left) * horizontalOffset;
    int rightWidth = calculateSubtreeWidth(node->right) * horizontalOffset;
    this->addSubtree(root->left, node->left, x - leftWidth, y + 100,
                     horizontalOffset / 2);
    this->addSubtree(root->right, node->right, x + rightWidth, y + 100,
                     horizontalOffset / 2);
}

void TreeGraph::upd() {
    if (this->tree_.root_ == nullptr) {
        this->scene->clear();
        return;
    }
    this->root =
        new TreeNode(this->tree_.root_->kv.first, DEFAULT_X, DEFAULT_Y);
    int horizontalOffset = 100;  // Initial offset value
    this->addSubtree(this->root->left, this->tree_.root_->left,
                     DEFAULT_X - horizontalOffset, DEFAULT_Y + 100,
                     horizontalOffset / 2);
    this->addSubtree(this->root->right, this->tree_.root_->right,
                     DEFAULT_X + horizontalOffset, DEFAULT_Y + 100,
                     horizontalOffset / 2);
    this->scene->clear();
    this->addNode(this->root, nullptr);
    this->update();
}

void TreeGraph::addNode(TreeNode* node, TreeNode* parent = nullptr) {
    if (node != nullptr) {
        QGraphicsEllipseItem* ellipse = scene->addEllipse(
            node->x - 15, node->y - 15, 30, 30, QPen(), QBrush(Qt::white));
        QGraphicsTextItem* text = scene->addText(QString::number(node->number));
        text->setPos(node->x - 7, node->y - 10);
        if (parent) {
            scene->addLine(parent->x, parent->y, node->x, node->y);
        }
        addNode(node->left, node);
        addNode(node->right, node);
    }
}

TreeNode* TreeGraph::find(int key) {
    return innerFind(this->root, key);
}

TreeNode* TreeGraph::innerFind(TreeNode* inner_root, int key) {
    if (inner_root == nullptr) {
        return nullptr;
    }
    if (key == inner_root->number) {
        return inner_root;
    }
    if (key < inner_root->number) {
        return this->innerFind(inner_root->left, key);
    }
    return this->innerFind(inner_root->right, key);
}
