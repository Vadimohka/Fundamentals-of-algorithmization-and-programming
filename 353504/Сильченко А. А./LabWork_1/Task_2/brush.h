#ifndef BRUSH_H
#define BRUSH_H

#include "figure.h"

class Brush : public Figure{
public:
    Brush(Figure *parent = nullptr);

    void draw(QPainter *painter) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void findSquare() override;
    void findPerimetr() override;

private:
    QPainterPath path;
};

#endif // BRUSH_H
