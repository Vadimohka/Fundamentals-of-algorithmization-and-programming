#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure
{
public:
    int clickNumber=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void updateSquare() override;
};

#endif // TRIANGLE_H
