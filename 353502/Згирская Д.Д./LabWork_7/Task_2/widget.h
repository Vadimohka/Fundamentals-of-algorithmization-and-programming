#ifndef WIDGET_H
#define WIDGET_H

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

#endif // WIDGET_H
