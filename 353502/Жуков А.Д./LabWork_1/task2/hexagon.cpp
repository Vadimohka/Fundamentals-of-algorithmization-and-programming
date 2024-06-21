#include "hexagon.h"

constexpr int H_SIDES = 6;
constexpr double ONE_AND_A_HALF = 1.5;
constexpr int THREE = 3;

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    int betweenPoint = sqrt((getEP().x() - getSP().x()) * (getEP().x() - getSP().x()) +
                        (getEP().y() - getSP().y()) * (getEP().y() - getSP().y()));

    setPerimeter(H_SIDES * betweenPoint);

    setArea(ONE_AND_A_HALF * pow(betweenPoint, 2) * sqrt(THREE));

    qreal side = qMax(qAbs(getEP().x() - getSP().x()), qAbs(getEP().y() - getSP().y()));

    QPolygonF hexagon;
    for (int i = 0; i < H_SIDES; ++i) {
        hexagon << QPointF(getSP().x() + side * cos(2 * M_PI * i / H_SIDES), getSP().y() + side * sin(2 * M_PI * i / H_SIDES));
    }

    painter->drawPolygon(hexagon);
}

QRectF Hexagon::boundingRect() const
{
    qreal minX = std::numeric_limits<qreal>::max();
    qreal minY = std::numeric_limits<qreal>::max();
    qreal maxX = std::numeric_limits<qreal>::min();
    qreal maxY = std::numeric_limits<qreal>::min();

    qreal side = qMax(qAbs(getEP().x() - getSP().x()), qAbs(getEP().y() - getSP().y()));

    for (int i = 0; i < H_SIDES; ++i) {
        qreal x = getSP().x() + side * cos(2 * M_PI * i / H_SIDES);
        qreal y = getSP().y() + side * sin(2 * M_PI * i / H_SIDES);

        minX = qMin(minX, x);
        minY = qMin(minY, y);
        maxX = qMax(maxX, x);
        maxY = qMax(maxY, y);
    }

    return {QRectF(minX, minY, maxX - minX, maxY - minY)};
}
