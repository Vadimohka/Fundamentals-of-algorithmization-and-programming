#include "triangle.h"

Triangle::Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygon polygon;
    painter->setBrush(QBrush(QColor(0,255,255)));
    polygon << QPoint(-40,20 * sqrt(3)) << QPoint(0,-20 * sqrt(3)) << QPoint(40,20 * sqrt(3));
    painter->drawPolygon(polygon);
}

float Triangle::area()
{
    return this->getScale() * this->getScale() * (size*size*sqrt(3)) / 4; //формула площади равностороннего треугольника
}

float Triangle::perimeter()
{
    return 3 * size * this->getScale(); //getScale() для изменения периметра и площади с увеличением/уменьшением размера фигуры
}
