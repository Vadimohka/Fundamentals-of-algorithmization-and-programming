#ifndef ROMB_H
#define ROMB_H

#include "figure.h"
#include <QBrush>

class Romb : public Figure
{
public:
    Romb(int x, int y, QGraphicsPolygonItem* parent = nullptr);
};

class RombDraw : public FigureDraw
{
    Q_OBJECT

public:
    explicit RombDraw(QPointF point, QGraphicsObject *parent = 0);
    ~RombDraw();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROMB_H
