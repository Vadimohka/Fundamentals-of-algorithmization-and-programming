#include "hanoitower.h"

HanoiTower::HanoiTower(int n) : QGraphicsItem()
{
    n_ = n;
}

void HanoiTower::hanoi(int n, int first, int second, int third)
{
    if (n != 0)
    {
        hanoi(n -1, first, third, second);
        from.push_back(first);
        to.push_back(third);
        hanoi(n -1, second, first, third);
    }
}

QRectF HanoiTower::boundingRect() const
{
    return QRectF(-1000, -1000, 2000, 2000);
}

void HanoiTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::darkGray);
    painter->setBrush(Qt::darkGray);
    painter->drawRect(-300, 200, 600, 20);
    painter->drawRect(-150, 200, 20, -200);
    painter->drawRect(0, 200, 20, -200);
    painter->drawRect(150, 200, 20, -200);
}
