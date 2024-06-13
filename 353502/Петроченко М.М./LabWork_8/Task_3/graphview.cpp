//
// Created by acryoz on 25.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GraphView.h" resolved

#include "graphview.h"

TreeNode::TreeNode(int number, int x, int y, color_t color)
    : number(number), x(x), y(y), color(color) {}

TreeGraph::TreeGraph(QWidget* parent)
    : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
    this->root = nullptr;
    this->tree_.root_ = nullptr;
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

int TreeGraph::calculateSubtreeWidth(RedBlackTree<int, QString>::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(calculateSubtreeWidth(node->children[LEFT]),
                        calculateSubtreeWidth(node->children[RIGHT]));
}

void TreeGraph::addSubtree(TreeNode*& root,
                           RedBlackTree<int, QString>::Node* node, int x, int y,
                           int horizontalOffset) {
    if (node == nullptr) {
        return;
    }
    root = new TreeNode(node->kv.first, x, y, node->color);
    int leftWidth =
        calculateSubtreeWidth(node->children[LEFT]) * horizontalOffset;
    int rightWidth =
        calculateSubtreeWidth(node->children[RIGHT]) * horizontalOffset;
    this->addSubtree(root->left, node->children[LEFT], x - leftWidth, y + 100,
                     horizontalOffset / 2);
    this->addSubtree(root->right, node->children[RIGHT], x + rightWidth,
                     y + 100, horizontalOffset / 2);
}

void TreeGraph::upd() {
    if (this->tree_.root_ == nullptr) {
        this->scene->clear();
        return;
    }
    this->root =
        new TreeNode(this->tree_.root_->kv.first, DEFAULT_X, DEFAULT_Y, BLACK);
    int horizontalOffset = 100;  // Initial offset value
    this->addSubtree(this->root->left, this->tree_.root_->children[LEFT],
                     DEFAULT_X - horizontalOffset, DEFAULT_Y + 100,
                     horizontalOffset / 2);
    this->addSubtree(this->root->right, this->tree_.root_->children[RIGHT],
                     DEFAULT_X + horizontalOffset, DEFAULT_Y + 100,
                     horizontalOffset / 2);
    this->scene->clear();
    this->addNode(this->root, nullptr);
    this->update();
}

void TreeGraph::addNode(TreeNode* node, TreeNode* parent = nullptr) {
    if (node != nullptr) {
        QBrush brush;
        if (node->color == RED) {
            brush = QBrush(Qt::red);
        } else {
            brush = QBrush(Qt::black);
        }
        QGraphicsEllipseItem* ellipse = scene->addEllipse(
            node->x - 15, node->y - 15, 30, 30, QPen(), brush);
        QGraphicsTextItem* text = scene->addText(QString::number(node->number));
        text->setDefaultTextColor(Qt::white);
        text->setPos(node->x - 7, node->y - 10);
        if (parent) {
            scene->addLine(parent->x, parent->y, node->x, node->y);
        }
        this->addNode(node->left, node);
        this->addNode(node->right, node);
    } /*else {
        if (parent) {
            scene->addLine(parent->x, parent->y, node->x, node->y);
        } else {
            return;
        }
        QGraphicsEllipseItem* ellipse = scene->addEllipse(
            node->x - 15, node->y - 15, 30, 30, QPen(), QBrush(Qt::black));
        QGraphicsTextItem* text = scene->addText("NULL");
        text->setPos(node->x - 7, node->y - 10);
    }
    */
}

TreeNode* TreeGraph::find(int key) {
    return innerFind(this->root, key);
}

TreeNode* TreeGraph::innerFind(TreeNode* inner_root, int key) {
    RedBlackTree<int, QString>::Node* found = this->tree_.find(key);
    if (found == nullptr) {
        return nullptr;
    }
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
