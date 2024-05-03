#ifndef CUSTOM_H
#define CUSTOM_H

#include "figure.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Custom : public Figure
{
public:
    Custom();


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QPointF     previousPoint;
};

#endif // CUSTOM_H
