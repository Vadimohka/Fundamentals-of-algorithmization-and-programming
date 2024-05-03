#ifndef POINT_POV_H
#define POINT_POV_H

#include "figures.h"

#include <QPainter>

#include <QGraphicsScene>

class point_pov : public QGraphicsScene{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // POINT_POV_H
