#ifndef CUSTOM_H
#define CUSTOM_H

#include "shape.h"
#include <QGraphicsSceneMouseEvent>

class Custom: public Shape
{
public:
    QVector<QVector<QPointF>> points;
    int currentline = 0;
    Custom(QGraphicsItem *parent = nullptr);
    ~Custom();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOM_H
