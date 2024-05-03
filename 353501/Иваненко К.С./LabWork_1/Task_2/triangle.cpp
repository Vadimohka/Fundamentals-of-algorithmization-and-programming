#include "triangle.h"
#include <QPainter>
 
Triangle::Triangle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
    N = 0;
    scale = 1;
    rotation = 0;
    rotationX = 0;
    rotationY = 0;
    sideA = 0;
    sideB = 0;
    sideC = 0;
    area = 0;
    perimeter = 0;
    angel = 0;
    outerRadius = 0;
    innerRadius = 0;
    center = QPointF(0, 0);
    pointA = QPointF(0, 0);
    pointB = QPointF(0, 0);
    pointC = QPointF(0, 0);
    A_x = 0;
    A_y = 0;
    B_x = 0;
    B_y = 0;
    C_x = 0;
    C_y = 0;
    is_drawing_first_time = true;
}
 
Triangle::~Triangle()
{
 
}
 
// Реализуем метод отрисовки
void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    
 
    QPolygonF polygon;

    if (is_drawing_first_time) {
        pointA = QPointF(((startPoint().x() + endPoint().x()) / 2 - rotationX) * scale, (startPoint().y() - rotationY) * scale);
        pointB = QPointF((endPoint().x() - rotationX) * scale, (endPoint().y() - rotationY) * scale);
        pointC = QPointF((startPoint().x() - rotationX) * scale, (endPoint().y() - rotationY) * scale);

        A_x = pointA.x();
        A_y = pointA.y();
        B_x = pointB.x();
        B_y = pointB.y();
        C_x = pointC.x();
        C_y = pointC.y();
        center = QPoint((A_x + B_x + C_x) / 3, (A_y + B_y + C_y) / 3);
    } else
    {
        pointA = QPointF((A_x - rotationX) * scale, (A_y- rotationY) * scale);
        pointB = QPointF((B_x - rotationX) * scale, (B_y- rotationY) * scale);
        pointC = QPointF((C_x- rotationX) * scale, (C_y - rotationY) * scale);
        center = QPoint((A_x + B_x + C_x - 3 * rotationX) / 3, (A_y + B_y + C_y - 3 * rotationY) / 3) * scale;
    }

    sideA = std::sqrt(std::pow((pointB.x() - pointC.x()), 2) + std::pow((pointB.y() - pointC.y()), 2));
    sideB = std::sqrt(std::pow((pointA.x() - pointB.x()), 2) + std::pow((pointA.y() - pointB.y()), 2));
    sideC = std::sqrt(std::pow((pointA.x() - pointC.x()), 2) + std::pow((pointA.y() - pointC.y()), 2));


 
    polygon << pointA << pointB << pointC;
 

    painter->setPen(QPen(Qt::red, 5));
    painter->drawPoint(rotationX, rotationY);

    painter->save();
    painter->translate(rotationX, rotationY);
    painter->rotate(rotation);
    painter->setPen(QPen(Qt::green, 5));
    painter->drawPoint(center);
    painter->setPen(QPen(Qt::gray, 2));
    painter->drawPolygon(polygon);
    painter->restore();

    
    perimeter = sideA + sideB + sideC;
    N = perimeter / 2;
    area = sqrt(N * (N - sideA) * (N - sideB) * (N - sideC));

    Q_UNUSED(option)
    Q_UNUSED(widget)
}