#include "ellipse.h"
#include <QPainter>
 
Ellipse::Ellipse(QPointF point, QObject *parent) :
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
 
Ellipse::~Ellipse()
{
 
}
 
// Реализуем метод отрисовки
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (is_drawing_first_time) {
    sideA = (endPoint().x() - startPoint().x()) * scale;
    sideB = (endPoint().y() - startPoint().y()) * scale;
    }
    
    center = QPointF(startPoint().x() + sideA / 2, startPoint().y() + sideB / 2);
 
    QRectF polygon((startPoint().x() - rotationX) * scale, (startPoint().y() - rotationY) * scale, sideA, sideB);

    // Нарисуйте эллипс внутри прямоугольника
    painter->setPen(QPen(Qt::red, 5));
    painter->drawPoint(rotationX, rotationY);

    painter->save();
    painter->translate(rotationX, rotationY);
    painter->rotate(rotation);
    painter->setPen(QPen(Qt::green, 5));
    painter->drawPoint((center - QPoint(rotationX, rotationY)) * scale);
    painter->setPen(QPen(Qt::gray, 2));
    painter->drawEllipse(polygon);
    painter->restore();

    area = abs(sideA / 2) * abs(sideB / 2) * M_PI;
    perimeter = 2 * M_PI * sqrt((sideA * sideA / 4 + sideB * sideB / 4) / 2);
    
 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}