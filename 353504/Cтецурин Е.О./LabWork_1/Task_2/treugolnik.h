#ifndef TREUGOLNIK_H
#define TREUGOLNIK_H

#include "figure.h"
#include <QBrush>

class Treugolnik : public Figure
{
public:
    Treugolnik(int x, QGraphicsPolygonItem* parent = nullptr);
};

class TreugolnikDraw : public FigureDraw
{
    Q_OBJECT

public:
    explicit TreugolnikDraw(QPointF point, QGraphicsObject *parent = 0) :
        FigureDraw(point,parent)
    {
        Q_UNUSED(point)
    }
    ~TreugolnikDraw(){

    };

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TREUGOLNIK_H
