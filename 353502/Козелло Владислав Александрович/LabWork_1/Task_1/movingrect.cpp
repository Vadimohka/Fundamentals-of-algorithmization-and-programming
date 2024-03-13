#include "movingrect.h"

movingRect::movingRect()
{

}
movingRect::~movingRect()
{

}

void movingRect::moveDown()
{
    this->moveBy(0, 15);
}

void movingRect::moveLeft()
{
    this->moveBy(-15, 0);
}

void movingRect::moveRight()
{
    this->moveBy(15, 0);
}

void movingRect::moveUp()
{
    this->moveBy(0, -15);
}

void movingRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    QBrush brush(Qt::blue);
    painter->setBrush(brush);

    painter->drawRect(100,50,150,25);
}

QRectF movingRect::boundingRect() const
{
    return(QRectF(0,0,800,600));
}
