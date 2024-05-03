#include "rectangle.h"

rectangle::rectangle(QPointF point, QObject *parent) : shape(point,parent)
{}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 4/scaleFactor));

    Q_UNUSED(option);
    Q_UNUSED(widget);

    center = QPointF(qMin(getStartPoint().x(),getFinalPoint().x())+length/2,qMin(getStartPoint().y(),getFinalPoint().y())+width/2);
    perim = 2*(length+width)*scaleFactor;
    square = length*width*scaleFactor*scaleFactor;

    QPolygonF polygon;
    int startY = qMin(startPoint.y(),finalPoint.y());
    int endY = qMax(startPoint.y(),finalPoint.y());
    int startX = qMin(startPoint.x(),finalPoint.x());
    int endX = qMax(startPoint.x(),finalPoint.x());
    polygon << QPointF(startX,startY) << QPointF(startX,endY) << QPointF(endX,endY) << QPointF(endX,startY);

    painter->drawPolygon(polygon);

    /*painter->drawRect(qMin(getStartPoint().x(),getFinalPoint().x()),
                      qMin(getStartPoint().y(),getFinalPoint().y()),
                      length, width);*/
}
