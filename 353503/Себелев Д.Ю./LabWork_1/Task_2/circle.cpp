#include "circle.h"

Circle::Circle(QVector<QPointF> temp, QGraphicsObject *parent) : Figure(parent)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        points->append(temp[i]);
    }

    center = points->at(0);
    setTransformOriginPoint(center);

    radius_on_x = abs(points->at(1).x() - points->at(0).x());
    radius_on_y = abs(points->at(1).y() - points->at(0).y());

    radius = sqrt((radius_on_x * radius_on_x) + (radius_on_y * radius_on_y));

    perim = 2 * M_PI * radius;

    square = M_PI * pow(radius, 2);
}

QRectF Circle::boundingRect() const
{
    QPointF top_left;
    QPointF bottom_right;



    top_left.setX(points->at(0).x() - radius);
    top_left.setY(points->at(0).y() - radius);

    bottom_right.setX(points->at(0).x() + radius);
    bottom_right.setY(points->at(0).y() + radius);

    return QRectF(top_left - QPointF(1, 1), bottom_right + QPointF(1, 1));
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    pen.setCosmetic(true);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(boundingRect());
}
