#include "ellipse.h"
#include <QPainter>
 
Ellipse::Ellipse(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
    rotation = 0;
    rotationX = 0;
    rotationY = 0;
    area = 0;
    center = QPoint(0,0);
}
 
Ellipse::~Ellipse()
{
 
}
 
// Реализуем метод отрисовки
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    center = (startPoint() + endPoint()) / 2;
 
    QRectF polygon(startPoint().x(), startPoint().y(), endPoint().x() - startPoint().x(), endPoint().y() - startPoint().y());

    // Нарисуйте эллипс внутри прямоугольника
    painter->setPen(QPen(Qt::red, 5));
    painter->drawPoint(rotationX, rotationY);

    painter->save();
    painter->translate(rotationX, rotationY);
    painter->rotate(rotation);
    painter->setPen(QPen(Qt::green, 5));
    painter->drawPoint(center - QPoint(rotationX, rotationY));
    painter->setPen(QPen(Qt::white, 2));
    painter->drawEllipse(polygon);
    painter->restore();

    area = abs(startPoint().x() - endPoint().x()) * abs(startPoint().y() - endPoint().y());

    
 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}