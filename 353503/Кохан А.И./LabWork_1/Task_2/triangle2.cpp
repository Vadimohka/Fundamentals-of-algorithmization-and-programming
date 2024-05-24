#include "triangle2.h"

Triangle2::Triangle2(QPointF point, QObject *parent) : Figure(point,parent)
{
    Q_UNUSED(point)
}

void Triangle2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));
    //painter->setBrush(Qt::black);
    betweenPoint = sqrt((getEndPoint().x() - getStartPoint().x()) * (getEndPoint().x() - getStartPoint().x()) +
                        (getEndPoint().y() - getStartPoint().y()) * (getEndPoint().y() - getStartPoint().y()));

    pFigure = 6 * betweenPoint;
    sFigure = betweenPoint * betweenPoint * sqrt(3) * 0.25;

    QPolygonF polygon;

    polygon << QPointF(getStartPoint().x() + (getEndPoint().x() > getStartPoint().x() ? + 1 : - 1)*
                                              abs((getEndPoint().x() - getStartPoint().x())/2), getStartPoint().y())
            << QPointF((getEndPoint().x() > getStartPoint().x()) ? getEndPoint().x() : getStartPoint().x(),
                       getEndPoint().y())
            << QPointF((getEndPoint().x() > getStartPoint().x()) ? getStartPoint().x() : getEndPoint().x(),
                       getEndPoint().y());

    painter->drawPolygon(polygon);
}

qreal Triangle2::getSFigure() const
{
    return sFigure;
}

qreal Triangle2::getPFigure() const
{
    return pFigure;
}
