#include "graphics_tree.h"

GraphicsTree::GraphicsTree(QWidget *parent) : QWidget(parent)
{
    tree = nullptr;
    setMinimumSize(800, 600);

}

void GraphicsTree::setTree(TreeNode *root, bool poisk, int value)
{

    find = poisk;
    if (find)
        findValue = value;
    tree = root;
    repaint();
}

void GraphicsTree::paintEvent(QPaintEvent *event)
{
    if (!tree)
        return;

    QPainter painter(this);

    drawTree(&painter, tree, 700, 20, 300, 60, 0);
}

void GraphicsTree::drawTree(QPainter *painter, TreeNode *node, int x, int y, int dx, int dy, int h)
{
    painter->setBrush(QColorConstants::Svg::purple);
    painter->setPen(Qt::blue);
    if (node)
    {
        r = 30 * pow(0.9, pow(h, 1.3));

        if (find && node->data == findValue){
            painter->setBrush(Qt::red);

            painter->drawEllipse(x - r / 2, y - r / 2, r, r);

            QCoreApplication::processEvents();
            QThread::msleep(100);
        }
        else

        painter->drawEllipse(x - r / 2, y - r / 2, r, r);
        painter->setPen(Qt::white);
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
        painter->setPen(Qt::blue);
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
