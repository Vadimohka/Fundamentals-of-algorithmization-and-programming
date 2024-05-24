//
// Created by u on 09.03.24.
//

#ifndef TELEGA_WAGGON_H
#define TELEGA_WAGGON_H

#include <QGraphicsObject>
#include <QGraphicsView>
#include "moving_rect.h"

class waggon : public moving_rect
{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    waggon(int x, int y, int w, int h);
};


#endif //TELEGA_WAGGON_H
