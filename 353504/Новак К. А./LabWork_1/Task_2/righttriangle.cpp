#include "righttriangle.h"

rightTriangle::rightTriangle(QPointF point, QObject *parent) : shape(point,parent)
{}

void rightTriangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 4/scaleFactor));

    Q_UNUSED(option);
    Q_UNUSED(widget);

    /*perim = ;
    square = ;*/


    perim = (length+width)*scaleFactor;
    square = length*width/2*scaleFactor*scaleFactor;

    QPolygonF polygon;
    /*int startY = qMin(startPoint.y(),finalPoint.y());
    int endY = qMax(startPoint.y(),finalPoint.y());
    int startX = qMin(startPoint.x(),finalPoint.x());
    int endX = qMax(startPoint.x(),finalPoint.x());*/
    center = (QPointF(startPoint)*2+finalPoint)/3;
    polygon << startPoint << QPointF(startPoint.x(),finalPoint.y()) << QPointF(finalPoint.x(),startPoint.y());

    painter->drawPolygon(polygon);
}
