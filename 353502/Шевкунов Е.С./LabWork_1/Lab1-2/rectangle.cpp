#include "rectangle.h"


Rectangle::Rectangle(QWidget *parent)
    : Figure{parent}
{}

Rectangle::Rectangle(const QVector<QPoint> &pv, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure (parent)
{
    this->ID = ID;
    center = (pv.at(0) + pv.at(1)) / 2;
    this->setPos(center);

    points.push_back(pv.at(0) - center);
    points.push_back(pv.at(1) - center);

    a = qAbs(pv.at(0).x() - pv.at(1).x());
    b = qAbs(pv.at(0).y() - pv.at(1).y());

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;
}


//**********************************************


QPointF Rectangle::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Rectangle::getSquare()
{
    return a * b * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();
}

qreal Rectangle::getPerimeter()
{
    return (a + b) * 2 * this->QGraphicsItem::scale();
}


//**********************************************


QPair<int, int> Rectangle::getParameter()
{
    return QPair<int, int>(a, b);
}

void Rectangle::setParameter(QPair<int, int> input)
{
    a = input.first;
    b = input.second;
}


//**********************************************


QRectF Rectangle::boundingRect() const
{
    return QRectF(QPointF(-a / 2, - b / 2), QSizeF(a, b));
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawRect(QRectF(QPointF(-a / 2, - b / 2), QSizeF(a, b)));
}
