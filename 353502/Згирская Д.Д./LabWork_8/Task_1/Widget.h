//
// Created by zgdarya on 6/5/24.
//

#ifndef L8_T1_WIDGET_H
#define L8_T1_WIDGET_H

#include <QWidget>
#include <QPainter>
#include "AVLTree.h"

class Widget : public QWidget
{
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void setAVLTree(Node* tree);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Node* avlTree;
    void drawNode(QPainter &painter, Node *node, int x, int y, int dx, int dy);
};


#endif //L8_T1_WIDGET_H
