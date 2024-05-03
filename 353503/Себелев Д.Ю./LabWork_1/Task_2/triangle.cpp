#include "triangle.h"

Triangle::Triangle(QVector<QPointF> temp, QGraphicsObject *parent) : Figure(parent)
{
    for (int i = 0; i < temp.size(); ++i)
    {
        points->append(temp[i]);
    }

    center.setX((points->at(0).x() + points->at(1).x() + points->at(2).x()) / 3);
    center.setY((points->at(0).y() + points->at(1).y() + points->at(2).y()) / 3);

    first_side = sqrt(pow(points->at(1).x() - points->at(0).x(), 2) + pow(points->at(1).y() - points->at(0).y(), 2));
    second_side = sqrt(pow(points->at(2).x() - points->at(1).x(), 2) + pow(points->at(2).y() - points->at(1).y(), 2));
    third_side = sqrt(pow(points->at(0).x() - points->at(2).x(), 2) + pow(points->at(0).y() - points->at(2).y(), 2));

    perim = first_side + second_side + third_side;

    square = sqrt(perim / 2 * (perim / 2 - first_side) * (perim / 2 - second_side) * (perim / 2 - third_side));

    setTransformOriginPoint(center);
}

QRectF Triangle::boundingRect() const
{
    QPointF top_left;
    QPointF bottom_right;


    top_left.setX(std::min(std::min(points->at(0).x(), points->at(1).x()), points->at(2).x()));
    top_left.setY(std::min(std::min(points->at(0).y(), points->at(1).y()), points->at(2).y()));

    bottom_right.setX(std::max(std::max(points->at(0).x(), points->at(1).x()), points->at(2).x()));
    bottom_right.setY(std::max(std::max(points->at(0).y(), points->at(1).y()), points->at(2).y()));

    return QRectF(top_left - QPointF(1, 1), bottom_right + QPointF(1, 1));
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //QBrush brush(Qt::gray);


    pen.setCosmetic(true);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawPolygon(points->data(), points->size());
    painter->drawEllipse(center, 3, 3);
}





