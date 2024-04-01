#include "star_eight.h"

Star_Eight::Star_Eight(QPointF point, QObject *parent) : Figure(point, parent)
{
    Q_UNUSED(point);
}

void Star_Eight::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    for (int i = 0; i < 16; i++)
    {
        qreal angle = 2 * M_PI * i / 16;
        qreal radius = (i%2 == 0) ?  a : a/2;;

        qreal x = startPoint().x() + radius*qCos(angle);
        qreal y = startPoint().y() + radius*qSin(angle);

        points << QPointF(x, y);
    }


    X = startPoint().x();
    Y = startPoint().y();


    S = 0;
    P = 0;

    for (int i = 0; i < 16; i++){
        int nextIndex = (i + 1) % 16;
        S += points[i].x() * points[nextIndex].y() - points[nextIndex].x() * points[i].y();
    }

    S = abs(S)/2;

    for (int i = 0; i < 16; i++){
        int nextIndex = (i + 1) % 16;
        P += sqrt((points[i].x()-points[nextIndex].x())*(points[i].x()-points[nextIndex].x()) + (points[i].y()-points[nextIndex].y())*(points[i].y()-points[nextIndex].y()));
    }

    QPolygonF polygon(points);

    painter->drawPolygon(polygon);

    Q_UNUSED(option);
    Q_UNUSED(widget);
    m_shape = QPainterPath();
    m_shape.addPolygon(polygon);
        points.clear();
}
