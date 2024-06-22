#include "square.h"


Square::Square(QWidget *parent)
    : Figure{parent}
{}

Square::Square(const QVector<QPoint> &pv, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure (parent)
{
    this->ID = ID;
    center = pv.at(0);
    this->setPos(center);

    side = qMax(qAbs(pv.at(0).x() - pv.at(1).x()), qAbs(pv.at(0).y() - pv.at(1).y())) * 2;

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;
}


//**********************************************


QPointF Square::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Square::getSquare()
{
    return side * side * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();
}

qreal Square::getPerimeter()
{
    return side * 4 * this->QGraphicsItem::scale();
}


//**********************************************

QPair<int, int> Square::getParameter()
{
    return QPair<int, int>(side, 0);
}

void Square::setParameter(QPair<int, int> input)
{
    side = input.first;
}

//**********************************************


QRectF Square::boundingRect() const
{
    return QRectF(QPointF(-side / 2 - 1, -side / 2 - 1), QSize(side + 2, side + 2));
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawRect(QRect(QPoint(-side / 2, - side / 2), QSize(side, side)));
}
