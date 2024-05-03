#include "triangle.h"

Triangle::Triangle()
{

}

void Triangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){

    Q_UNUSED(option);
    Q_UNUSED(widget);

    qreal side1 = valueA;
    qreal side2 = valueB;
    qreal side3 = valueC;

    x1 = 0;
    y1 = 0;
    x2 = x1 + side1;
    y2 = y1;
    x3 = x1 + (side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1);
    y3 = y1 + sqrt(side3 * side3 - pow((side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1), 2));

    centerX = (x1 + x2 + x3) / 3;
    centerY = (y1 + y2 + y3) / 3;

    center = {centerX, centerY};


    QPolygon triangle;
    triangle << QPoint(x1, y1)<< QPoint(x2, y2)  << QPoint(x3, y3);

    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    painter->drawPolygon(triangle);
}
void Triangle::updateSizeTriangleA(double arg1){

    valueA=arg1;
}
void Triangle::updateSizeTriangleB(double arg1){
    valueB=arg1;

}
void Triangle::updateSizeTriangleC(double arg1){
    valueC=arg1;

}
float Triangle::area()
{
    return this->getScale() * this->getScale() * (size*size*sqrt(3)) / 4;
}

float Triangle::perimeter()
{
    return 3 * size * this->getScale();
}
