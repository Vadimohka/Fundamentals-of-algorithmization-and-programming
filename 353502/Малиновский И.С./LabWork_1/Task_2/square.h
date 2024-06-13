#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void updateSquare() override;
};

#endif // SQUARE_H
