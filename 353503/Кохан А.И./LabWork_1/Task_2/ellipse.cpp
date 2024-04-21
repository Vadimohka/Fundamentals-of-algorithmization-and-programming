#include "ellipse.h"

Ellipse::Ellipse(QPointF point, QObject *parent) : Figure(point,parent) {}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));
    //painter->setBrush(Qt::black);
    betweenPoint = sqrt((getEndPoint().x() - getStartPoint().x()) * (getEndPoint().x() - getStartPoint().x()) +
                        (getEndPoint().y() - getStartPoint().y()) * (getEndPoint().y() - getStartPoint().y()));

    pFigure = 2 * M_PI * betweenPoint;
    sFigure = M_PI * betweenPoint * betweenPoint * 0.1;

    QRectF ellipse(getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x(),
                getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y(),
                qAbs(getEndPoint().x() - getStartPoint().x()),
                qAbs(getEndPoint().y() - getStartPoint().y()));

    painter->drawEllipse(ellipse);
}

qreal Ellipse::getSFigure() const
{
    return sFigure;
}

qreal Ellipse::getPFigure() const
{
    return pFigure;
}
