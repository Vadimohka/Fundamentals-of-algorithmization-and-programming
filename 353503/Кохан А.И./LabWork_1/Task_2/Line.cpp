#include "Line.h"

Line::Line(QPointF point, QObject *parent) : Figure(point,parent)
{
    Q_UNUSED(point)
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));

    QPainterPath path;
    path.moveTo(getStartPoint());
    path.quadTo(getStartPoint(), getEndPoint());

    painter->drawPath(path);
}

qreal Line::getSFigure() const
{
    return 0;
}

qreal Line::getPFigure() const
{
    return 0;
}
