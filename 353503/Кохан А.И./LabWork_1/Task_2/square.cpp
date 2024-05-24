#include "square.h"

Square::Square(QPointF point, QObject *parent) : Figure(point,parent)
{
    Q_UNUSED(point)
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));
    //painter->setBrush(Qt::black);

    qreal side = qMin(qAbs(getEndPoint().x() - getStartPoint().x()), qAbs(getEndPoint().y() - getStartPoint().y()));

    pFigure = 4 * side;
    sFigure = side * side;

    QRectF square(getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x(),
                getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y(),
                side, side);

    painter->drawRect(square);
}

QRectF Square::boundingRect() const
{
    qreal side = qMin(qAbs(getEndPoint().x() - getStartPoint().x()), qAbs(getEndPoint().y() - getStartPoint().y()));

    QRectF square(getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x(),
                  getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y(),
                  side, side);

    return square;
}

qreal Square::getSFigure() const
{
    return sFigure;
}

qreal Square::getPFigure() const
{
    return pFigure;
}
