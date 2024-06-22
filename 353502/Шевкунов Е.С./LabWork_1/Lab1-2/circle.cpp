#include "circle.h"


Circle::Circle(QWidget *parent)
    : Figure{parent}
{}

Circle::Circle(const QVector<QPoint>& pv, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure{parent}
{
    this->ID = ID;
    this->setPos(pv.at(0));
    radius = dist(pv.at(0), pv.at(1));

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;
}



QPointF Circle::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Circle::getSquare()
{
    return PI * radius * radius * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();
}

qreal Circle::getPerimeter()
{
    return PI * 2 * radius * this->QGraphicsItem::scale();
}



QPair<int, int> Circle::getParameter()
{
    return QPair<int, int>(radius, 0);
}

void Circle::setParameter(QPair<int, int> input)
{
    radius = input.first;
}



QRectF Circle::boundingRect() const
{
    return QRectF(QPointF(-radius - 1, -radius - 1), QSize(2 * radius + 2, 2 * radius + 2));
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawEllipse(QRect(QPoint(-radius, - radius), QSize(2 * radius, 2 * radius)));
}
