#ifndef LAB3TASK1_RING_H
#define LAB3TASK1_RING_H
#define uint unsigned

#include "QDebug"
#include "QGraphicsItem"
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QPainter"

class Ring {
    float _width;

    float _height;

    int _pos;

    QPointF _center;

    QRectF _ring;

public:
    Ring();

    void setWidth(float width);

    void setHeight(float height);

    void setPoint(QPointF point);

    void setPos(uint pos);

    void setRing(float xPos, float yPos, float width, float height);

    QRectF ring();

    QPointF center();

    int pos();

    float x();

    float y();

    float width() const;

    float height() const;
};

#endif//LAB3TASK1_RING_H
