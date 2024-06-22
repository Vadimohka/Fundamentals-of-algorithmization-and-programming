#include "triangle.h"


Triangle::Triangle(QWidget *parent)
    : Figure{parent}
{}

Triangle::Triangle(const QVector<QPoint> &pv, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure (parent)
{
    this->ID = ID;
    center = center_tr(pv.at(0), pv.at(1), pv.at(2));
    this->setPos(center);

    points.push_back(pv.at(0) - center);
    points.push_back(pv.at(1) - center);
    points.push_back(pv.at(2) - center);

    triangleSquare(points.at(0), points.at(1), points.at(2));

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;
}


//**********************************************


QPointF Triangle::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Triangle::getSquare()
{
    return triangleSquare(points.at(0), points.at(1), points.at(2))
           * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();
}

qreal Triangle::getPerimeter()
{
    return (dist(points.at(0), points.at(1)) +
            dist(points.at(0), points.at(2)) +
            dist(points.at(2), points.at(1))) * this->QGraphicsItem::scale();
}


//**********************************************


QPair<int, int> Triangle::getParameter()
{
    return QPair<int, int>(points.at(2).x(), points.at(2).y());
}

void Triangle::setParameter(QPair<int, int> input)
{
    points[2].rx() = input.first;
    points[2].ry() = input.second;

    //this->move(-center_tr(points.at(0), points.at(1), points.at(2)));
    this->setPos(this->QGraphicsItem::pos() + center_tr(points.at(0), points.at(1), points.at(2)));

    QPointF t = points.at(0);
    points[0].rx() = points[0].x() - center_tr(points.at(0), points.at(1), points.at(2)).x();
    points[0].ry() = points[0].y() - center_tr(points.at(0), points.at(1), points.at(2)).y();
    points[1].rx() = points[1].x() - center_tr(t, points.at(1), points.at(2)).x();
    points[1].ry() = points[1].y() - center_tr(t, points.at(1), points.at(2)).y();
}


//**********************************************


QRectF Triangle::boundingRect() const
{
    QPointF tl(points.at(0)), br(points.at(1));

    for (auto now : points)
    {
        if (now.x() < tl.x())
        {
            tl.rx() = now.x();
        }
        else if (now.x() > br.x())
        {
            br.rx() = now.x();
        }

        if (now.y() < tl.y())
        {
            tl.ry() = now.y();
        }
        else if (now.y() > br.y())
        {
            br.ry() = now.y();
        }
    }

    return QRectF(tl, br);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawPolygon(points.data(), 3);
}
