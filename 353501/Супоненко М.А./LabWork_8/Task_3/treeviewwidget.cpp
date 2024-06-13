#include "treeviewwidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

TreeViewWidget::TreeViewWidget(QWidget *parent) : QWidget(parent), tree(nullptr) {}

void TreeViewWidget::setTree(RedBlackTree* t) {
    tree = t;
    update();
}

void TreeViewWidget::drawNode(QPainter& painter, Node* node, int x, int y, int dx, int dy) {
    if (node == nullptr) {
        return;
    }

    QColor nodeColor = (node->color == RED) ? Qt::red : Qt::black;
    painter.setBrush(QBrush(nodeColor));
    painter.drawEllipse(x - 15, y - 15, 30, 30);
    
    painter.setPen(QPen(Qt::white));
    painter.drawText(x - 5, y + 5, QString::number(node->data));

    painter.setPen(QPen(Qt::black));
    
    if (node->left != nullptr) {
        painter.drawLine(x, y, x - dx, y + dy);
        drawNode(painter, node->left, x - dx, y + dy, dx / 2, dy);
    } else {
        // Рисуем линию и черный лист для отсутствующего левого потомка
        painter.drawLine(x, y, x - dx, y + dy);
        painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(x - dx - 15, y + dy - 15, 30, 30);
    }

    if (node->right != nullptr) {
        painter.drawLine(x, y, x + dx, y + dy);
        drawNode(painter, node->right, x + dx, y + dy, dx / 2, dy);
    } else {
        // Рисуем линию и черный лист для отсутствующего правого потомка
        painter.drawLine(x, y, x + dx, y + dy);
        painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(x + dx - 15, y + dy - 15, 30, 30);
    }
}

void TreeViewWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);

    if (tree == nullptr || tree->getRoot() == nullptr) {
        return;
    }

    drawNode(painter, tree->getRoot(), width() / 2, 40, width() / 4, 40);
}
