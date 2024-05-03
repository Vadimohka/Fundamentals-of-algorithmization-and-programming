#include "romb.h"

Romb::Romb(QPointF point, QObject *parent) : Figure(point,parent)
{
    Q_UNUSED(point)
}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));
    //painter->setBrush(Qt::black);
    betweenPoint = sqrt((getEndPoint().x() - getStartPoint().x()) * (getEndPoint().x() - getStartPoint().x()) +
                        (getEndPoint().y() - getStartPoint().y()) * (getEndPoint().y() - getStartPoint().y()));

    pFigure = 4 * qMax(abs(getEndPoint().x() - getStartPoint().x()), abs(getEndPoint().y() - getStartPoint().y()));
    sFigure = qMax(abs(getEndPoint().x() - getStartPoint().x()), abs(getEndPoint().y() - getStartPoint().y())) *
              qMax(abs(getEndPoint().x() - getStartPoint().x()), abs(getEndPoint().y() - getStartPoint().y())) * 0.1;

    QPolygonF polygon;

    polygon << QPointF(getStartPoint().x() + (getEndPoint().x() > getStartPoint().x() ? + 1 : - 1)*
                                              abs((getEndPoint().x() - getStartPoint().x())/2), getStartPoint().y())
            << QPointF(getEndPoint().x(), getStartPoint().y() + (getEndPoint().y() > getStartPoint().y() ? + 1 : - 1)*
                                                              abs((getEndPoint().y() - getStartPoint().y())/2))
            << QPointF(getStartPoint().x() + (getEndPoint().x() > getStartPoint().x() ? + 1 : - 1)*
                                              abs((getEndPoint().x() - getStartPoint().x())/2), getEndPoint().y())
            << QPointF(getStartPoint().x(), getStartPoint().y() + (getEndPoint().y() > getStartPoint().y() ? + 1 : - 1)*
                                                                abs((getEndPoint().y() - getStartPoint().y())/2));

    painter->drawPolygon(polygon);
}

qreal Romb::getSFigure() const
{
    return sFigure;
}

qreal Romb::getPFigure() const
{
    return pFigure;
}
