#include "Figure.h"


void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

}

Figure::Figure()
{

}

QRectF Figure::boundingRect() const
{
    return QRectF(-750,-750,1500,1500);
}


QPoint Figure::getCenter()
{

}

void Figure::moveRight() {
    this->setPos(this->x() + 2, this->y());
}

void Figure::moveLeft() {
    this->setPos(this->x() - 2, this->y());
}

void Figure::moveUp()
{
    this->setPos(this->x(), this->y() - 2);
}

void Figure::moveDown()
{
    this->setPos(this->x(), this->y() + 2);
}

void Figure::rotateRight()
{
    this->setRotation(rotation()+1);
}


void Figure::rotateLeft()
{
    this->setRotation(rotation()-1);
}

void Figure::upScale()
{
    scale = scale*1.01;
    this->setScale(scale);

}

void Figure::setRotationCenter(QPointF center) {
    setTransformOriginPoint(center);
}

void Figure::downScale()
{
    scale = scale/1.01;
    this->setScale(scale);

}

float Figure::getScale() {
    return scale;
}


float Figure::findArea()
{
    return 0;
}

float Figure::findPerimeter()
{
    return 0;
}

void Figure::SBMoveX(int x)
{
    this->setPos(x, y());
}

void Figure::SBMoveY(int y)
{
    this->setPos(x(), y);
}

