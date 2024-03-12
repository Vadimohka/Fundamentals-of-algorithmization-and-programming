#include "romb.h"
#include <QPainter>
 
Romb::Romb(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
    rotation = 0;
    rotationX = 0;
    rotationY = 0;
    area = 0;
    center = QPoint(0,0);
}
 
Romb::~Romb()
{
 
}
 
// Реализуем метод отрисовки
void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPolygonF polygon;

    center = (startPoint() + endPoint()) / 2;
 
    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1) * abs((endPoint().x() - startPoint().x())/2), startPoint().y())
            << QPointF(endPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1) * abs((endPoint().y() - startPoint().y())/2))
            << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1) * abs((endPoint().x() - startPoint().x())/2), endPoint().y())
            << QPointF(startPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1) * abs((endPoint().y() - startPoint().y())/2));
 
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
 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}