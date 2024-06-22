#include "hexagon.h"


Hexagon::Hexagon(QWidget *parent)
    : Figure{parent}
{}

Hexagon::Hexagon(const QVector<QPoint> &pv, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure (parent)
{
    this->ID = ID;
    center = (pv.at(0) + pv.at(1)) / 2;
    this->setPos(center);

    radius = dist(pv.at(0), pv.at(1));

    qreal x, y;
    for (int i = 0; i < 6; ++i)
    {
        x = radius * qCos(qDegreesToRadians(60.0 * i - 30.0));
        y = radius * qSin(qDegreesToRadians(60.0 * i - 30.0));
        points.push_back(QPointF(x, y));
    }

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;
}


//**********************************************


QPointF Hexagon::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Hexagon::getSquare()
{
    return 6 * 1.5 * qSqrt(2) * radius * radius * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();
}

qreal Hexagon::getPerimeter()
{
    return 6 * radius * this->QGraphicsItem::scale();
}


//**********************************************


QPair<int, int> Hexagon::getParameter()
{
    return QPair<int, int>(radius, 0);
}

void Hexagon::setParameter(QPair<int, int> input)
{
    radius = input.first;

    points.clear();

    qreal x, y;
    for (int i = 0; i < 6; ++i)
    {
        x = radius * qCos(qDegreesToRadians(60.0 * i - 30.0));
        y = radius * qSin(qDegreesToRadians(60.0 * i - 30.0));
        points.push_back(QPointF(x, y));
    }
}


//**********************************************


QRectF Hexagon::boundingRect() const
{
    return QRectF(QPointF(-radius, -radius), QSizeF(2 * radius, 2 * radius));
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawPolygon(points.data(), 6);
}
