//
// Created by acryoz on 25.05.24.
//
#ifndef LAB7_LIB_BST_GRAPHVIEW_H_
#define LAB7_LIB_BST_GRAPHVIEW_H_

#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPen>
#include <QWidget>
#include "avl.h"

static const int DEFAULT_X = 500;
static const int DEFAULT_Y = 50;

class TreeNode {
   public:
    TreeNode(int, int, int);
    int number;
    int x;
    int y;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class TreeGraph : public QGraphicsView {
   public:
    explicit TreeGraph(QWidget* parent = nullptr);
   public slots:
    void insertIntoTree(std::pair<int, QString>);
    void deleteFromTree(int);
    TreeNode* find(int);

   private:
    TreeNode* innerFind(TreeNode*, int);
    TreeNode* root;
    AVLTree<int, QString> tree_;
    void addNode(TreeNode*, TreeNode*);
    int calculateSubtreeWidth(AVLTree<int, QString>::Node*);
    QGraphicsScene* scene;
    void addSubtree(TreeNode*& root, AVLTree<int, QString>::Node*, int, int,
                    int);
    void upd();
};
#endif  //LAB7_LIB_BST_GRAPHVIEW_H_
