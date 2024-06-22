#include "rhombus.h"


Rhombus::Rhombus(QWidget *parent)
    : Figure(parent)
{

}

Rhombus::Rhombus(const QVector<QPoint> &pv, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure(parent)
{
    this->ID = ID;
    center = (pv.at(0) + pv.at(1)) / 2;
    this->setPos(center);

    a = qAbs(pv.at(0).x() - pv.at(1).x());
    b = qAbs(pv.at(0).y() - pv.at(1).y());

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;

    points << QPointF(-a /2, 0);
    points << QPointF(0, b / 2);
    points << QPointF(a / 2, 0);
    points << QPointF(0, - b / 2);
}


//**********************************************


QPointF Rhombus::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Rhombus::getSquare()
{
    return a * b / 2 * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();
}

qreal Rhombus::getPerimeter()
{
    return qSqrt(a * a + b * b) * this->QGraphicsItem::scale();
}


//**********************************************


QPair<int, int> Rhombus::getParameter()
{
    return QPair<int, int>(a, b);
}

void Rhombus::setParameter(QPair<int, int> input)
{
    a = input.first;
    b = input.second;

    points.clear();

    points << QPointF(-a /2, 0);
    points << QPointF(0, b / 2);
    points << QPointF(a / 2, 0);
    points << QPointF(0, - b / 2);
}


//**********************************************


QRectF Rhombus::boundingRect() const
{
    return QRectF(QPointF(-a / 2, -b / 2), QSizeF(a, b));
}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawPolygon(points.data(), 4);
}
