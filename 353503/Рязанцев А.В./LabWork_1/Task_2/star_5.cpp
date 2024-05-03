#include "star_5.h"
Star_5::Star_5(QPointF point) : Shape(point){}

QRectF Star_5::boundingRect() const
{
    qreal minX = 999999;
    qreal minY = 999999;
    qreal maxX = -999999;
    qreal maxY = -999999;

    qreal side = qMax(qAbs(GetEndPoint().x() - GetStarterPoint().x()), qAbs(GetEndPoint().y() - GetStarterPoint().y()));

    for (int i = 0; i < 10; ++i) {
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        qreal x = GetStarterPoint().x() + radius * cos(2 * 3.14 * i / 10 - 3.14/2);
        qreal y = GetStarterPoint().y() + radius * sin(2 * 3.14 * i / 10 - 3.14/2);

        minX = qMin(minX, x);
        minY = qMin(minY, y);
        maxX = qMax(maxX, x);
        maxY = qMax(maxY, y);
    }

    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

void Star_5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    square = 1.5 * sqrt((width * width) + (heigh * heigh)) * sqrt(3);
    perimetr = 6 * sqrt((width * width) + (heigh * heigh));

    qreal side = qMax(width, heigh);

    QPolygonF star;
    for (int i = 0; i < 10; ++i) {
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        star << QPointF(GetStarterPoint().x() + radius * cos(2 * 3.14 * i / 10 - 3.14/2),
                        GetStarterPoint().y() + radius * sin(2 * 3.14 * i / 10 - 3.14/2));
    }

    painter->drawPolygon(star);
}

qreal Star_5::GetSquare()
{
    return square;
}

qreal Star_5::GetPerimetr()
{
    return perimetr;
}

QPointF Star_5::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
