#include "rotatingwheel.h"
#include <cmath>

RotatingWheel::RotatingWheel() : MovingCircle()
{

}

void RotatingWheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;
    QGraphicsPolygonItem poly;

    for(int i = 0, count = 16; i < count; ++i)
    {
        qreal angle = 2 * 3.14 * i / count;
        int xi = 200 * cos(angle);
        int yi = 200 * sin(angle);
        polygon << QPointF(xi, yi);
    }

    poly.setPolygon(polygon);
    painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter->drawPolygon(polygon);
    MovingCircle::paint(painter, option, widget);
}

void RotatingWheel::rotateLeft()
{
    setRotation(this->rotation() - 1);
    update();
}

void RotatingWheel::rotateRight()
{
    setRotation(this->rotation() + 1);
    update();
}
