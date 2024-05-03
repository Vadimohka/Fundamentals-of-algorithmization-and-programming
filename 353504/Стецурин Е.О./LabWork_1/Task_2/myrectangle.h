#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include "figure.h"
#include <QBrush>

class MyRectangle : public Figure
{
public:
    MyRectangle(int x,int y, QGraphicsPolygonItem* parent = nullptr);
};

class RectDraw : public FigureDraw
{
    Q_OBJECT

public:
    explicit RectDraw(QPointF point, QGraphicsObject *parent = 0) :
        FigureDraw(point,parent)
    {
        Q_UNUSED(point)
    }

    ~RectDraw(){

    };

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MYRECTANGLE_H
