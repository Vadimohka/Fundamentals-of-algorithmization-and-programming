#include "ellipse.h"


Ellipse::Ellipse(QWidget *parent)
    : Figure{parent}
{}

Ellipse::Ellipse(const QVector<QPoint> &pv, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure (parent)
{
    this->ID = ID;
    center = (pv.at(0) + pv.at(1)) / 2;
    this->setPos(center);

    a = qAbs(pv.at(0).x() - pv.at(1).x()) / 2;
    b = qAbs(pv.at(0).y() - pv.at(1).y()) / 2;

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;
}


//**********************************************


QPointF Ellipse::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Ellipse::getSquare()
{
    return M_PI * a * b * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();

}

qreal Ellipse::getPerimeter()
{
    return 2 * PI * qSqrt((a * a + b * b) / 2) * this->QGraphicsItem::scale();
}


//**********************************************


QPair<int, int> Ellipse::getParameter()
{
    return QPair<int, int>(a, b);
}

void Ellipse::setParameter(QPair<int, int> input)
{
    a = input.first;
    b = input.second;
}


//**********************************************


QRectF Ellipse::boundingRect() const
{
    return QRectF(-a - 1, -b - 1, 2 * a + 1, 2 * b + 1);
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawEllipse(-a, -b, 2 * a, 2 * b);
}
