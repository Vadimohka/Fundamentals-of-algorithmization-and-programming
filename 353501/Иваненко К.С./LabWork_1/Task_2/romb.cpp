#include "romb.h"
#include <QPainter>
 
Romb::Romb(QPointF point, QObject *parent) :
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
 
Romb::~Romb()
{
 
}
 
// Реализуем метод отрисовки
void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;
    if (is_drawing_first_time) {
        sideA = sqrt(pow((endPoint().x() - startPoint().x()) / 2, 2) + pow((endPoint().y() / 2 - startPoint().y()) / 2, 2)) * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1);
        angel = 2 * atan((abs(endPoint().y() - startPoint().y()) / 2) / (abs(endPoint().x() - startPoint().x()) / 2)) * 180 / M_PI;

        polygon << QPointF(((startPoint().x() + endPoint().x()) / 2 - rotationX) * scale, (startPoint().y() - rotationY) * scale)
            << QPointF((endPoint().x() - rotationX) * scale, ((startPoint().y() + endPoint().y()) / 2 - rotationY) * scale)
            << QPointF(((startPoint().x() + endPoint().x()) / 2 - rotationX) * scale, (endPoint().y() - rotationY) * scale)
            << QPointF((startPoint().x() - rotationX) * scale, ((startPoint().y() + endPoint().y()) / 2 - rotationY) * scale);

        center = (startPoint() + endPoint()) / 2;
        area = abs((endPoint().x() - startPoint().x()) * (endPoint().x() - startPoint().x()) / 2);

    } else
    {   
        polygon << QPointF((startPoint().x() + sideA * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1) * cos(angel / 2 / 180 * M_PI) - rotationX) * scale, (startPoint().y() - rotationY) * scale)
            << QPointF((startPoint().x() + sideA * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1) * cos(angel / 2 / 180 * M_PI) * 2 - rotationX) * scale, (startPoint().y() + sideA * sin(angel / 2 / 180 * M_PI) - rotationY) * scale)
            << QPointF((startPoint().x() + sideA * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1) * cos(angel / 2 / 180 * M_PI) - rotationX) * scale, (startPoint().y() + sideA * sin(angel / 2 / 180 * M_PI) * 2 - rotationY) * scale)
            << QPointF((startPoint().x() - rotationX) * scale, (startPoint().y() + sideA * sin(angel / 2 / 180 * M_PI) - rotationY) * scale);
        center = QPoint(startPoint().x() + sideA * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1) * cos(angel / 2 / 180 * M_PI), startPoint().y() + sideA * sin(angel / 2 / 180 * M_PI));
        area = sideA * cos(angel / 2 / 180 * M_PI) * sideA * sin(angel / 2 / 180 * M_PI) * 2;
    }
 
    painter->setPen(QPen(Qt::red, 5));
    painter->drawPoint(rotationX, rotationY);

    painter->save();
    painter->translate(rotationX, rotationY);
    painter->rotate(rotation);
    painter->setPen(QPen(Qt::green, 5));
    painter->drawPoint((center - QPoint(rotationX, rotationY)) * scale);
    painter->setPen(QPen(Qt::gray, 2));
    painter->drawPolygon(polygon);
    painter->restore();

    perimeter = abs(sideA) * 4;
 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}