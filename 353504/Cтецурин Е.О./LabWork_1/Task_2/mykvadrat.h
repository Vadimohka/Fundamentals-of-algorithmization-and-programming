#ifndef MYKVADRAT_H
#define MYKVADRAT_H

#include "figure.h"
#include <QBrush>

class MyKvadrat: public Figure
{
public:
    MyKvadrat(int x,QGraphicsPolygonItem* parent = nullptr);
};

class KvadratDraw1 : public FigureDraw
{
    Q_OBJECT

public:
    explicit KvadratDraw1(QPointF point, QGraphicsObject *parent = 0) :
        FigureDraw(point,parent)
    {
        Q_UNUSED(point)
    }

    ~KvadratDraw1(){

    };

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MYKVADRAT_H
