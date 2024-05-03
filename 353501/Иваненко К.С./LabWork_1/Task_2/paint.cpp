#include "paint.h"
#include <QPainter>


Paint::Paint(QPointF point, QObject *parent) :
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

Paint::~Paint()
{

}

// Реализуем метод отрисовки
void Paint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->setPen(QPen(Qt::red, 5));
    painter->drawPoint(rotationX, rotationY);

    painter->save();
    painter->translate(rotationX, rotationY);
    painter->rotate(rotation);
    painter->setPen(QPen(Qt::gray, 2));
    for(QPointF p: points) {
        painter->drawEllipse((p.x() - 5 - rotationX) * scale, (p.y() - 5 - rotationY) * scale, 10, 10);
    }
    painter->restore();

    painter->setBrush(Qt::NoBrush);
    
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
