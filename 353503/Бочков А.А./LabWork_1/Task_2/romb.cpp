#include "romb.h"

romb::romb(QPointF point, QObject *parent) : shape(point,parent)
{}

void romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 4/scaleFactor));

    Q_UNUSED(option);
    Q_UNUSED(widget);

    center = QPointF(qMin(getStartPoint().x(),getFinalPoint().x())+length/2,qMin(getStartPoint().y(),getFinalPoint().y())+width/2);
    perim = 2*sqrtf(length*length+width*width)*scaleFactor;
    square = length*width/2*scaleFactor*scaleFactor;

    QPolygonF polygon;
    int startY = qMin(startPoint.y(),finalPoint.y());
    int endY = qMax(startPoint.y(),finalPoint.y());
    int startX = qMin(startPoint.x(),finalPoint.x());
    int endX = qMax(startPoint.x(),finalPoint.x());
    polygon << QPointF(startX+length/2,startY) << QPointF(startX,startY+width/2) << QPointF(startX+length/2,endY) << QPointF(endX,startY+width/2);

    painter->drawPolygon(polygon);
}
