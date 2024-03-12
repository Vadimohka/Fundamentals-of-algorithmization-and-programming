#include "basicshape.h"

BasicShape::BasicShape()
{

}

void BasicShape::setRadius(int value)
{
    this->radius = value;
    update();
}

void BasicShape::setRadiusA(int value)
{
    this->radiusA = value;
    update();
}

void BasicShape::setRadiusB(int value)
{
    this->radiusB = value;
    update();
}

void BasicShape::setSide(int value)
{
    this->side = value;
    update();
}

void BasicShape::setLength(int value)
{
    this->length = value;
    update();
}

void BasicShape::setWidth(int value)
{
    this->width = value;
    update();
}

void BasicShape::setAngle(int value)
{
    this->angle = value;
    update();
}

float BasicShape::getRadius()
{
    return this->radius;
}

float BasicShape::getRadiusA()
{
    return this->radiusA;
}

float BasicShape::getRadiusB()
{
    return this->radiusB;
}

float BasicShape::getSide()
{
    return this->side;
}

float BasicShape::getLength()
{
    return this->length;
}

float BasicShape::getWidth()
{
    return this->width;
}

float BasicShape::getAngle()
{
    return this->angle;
}

QRectF BasicShape::boundingRect() const
{
    return QRectF(-250,-250,500,500);
}

float BasicShape::getScale()
{
    return scale;
}

QPoint BasicShape::getCenter()
{
    return QPoint(this->pos().toPoint());
}

QPoint BasicShape::getOrigin()
{
    origin = QPoint(this->transformOriginPoint().toPoint());
    return origin;
}

void BasicShape::move_up()
{
    this->setPos(this->x(), this->y() - 2);
}

void BasicShape::move_down()
{
    this->setPos(this->x(), this->y() + 2);
}

void BasicShape::move_left()
{
    this->setPos(this->x() - 2, this->y());
}

void BasicShape::move_right()
{
    this->setPos(this->x() + 2, this->y());
}

void BasicShape::origin_move_up()
{
    this->setTransformOriginPoint(origin.x(), origin.y() - 2);
}

void BasicShape::origin_move_down()
{
    this->setTransformOriginPoint(origin.x(), origin.y() + 2);
}

void BasicShape::origin_move_left()
{
    this->setTransformOriginPoint(origin.x() - 2, origin.y());
}

void BasicShape::origin_move_right()
{
    this->setTransformOriginPoint(origin.x() + 2, origin.y());
}

void BasicShape::rotate_left()
{
    rotationAngle--;
    this->setRotation(rotationAngle);
}

void BasicShape::rotate_right()
{
    rotationAngle++;
    this->setRotation(rotationAngle);
}

void BasicShape::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}

void BasicShape::sizeUp()
{
    scale += 0.01;

    this->setScale(scale);
}

void BasicShape::sizeDown()
{
    scale -= 0.01;
    if(scale < 0)
    {
        scale=0.01;
    }

    this->setScale(scale);
}

void BasicShape::reset()
{
    scale = 1;
    rotationAngle = 0;
    this->setScale(scale);
    this->setRotation(rotationAngle);
    this->setPos(0, 0);
    this->setTransformOriginPoint(0, 0);
}

void BasicShape::mousePressing(QMouseEvent *me)
{
    mouseNow = me->pos();
    setPoints(me);
}

void BasicShape::mouseMoving(QMouseEvent *me)
{
    mouseNow = me->pos();
    setPoints(me);
}

float BasicShape::area()
{
    return 0;
}

float BasicShape::perimeter()
{
    return 0;
}

void BasicShape::setPoints(QMouseEvent *)
{

}
