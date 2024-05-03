#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsItem>
#include <QPainter>
#include "movingrect.h"

class Ground : public movingRect
{
public:
    Ground();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GROUND_H
