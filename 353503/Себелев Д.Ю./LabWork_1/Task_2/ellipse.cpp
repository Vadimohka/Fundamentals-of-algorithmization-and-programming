#include "ellipse.h"

Ellipse::Ellipse(QVector<QPointF> temp, QGraphicsObject *parent) : Figure(parent)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        points->append(temp[i]);
    }

    CorrectCorners(points->at(0), points->at(1));

    x_side = abs(top_left.x() - bottom_right.x());
    y_side = abs(top_left.y() - bottom_right.y());

    center.setX(top_left.x() + x_side / 2);
    center.setY(top_left.y() + y_side / 2);

    perim = 4 * ((M_PI * (x_side / 2) * (y_side / 2) + pow(x_side/2 - y_side/2, 2)) / (x_side/2 + y_side/2));

    setTransformOriginPoint(center);
}

QRectF Ellipse::boundingRect() const
{
    return QRectF(top_left, bottom_right);
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    pen.setCosmetic(true);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(boundingRect());
}
