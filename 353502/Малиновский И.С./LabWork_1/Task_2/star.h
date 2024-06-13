#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure
{
public:
    int verticesNum;
    double describedRadius = 1, inscribedRadius = describedRadius / 2.0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void updateSquare() override;
};

#endif // STAR_H
