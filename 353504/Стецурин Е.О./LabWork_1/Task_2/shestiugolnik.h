#ifndef SHESTIUGOLNIK_H
#define SHESTIUGOLNIK_H

#include "figure.h"
#include <QBrush>

class Shestiugolnik : public Figure
{
public:
    Shestiugolnik(int x, QGraphicsPolygonItem* parent = nullptr);
};

class HexDraw : public FigureDraw
{
    Q_OBJECT

public:
    explicit HexDraw(QPointF point, QGraphicsObject *parent = 0);
    ~HexDraw();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // SHESTIUGOLNIK_H
