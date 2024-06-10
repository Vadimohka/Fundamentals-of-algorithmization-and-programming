#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {}

void Widget::setAVLTree(Node* tree) {
    avlTree = tree;

    if (avlTree != nullptr)
        update();
}

void Widget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (avlTree != nullptr) {
        drawNode(painter, avlTree, width() / 2, 30, 50, 50);
    }
}

void Widget::drawNode(QPainter &painter, Node *node, int x, int y, int dx, int dy) {
    if (node == nullptr) return;

    painter.drawEllipse(x - 15, y - 15, 30, 30);
    painter.drawText(x - 10, y + 5, QString::number(node->value));

    if (node->left != nullptr) {
        painter.drawLine(x, y, x - dx, y + dy);
        drawNode(painter, node->left, x - dx, y + dy, dx / 1.5, dy);
    }

    if (node->right != nullptr) {
        painter.drawLine(x, y, x + dx, y + dy);
        drawNode(painter, node->right, x + dx, y + dy, dx / 1.5, dy);
    }
}
