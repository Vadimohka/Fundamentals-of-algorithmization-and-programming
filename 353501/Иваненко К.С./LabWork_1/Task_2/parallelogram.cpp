#include "parallelogram.h"
#include <QPainter>
 
Parallelogram::Parallelogram(QPointF point, QObject *parent) :
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
 
Parallelogram::~Parallelogram()
{
 
}

// Реализуем метод отрисовки
void Parallelogram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;
    if (is_drawing_first_time) {
    sideA = endPoint().x() - startPoint().x();
    sideB = sqrt(pow(endPoint().y() - startPoint().y(), 2) + pow(sideA / 3, 2)) * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1);
    }
    // sideB(y) = sqrt(pow(sideB, 2) - pow(sideA / 3, 2)) * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1);
    center = QPointF(startPoint().x() + sideA / 2, startPoint().y() + sqrt(pow(sideB, 2) - pow(sideA / 3, 2)) * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1) / 2);
 
    polygon << QPointF((startPoint().x() - rotationX) * scale, (startPoint().y() - rotationY) * scale)
            << QPointF((startPoint().x() + sideA * 2/3 - rotationX) * scale, (startPoint().y() - rotationY) * scale)
            << QPointF((startPoint().x() + sideA - rotationX) * scale, (startPoint().y() + sqrt(pow(sideB, 2) - pow(sideA / 3, 2)) * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1) - rotationY) * scale)
            << QPointF((startPoint().x() + sideA * 1/3 - rotationX) * scale, (startPoint().y() + sqrt(pow(sideB, 2) - pow(sideA / 3, 2)) * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1) - rotationY) * scale);
            

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

    area = abs(sideA) * abs(sqrt(pow(sideB, 2) - pow(sideA / 3, 2)) * ((endPoint().y() - startPoint().y() < 0) ? -1 : 1)) * 2/3;
    perimeter = (abs(sideA) * 2/3 + abs(sideB)) * 2;

 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

