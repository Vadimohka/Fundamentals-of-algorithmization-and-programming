#include "triangle90.h"

Triangle90::Triangle90(QPointF point, QObject *parent) : Figure(point,parent)
{
    Q_UNUSED(point)
}

void Triangle90::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));
    //painter->setBrush(Qt::black);
    betweenPoint = sqrt((getEndPoint().x() - getStartPoint().x()) * (getEndPoint().x() - getStartPoint().x()) +
                        (getEndPoint().y() - getStartPoint().y()) * (getEndPoint().y() - getStartPoint().y()));

    sFigure = abs(getEndPoint().x() - getStartPoint().x()) * abs(getEndPoint().y() - getStartPoint().y()) * 0.5;
    pFigure = abs(getEndPoint().x() - getStartPoint().x()) + abs(getEndPoint().y() - getStartPoint().y()) + betweenPoint;


    QPolygonF polygon;

    polygon << getStartPoint()
            << QPointF(getEndPoint().x(), getStartPoint().y())
            << QPointF(getStartPoint().x(), getEndPoint().y());

    painter->drawPolygon(polygon);
}

qreal Triangle90::getSFigure() const
{
    return sFigure;
}

qreal Triangle90::getPFigure() const
{
    return pFigure;
}
