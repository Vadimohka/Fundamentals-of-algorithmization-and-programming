#include "star8.h"

Star8::Star8(QVector<QPointF> temp, QGraphicsObject *parent) : Figure(parent)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        points->append(temp[i]);
    }

    CorrectCorners(points->at(0), points->at(1));

    diag = sqrt((x_side * x_side) + (y_side * y_side));

    side = diag / sqrt(2);

    center.setX(top_left.x() + side / 2);
    center.setY(top_left.y() + side / 2);

    for (int i = 0; i < 16; ++i)
    {
        qreal radius = (i % 2 == 0) ? side / 2.0 : side / 4.0;
        points->append(QPointF(center.x() + radius * cos(2 * M_PI * i / 16 - M_PI/2),
                               center.y() + radius * sin(2 * M_PI * i / 16 - M_PI/2)));
    }

    base = abs(points->at(3).x() - points->at(17).x());

    tri_side = sqrt(pow(base / 2, 2) + pow(abs(points->at(2).y() - points->at(3).y()), 2));

    perim = 16 * tri_side;

    temp_perim = tri_side + base + side / 2;

    square = 16 * (sqrt(temp_perim / 2 * (temp_perim / 2 - tri_side) * (temp_perim / 2 - base) * abs(temp_perim / 2 - side / 2)));

    setTransformOriginPoint(center);
}

QRectF Star8::boundingRect() const
{
    return QRectF(top_left.x(), top_left.y(), side, side);
}

void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    pen.setCosmetic(true);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(brush);

    painter->drawEllipse(center, 3, 3);

    painter->drawPolygon(points->data() + 2, points->size() - 2);
}
