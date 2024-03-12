#include "triangle.h"

Triangle::Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygon polygon;
    polygon << QPoint(-length / 2, width * sin(angle * M_PI / 180) / 2) << QPoint(length / 2, width * sin(angle * M_PI / 180) / 2) << QPoint(-length / 2 + width * cos(angle * M_PI / 180), -width * sin(angle * M_PI / 180) / 2);
    for (auto &p : polygon)
    {
        center += p;
    }
    center.setX(center.x() / 3);
    center.setY(center.y() / 3);

    for (auto &p : polygon)
    {
        p -= center;
    }
    painter->drawPolygon(polygon);
}

float Triangle::area()
{
    return this->getScale() * this->getScale() * length * width * sin(angle * M_PI / 180) / 2;
}

float Triangle::perimeter()
{
    return this->getScale() * (length + width + sqrt(length * length + width * width - 2 * length * width * cos(angle * M_PI / 180)));
}

void Triangle::setLength(int value)
{
    this->length = value;
    update();
}

void Triangle::setWidth(int value)
{
    this->width = value;
    update();
}

void Triangle::setAngle(int value)
{
    this->angle = value;
    update();
}

float Triangle::getLength()
{
    return this->length;
}

float Triangle::getWidth()
{
    return this->width;
}

float Triangle::getAngle()
{
    return this->angle;
}
