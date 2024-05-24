#include "ring.h"

Ring::Ring(int x, int y, int width, int height, int pos) : QGraphicsItem()
{
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
    pos_ = pos;
    animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    timer = new QTimeLine(2000);
    timer->setFrameRange(0, 10000);
    animation->setTimeLine(timer);
}

QRectF Ring::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}

void Ring::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::red);
    painter->setPen(Qt::black);
    painter->drawRect(x_, y_, width_, height_);
}

void Ring::moveTo1(int pos)
{
    int start = pos_;
    timer->stop();
    animation->setPosAt(0, QPointF(xAnim, yAnim));
    animation->setPosAt(0.33, QPointF(xAnim, -200));
    animation->setPosAt(0.66, QPointF(0, -200));
    animation->setPosAt(1, QPointF(0, 20 * (start - pos)));
    timer->start();
    xAnim = 0;
    yAnim = 20 * (start - pos);
}

void Ring::moveTo2(int pos)
{
    int start = pos_;
    timer->stop();
    animation->setPosAt(0, QPointF(xAnim, yAnim));
    animation->setPosAt(0.33, QPointF(xAnim, -200));
    animation->setPosAt(0.66, QPointF(150, -200));
    animation->setPosAt(1, QPointF(150, 20 * (start - pos)));
    timer->start();
    xAnim = 150;
    yAnim = 20 * (start - pos);
}

void Ring::moveTo3(int pos)
{
    int start = pos_;
    timer->stop();
    animation->setPosAt(0, QPointF(xAnim, yAnim));
    animation->setPosAt(0.33, QPointF(xAnim, -200));
    animation->setPosAt(0.66, QPointF(300, -200));
    animation->setPosAt(1, QPointF(300, 20 * (start - pos)));
    timer->start();
    xAnim = 300;
    yAnim = 20 * (start - pos);
}

void Ring::xChange()
{
    x_ += 150;
}
