#include "polyline.h"

ShapePolyline::ShapePolyline() {
    points.clear();
}

void ShapePolyline::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    shift = QPointF(shiftX, shiftY);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(0, 0);

    shiftDetached = QPointF(lastShiftX, lastShiftY);

    painter->translate(shift);
    painter->rotate(rot);
    painter->translate(-shift);

    QBrush fillBrush(Qt::black);
    painter->setBrush(fillBrush);

    for(auto point : points){
        point += QPointF(0, 0);
        if(detached)
        {
            painter->drawEllipse(point * sc + shiftDetached, 5*sc, 5*sc);
        }
        else
        {
            painter->drawEllipse(point * sc + shift, 5*sc, 5*sc);
        }
    }

    painter->drawEllipse(shift, 1, 1);
}

float ShapePolyline::area()
{
    return 0;
}

float ShapePolyline::perim()
{
    return 0;
}

void ShapePolyline::getPoint(QPointF value)
{
    if(points.size() < 3000 )
    {
        point = value;
        points.append(point);
    }
}

void ShapePolyline::clear()
{
    points.clear();

    shiftX = 0;
    shiftY = 0;
    rot = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    sc = 1;

    detached = false;
}
