#include "hexagon.h"

hexagon::hexagon(QPointF point, QObject *parent) : shape(point,parent)
{}

void hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(color, 4/scaleFactor));


    center = QPointF(qMin(getStartPoint().x(),getFinalPoint().x())+length/2,qMin(getStartPoint().y(),getFinalPoint().y())+width/2);
    /*perim = 2*(length+width);
    square = length*width;*/

    QPolygonF polygon;
    int startY = qMin(startPoint.y(),finalPoint.y());
    int endY = qMax(startPoint.y(),finalPoint.y());
    int startX = qMin(startPoint.x(),finalPoint.x());
    int endX = qMax(startPoint.x(),finalPoint.x());
    perim = length+sqrtf(length*length/4+width*width)*2*scaleFactor;
    square = (endX-startX)*(endY-startY)*2/3*scaleFactor*scaleFactor;

    polygon << QPointF(endX-length/4,startY) << QPointF(startX+length/4,startY) << QPointF(startX,startY+width/2)
            << QPointF(startX+length/4,endY) << QPointF(endX-length/4,endY) << QPointF(endX,startY+width/2);

    painter->drawPolygon(polygon);
}
