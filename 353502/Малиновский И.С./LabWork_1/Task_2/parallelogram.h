#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "figure.h"

class Parallelogram : public Figure
{
public:
    int clickNumber=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void updateSquare() override;
};

#endif // PARALLELOGRAM_H
