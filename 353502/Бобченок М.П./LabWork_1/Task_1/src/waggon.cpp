//
// Created by u on 09.03.24.
//

#include "waggon.h"

void waggon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    moving_rect::paint(painter, option, widget);

    painter->setBrush(Qt::white);
    painter->drawEllipse(x_pos - 100, y_pos + h - 100, 200, 200);
    painter->drawEllipse(x_pos + w - 100, y_pos + h - 100, 200, 200);
}

waggon::waggon(int x, int y, int w, int h) : moving_rect(x, y, w, h)
{

}