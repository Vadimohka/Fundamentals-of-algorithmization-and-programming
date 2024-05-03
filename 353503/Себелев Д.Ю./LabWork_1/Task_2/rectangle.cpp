#include "rectangle.h"

Rectangle::Rectangle(QVector<QPointF> temp, QGraphicsObject *parent) : Figure(parent)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        points->append(temp[i]);
    }

    CorrectCorners(points->at(0), points->at(1));


    center.setX(top_left.x() + 0.5 * x_side);
    center.setY(top_left.y() + 0.5 * y_side);


    perim = 2 * (x_side + y_side);

    square = x_side * y_side;

    setTransformOriginPoint(center);
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(top_left, bottom_right);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    pen.setCosmetic(true);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());
}

