#include "square.h"
#include <QPainter>
 
Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
    rotation = 0;
    rotationX = 0;
    rotationY = 0;
    area = 0;
    center = QPoint(0,0);
}
 
Square::~Square()
{
 
}

// Реализуем метод отрисовки
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;

    center = (startPoint() + endPoint()) / 2;
 
    polygon << QPointF(startPoint().x() - rotationX, startPoint().y() - rotationY)
            << QPointF(endPoint().x() - rotationX, startPoint().y() - rotationY)
            << QPointF(endPoint().x() - rotationX, endPoint().y() - rotationY)
            << QPointF(startPoint().x() - rotationX, endPoint().y() - rotationY);
            

    painter->setPen(QPen(Qt::red, 5));
    painter->drawPoint(rotationX, rotationY);

    painter->save();
    painter->translate(rotationX, rotationY);
    painter->rotate(rotation);
    painter->setPen(QPen(Qt::green, 5));
    painter->drawPoint(center - QPoint(rotationX, rotationY));
    painter->setPen(QPen(Qt::white, 2));
    painter->drawPolygon(polygon);
    painter->restore();

    area = abs(startPoint().x() - endPoint().x()) * abs(startPoint().y() - endPoint().y());

 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

