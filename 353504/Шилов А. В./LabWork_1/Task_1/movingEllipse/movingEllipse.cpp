//
// Created by darina on 3/3/24.
//

#include "movingEllipse.h"

#include <QWidget>
#include <QPainter>



bool inside(double x, double y)
{

    if((double)(-200 - x) * (-200 - x) + (double)(-125 - y) * (-125 - y) > 2500)
        return false;
    else
        return true;
}

movingEllipse::movingEllipse(qint32 x, qint32 y) {
    x_pos = x;
    y_pos = y;
    x_size = 50;
    y_size = 75;
    on_Scene = true;
}

QRectF movingEllipse::boundingRect() const{
    return {0, 0, 0, 0};
}

void movingEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(on_Scene)
    {
        painter->setBrush(Qt::magenta);
        painter->setPen(Qt::black);

        painter->drawEllipse(x_pos, y_pos, x_size, y_size);

    }
    else
    {

    }

    update();
}

void movingEllipse::move(qint32 a, qint32 b)
{

    //-15 30
    //-25 = x_pos 37.5 = y_pos
    if(on_Scene)
    {
        x_pos = std::max(-373, std::min(x_pos + a, 219));
        y_pos = std::max(-204, std::min(y_pos + b, 124));

        if(inside(x_pos, y_pos + y_size / 2) || inside(x_pos + x_size, y_pos  + y_size / 2) ||
                inside(x_pos + x_size / 2, y_pos) || inside(x_pos + x_size / 2, y_pos + y_size) ||
                inside(x_pos + 10, y_pos + 7.5) || inside(x_pos + 10, y_pos + y_size - 7.5) ||
                inside(x_pos + x_size - 10, y_pos + 7.5) || inside(x_pos + x_size - 10, y_pos + y_size - 7.5)
                )
            on_Scene = false;
    }
  //  auto ellipse = new movingEllipse(x_pos, y_pos, x_size, y_size);
    update();
}

void movingEllipse::remove()
{
    on_Scene = false;
}