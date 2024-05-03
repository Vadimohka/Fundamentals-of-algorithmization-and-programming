#include "rhombus.h"

Rhombus::Rhombus(QVector<QPointF> temp, QGraphicsObject *parent) : Figure(parent)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        points->append(temp[i]);
    }

    CorrectCorners(points->at(0), points->at(1));

    center.setX(top_left.x() + x_side / 2);
    center.setY(top_left.y() + y_side / 2);

    side = pow((y_side / 2), 2) + pow((x_side / 2), 2);

    perim = 4 * side;

    square = 0.5 * y_side * x_side;

    setTransformOriginPoint(center);

    points->append(QPoint(top_left.x() + x_side / 2, top_left.y()));
    points->append(QPoint(bottom_right.x(), bottom_right.y() - y_side / 2));
    points->append(QPoint(bottom_right.x() - x_side / 2, bottom_right.y()));
    points->append(QPoint(top_left.x(), top_left.y() + y_side / 2));
}

QRectF Rhombus::boundingRect() const
{
    return QRectF(top_left, bottom_right);
}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    pen.setCosmetic(true);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(brush);

    painter->drawPolygon(points->data() + 2, points->size() - 2);
}


