#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure
{
public:
    int clickNumber = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void updateSquare() override;
};

#endif // RHOMB_H
