#ifndef LINE_H
#define LINE_H

#include <QGraphicsScene>

#include <QGraphicsSceneMouseEvent>

class line : public QGraphicsScene
{
public:
    QPointF point;
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // LINE_H
