#include "graphicstree.h"

GraphicsTree::GraphicsTree(QWidget *parent) : QWidget(parent)
{
    tree = nullptr;
    setMinimumSize(800, 600);

}

void GraphicsTree::setTree(TreeNode *root)
{

    tree = root;
    repaint();
}

void GraphicsTree::paintEvent(QPaintEvent *event)
{
    if (!tree)
        return;

    QPainter painter(this);

    drawTree(&painter, tree, 300, 20, 100, 60);
}

void GraphicsTree::drawTree(QPainter *painter, TreeNode *node, int x, int y, int dx, int dy, int h)
{

    if (node)
    {
        r = 30 * pow(0.9, pow(h, 1.3));


        if (node->color)
            painter->setBrush(Qt::red);
        else
            painter->setBrush(Qt::black);
        painter->drawEllipse(x - r / 2, y - r / 2, r, r);

        QFont font = painter->font();
        font.setPointSize(15 * pow(0.9, pow(h, 1.1)));
        if (h == 6) font.setPointSize(6);
        painter->setFont(font);
        if (h <= 6){
            int textRight = 0;
            if (h == 0) textRight = 15;
            if (h == 1) textRight = 14;
            if (h == 2) textRight = 12;
            if (h == 3) textRight = 10;
            if (h == 4) textRight = 7;
            if (h == 5) textRight = 6;
            if (h == 6) textRight = 5;
            painter->drawText(x + textRight, y, QString::number(node->data));
        }
        //painter->setPen(Qt::blue);
        if (node->left)
        {

            //dx = dx / kriv;
            painter->drawLine(x, y, x - dx, y + dy);
            drawTree(painter, node->left, x - dx, y + dy, dx / kriv, dy, h + 1);
        }

        if (node->right)
        {
            painter->drawLine(x, y, x + dx, y + dy);
            drawTree(painter, node->right, x + dx, y + dy, dx / kriv, dy, h + 1);
        }
    }
}
