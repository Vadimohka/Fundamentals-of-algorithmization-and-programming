#include "hanoibrick.h"

HanoiBrick::HanoiBrick()
{
}

QRectF HanoiBrick::boundingRect() const
{
    return QRectF(_x, _y, _w, _h);
}

void HanoiBrick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Задаем цвет и стиль кисти
    QBrush brush(Qt::blue);

    // Задаем цвет и стиль пера
    QPen pen(Qt::white);
    pen.setWidth(1);

    painter->setBrush(brush);
    painter->setPen(pen);

    // Рисуем прямоугольник
    painter->drawRect(_x, _y, _w, _h);
}

void HanoiBrick::setParams(const int x, const int y, int width, int height)
{
    _x = x;
    _y = y;
    _w = width;
    _h = height;
}

void HanoiBrick::setParams(int i)
{
    scale = scale - 0.05*i;
    _w = 130 * scale;
    _h = 30;
    _y = 270 - _h*i;
    _x = 110 - _w;
    _w -= _x;
}


