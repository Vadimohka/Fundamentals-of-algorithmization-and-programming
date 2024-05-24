#include "star6.h"

Star6::Star6(QPointF point, QObject *parent) : Figure(point,parent)
{
    Q_UNUSED(point)
}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

    QPolygonF star;
    for (int i = 0; i < 12; ++i) {
        // Добавляем точки для внешних и внутренних вершин звезды
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        star << QPointF(getStartPoint().x() + radius * cos(2 * M_PI * i / 12 - M_PI/2),
                        getStartPoint().y() + radius * sin(2 * M_PI * i / 12 - M_PI/2));
    }

    painter->drawPolygon(star);
}

QRectF Star6::boundingRect() const
{
    qreal minX = std::numeric_limits<qreal>::max();
    qreal minY = std::numeric_limits<qreal>::max();
    qreal maxX = std::numeric_limits<qreal>::min();
    qreal maxY = std::numeric_limits<qreal>::min();

    qreal side = qMax(qAbs(getEndPoint().x() - getStartPoint().x()), qAbs(getEndPoint().y() - getStartPoint().y()));

    for (int i = 0; i < 12; ++i) {
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        qreal x = getStartPoint().x() + radius * cos(2 * M_PI * i / 12 - M_PI/2);
        qreal y = getStartPoint().y() + radius * sin(2 * M_PI * i / 12 - M_PI/2);

        minX = qMin(minX, x);
        minY = qMin(minY, y);
        maxX = qMax(maxX, x);
        maxY = qMax(maxY, y);
    }

    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

qreal Star6::getSFigure() const
{
    return sFigure;
}

qreal Star6::getPFigure() const
{
    return pFigure;
}
