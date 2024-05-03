#include "parallelogram.h"

Parallelogram::Parallelogram()
{

}

void Parallelogram::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QPolygon polygon;
    polygon << QPoint(-length / 2 + width * cos(angle * M_PI/180) / 2, -width * sin(angle * M_PI/180) / 2) << QPoint(-length / 2 - width * cos(angle * M_PI/180) / 2, width * sin(angle * M_PI/180) / 2) << QPoint(length / 2 - width * cos(angle * M_PI/180) / 2, width * sin(angle * M_PI/180) / 2) << QPoint(length / 2 + width * cos(angle * M_PI/180) / 2, -width * sin(angle * M_PI/180) / 2);
    painter->drawPolygon(polygon);
}

float Parallelogram::area()
{
  return this->getScale() * this->getScale() * length * width * sin(angle * M_PI/180);
}

void Parallelogram::setLength(int value)
{
    this->length = value;
    update();
}

void Parallelogram::setWidth(int value)
{
    this->width = value;
    update();
}

void Parallelogram::setAngle(int value)
{
    this->angle = value;
    update();
}

float Parallelogram::getLength()
{
    return this->length;
}

float Parallelogram::getWidth()
{
    return this->width;
}

float Parallelogram::getAngle()
{
    return this->angle;
}
