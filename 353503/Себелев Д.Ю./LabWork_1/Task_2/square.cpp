#include "square.h"

Square::Square(QVector<QPointF> temp, QGraphicsObject *parent) : Figure(parent)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        points->append(temp[i]);
    }

    CorrectCorners(points->at(0), points->at(1));

    diag = sqrt((x_side * x_side) + (y_side * y_side));

    center.setX(0.5 * (diag / sqrt(2)) + top_left.x());
    center.setY(0.5 * (diag / sqrt(2)) + top_left.y());

    perim = 4 * diag / sqrt(2);

    square = 2 * diag / sqrt(2);

    setTransformOriginPoint(center);

}

QRectF Square::boundingRect() const
{

    return QRectF(top_left.x() - 1, top_left.y() - 1, diag / sqrt(2) + 1, diag / sqrt(2) + 1);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    pen.setCosmetic(true);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());
}
