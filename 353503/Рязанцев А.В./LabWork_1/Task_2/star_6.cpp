#include "star_6.h"

Star_6::Star_6(QPointF point) : Shape(point){}

void Star_6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal side = qMax(qAbs(GetEndPoint().x() - GetStarterPoint().x()), qAbs(GetEndPoint().y() - GetStarterPoint().y()));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    square = 1.5 * sqrt((width * width) + (heigh * heigh)) * sqrt(3);
    perimetr =6 * sqrt((width * width) + (heigh * heigh));

    QPolygonF star;
    for (int i = 0; i < 12; ++i) {
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        star << QPointF(GetStarterPoint().x() + radius * cos(2 * 3.14 * i / 12 - 3.14/2),
                        GetStarterPoint().y() + radius * sin(2 * 3.14 * i / 12 - 3.14/2));
    }

    painter->drawPolygon(star);
}

QRectF Star_6::boundingRect() const
{
    qreal minX = 999999;
    qreal minY = 999999;
    qreal maxX = -999999;
    qreal maxY = -999999;

    qreal side = qMax(qAbs(GetEndPoint().x() - GetStarterPoint().x()), qAbs(GetEndPoint().y() - GetStarterPoint().y()));

    for (int i = 0; i < 12; ++i) {
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        qreal x = GetStarterPoint().x() + radius * cos(2 * 3.14 * i / 12 - 3.14/2);
        qreal y = GetStarterPoint().y() + radius * sin(2 * 3.14 * i / 12 - 3.14/2);

        minX = qMin(minX, x);
        minY = qMin(minY, y);
        maxX = qMax(maxX, x);
        maxY = qMax(maxY, y);
    }

    return QRectF(minX, minY, maxX - minX, maxY - minY);
}


qreal Star_6::GetSquare()
{
    return square;
}

qreal Star_6::GetPerimetr()
{
    return perimetr;
}

QPointF Star_6::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
