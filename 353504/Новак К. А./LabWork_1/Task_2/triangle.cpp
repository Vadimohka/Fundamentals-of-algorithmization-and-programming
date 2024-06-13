#include "triangle.h"

triangle::triangle(QPointF point, QObject *parent) : shape(point,parent)
{}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 4/scaleFactor));

    Q_UNUSED(option);
    Q_UNUSED(widget);


    perim = (length+2*(sqrtf(width*width+length*length/4)))*scaleFactor;
    square = length*width/2*scaleFactor*scaleFactor;

    QPolygonF polygon;
    /*int startY = qMin(startPoint.y(),finalPoint.y());
    int endY = qMax(startPoint.y(),finalPoint.y());*/
    int startX = qMin(startPoint.x(),finalPoint.x());
    int endX = qMax(startPoint.x(),finalPoint.x());
    center = (QPointF(startX+length/2,finalPoint.y())+QPointF(startX,startPoint.y())+QPointF(endX,startPoint.y()))/3;
    polygon << QPointF(startX+length/2,finalPoint.y()) << QPointF(startX,startPoint.y()) << QPointF(endX,startPoint.y());

    painter->drawPolygon(polygon);
}
