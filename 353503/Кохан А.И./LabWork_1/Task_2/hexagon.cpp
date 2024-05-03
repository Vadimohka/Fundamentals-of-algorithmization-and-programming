#include "hexagon.h"

Hexagon::Hexagon(QPointF point, QObject *parent) : Figure(point,parent)
{
    Q_UNUSED(point)
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));
    //painter->setBrush(Qt::black);
    betweenPoint = sqrt((getEndPoint().x() - getStartPoint().x()) * (getEndPoint().x() - getStartPoint().x()) +
                        (getEndPoint().y() - getStartPoint().y()) * (getEndPoint().y() - getStartPoint().y()));

    pFigure = 6 * betweenPoint;

    sFigure = 1.5 * betweenPoint * betweenPoint * sqrt(3);

    qreal side = qMax(qAbs(getEndPoint().x() - getStartPoint().x()), qAbs(getEndPoint().y() - getStartPoint().y()));

    QPolygonF hexagon;
    for (int i = 0; i < 6; ++i) {
        hexagon << QPointF(getStartPoint().x() + side * cos(2 * M_PI * i / 6), getStartPoint().y() + side * sin(2 * M_PI * i / 6));
    }

    painter->drawPolygon(hexagon);
}

QRectF Hexagon::boundingRect() const
{
    qreal minX = std::numeric_limits<qreal>::max();
    qreal minY = std::numeric_limits<qreal>::max();
    qreal maxX = std::numeric_limits<qreal>::min();
    qreal maxY = std::numeric_limits<qreal>::min();

    qreal side = qMax(qAbs(getEndPoint().x() - getStartPoint().x()), qAbs(getEndPoint().y() - getStartPoint().y()));

    for (int i = 0; i < 6; ++i) {
        qreal x = getStartPoint().x() + side * cos(2 * M_PI * i / 6);
        qreal y = getStartPoint().y() + side * sin(2 * M_PI * i / 6);

        minX = qMin(minX, x);
        minY = qMin(minY, y);
        maxX = qMax(maxX, x);
        maxY = qMax(maxY, y);
    }

    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

qreal Hexagon::getSFigure() const
{
    return sFigure;
}

qreal Hexagon::getPFigure() const
{
    return pFigure;
}


