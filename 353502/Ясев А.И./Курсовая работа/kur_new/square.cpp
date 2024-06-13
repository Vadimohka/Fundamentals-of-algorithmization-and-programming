#include "square.h"

Square::Direction Square::getOpposite(Direction dir)
{
    if(dir == LEFT)
        return RIGHT;
    if(dir == RIGHT)
        return LEFT;
    if(dir == UP)
        return DOWN;
    if(dir == DOWN)
        return UP;
    return NONE;
}

Square::Square(qint8 x, qint8 y, QGraphicsObject *parent) : QGraphicsObject(parent) {
    this->setPos(20+40*x, 20+40*y);
}

Square::~Square(){}

Square::Cell Square::getCell()
{
    return Cell((qRound(x()))/40, (qRound(y()))/40);
}

QRectF Square::boundingRect() const
{
    return QRectF(-20,-20,40,40);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(this->boundingRect(), this->pixmap, QRectF(0,0,this->boundingRect().x(),this->boundingRect().y()));
}


