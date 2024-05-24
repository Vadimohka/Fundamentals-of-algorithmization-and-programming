//
// Created by darina on 3/9/24.
//

#include "baloon.h"
#include "QPainter"
#include "QPainterPath"

baloon::baloon(qint32 x, qint32 y) : movingEllipse(0, 0) {
    on_Scene = true;
    x_size = 50;
    y_size = 75;
}

void baloon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(on_Scene)
    {
        painter->setBrush(Qt::magenta);
        painter->setPen(Qt::black);
        painter->drawEllipse(x_pos, y_pos, x_size, y_size);
        QPainterPath path;
        qint32 x1 = x_pos + x_size / 2, x2 = x_pos + x_size / 2 + 5, x3 = x_pos + x_size / 2 - 5, y1 = y_pos + y_size, y2 = y_pos + y_size + 5, y3 = y_pos + y_size + 5;

        path.moveTo (x1,y1);
        // Draw line from pen point to this point.
        path.lineTo (x1,y1);
        path.lineTo (x2,y2);
        path.lineTo (x3,y3);
        path.lineTo (x1,y1);
        painter->fillPath (path, QBrush(Qt::magenta));

        painter->setPen(Qt :: black);
        painter->drawLine(x1, y1, x2, y2);
        painter->drawLine(x1, y1, x3, y3);
        painter->drawLine(x3, y3, x2, y2);
        painter->drawLine(x1, y2, x1, y2 + 50);

    }
    else
    {
        QPixmap boom("../boom.png");
        QPixmap boom2 = boom.scaled(50, 75, Qt::IgnoreAspectRatio);
        painter->drawPixmap(x_pos, y_pos, boom2);
       // painter->setBrush(Qt::blue);
       // painter->drawEllipse(x_pos, y_pos, x_size - 10, y_size - 10);
    }

    update();
}