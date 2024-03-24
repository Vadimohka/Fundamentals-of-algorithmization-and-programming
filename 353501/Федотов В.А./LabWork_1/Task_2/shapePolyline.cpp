#include "shapePolyline.h"

ShapePolyline::ShapePolyline() {
    points.clear();
}

void ShapePolyline::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    shift = QPointF(shiftX, shiftY);
    // QPolygonF polygon;

    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(0, -300);

    shiftDetached = QPointF(lastShiftX, lastShiftY);

    painter->translate(shift);
    painter->rotate(rotation);
    painter->translate(-shift);

    QBrush fillBrush(Qt::white);
    painter->setBrush(fillBrush);

    for(auto point : points){
        point += QPointF(0, 300);
        if(detached)
        {
            // polygon << point * scale + shiftDetached;
            painter->drawEllipse(point * scale + shiftDetached, 5*scale, 5*scale);
        }
        else
        {
            // polygon << point * scale + shift;
            painter->drawEllipse(point * scale + shift, 5*scale, 5*scale);
        }
    }

    // painter->drawPolygon(polygon);
    painter->drawEllipse(shift, 1, 1);
}

qreal ShapePolyline::area()
{
    return 0;
}

qreal ShapePolyline::perimeter()
{
    return 0;
}

void ShapePolyline::getPoint(QPointF value)
{
    if(points.size() < 1500 )
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
    rotation = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    scale = 1;

    detached = false;
}
