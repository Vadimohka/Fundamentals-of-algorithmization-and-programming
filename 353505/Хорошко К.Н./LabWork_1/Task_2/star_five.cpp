#include "star_five.h"

Star_Five::Star_Five(QPointF point, QObject *parent) : Figure(point, parent)
{
    Q_UNUSED(point);
}

void Star_Five::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    for (int i = 0; i < 10; i++)
    {
        qreal angle = 2 * M_PI * i / 10;
        qreal radius = (i%2 == 0) ? a : a/2;

        qreal x = startPoint().x() + radius*qCos(angle);
        qreal y = startPoint().y() + radius*qSin(angle);

        points << QPointF(x, y);
    }


    X = startPoint().x();
    Y = startPoint().y();


    S = 0;
    P = 0;

    for (int i = 0; i < 10; i++){
        int nextIndex = (i + 1) % 10;
        S += points[i].x() * points[nextIndex].y() - points[nextIndex].x() * points[i].y();
    }

    S = abs(S)/2;

    for (int i = 0; i < 10; i++){
        int nextIndex = (i + 1) % 10;
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
