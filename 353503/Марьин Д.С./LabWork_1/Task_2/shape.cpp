#include "shape.h"

Shape::Shape(QObject *parent):QGraphicsObject()
{
    Q_UNUSED(parent);
    setFlags(QGraphicsItem::ItemIsMovable);
}
void Shape::mousePressing(QPointF p)
{
    mouse_Press = p;
    mouse_Now = p;
}

QColor Shape::getColor()
{
    return color;
}

void Shape::setColor(QColor color)
{
    this->color = color;
}

QBrush Shape::getBrush()
{
    return brush;
}

void Shape::setBrush(QBrush b)
{
    this->brush = b;
}
void Shape::setPoints(QVector<QPointF> p)
{ Q_UNUSED(p)}

QPointF Shape::get_Center()
{
    return center;
}

void Shape::set_Center(QVector<QPointF> p)
{
    qreal c_x = 0;
    qreal c_y = 0;
    for(auto coord : p)
    {
        c_x += coord.x();
        c_y += coord.y();
    }
    c_x /= p.size();
    c_y /= p.size();
    center  = QPointF(c_x,c_y);
}

void Shape::set_Scale(qreal s)
{
    scale = s;
}

qreal Shape::get_Scale()
{
    return scale;
}
