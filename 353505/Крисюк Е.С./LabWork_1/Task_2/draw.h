#ifndef DRAW_H
#define DRAW_H

#include "all_shapes.h"
#include <QGraphicsPolygonItem>

class Draw : public QGraphicsPolygonItem, All_shapes
{
public:
    Draw(qreal, qreal, QGraphicsItem*);
    QPointF Point;
    QPointF Current_point;
    QPolygonF draw;


    QEvent::Type mousePressType;


public:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;


private:
    QPointF Mouse_last_pos;
};

#endif // DRAW_H
