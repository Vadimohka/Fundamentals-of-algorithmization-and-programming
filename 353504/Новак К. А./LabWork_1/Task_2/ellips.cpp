#include "ellips.h"

ellips::ellips(QPointF point, QObject *parent) : shape(point,parent)
{}

void ellips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 4/scaleFactor));

    center = QPointF(qMin(getStartPoint().x(),getFinalPoint().x())+length/2,qMin(getStartPoint().y(),getFinalPoint().y())+width/2);
    perim = 4*(pi*length*width+qAbs(length-width))/(length+width)*scaleFactor;
    square = pi*length*width/4*scaleFactor*scaleFactor;

    //qDebug () << perim << scaleFactor;
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //setP(4*(pi*length*width+qAbs(length-width))/(length+width));
    //setS(pi*length*width/4);

    painter->drawEllipse(qMin(getStartPoint().x(),getFinalPoint().x()),
                         qMin(getStartPoint().y(),getFinalPoint().y()),
                         length, width);
}
