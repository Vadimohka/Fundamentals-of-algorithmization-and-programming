#include "star.h"

#include <QPainter>

Star::Star(QPointF point, QObject *parent) :
    Figure(point,parent) {}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QPen(Qt::black, 4));
    painter->setBrush(Qt::yellow);

    qreal side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));

    // Вычисляем центр звезды
    QPointF center = Figure::centerPoint();

    QPolygonF star;
    for (int i = 0; i < points; ++i) {
        // Добавляем точки для внешних и внутренних вершин звезды
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        star << QPointF(center.x() + radius * cos(2 * M_PI * i / points - M_PI/2),
                        center.y() + radius * sin(2 * M_PI * i / points - M_PI/2));
    }

    painter->drawPolygon(star);
}
