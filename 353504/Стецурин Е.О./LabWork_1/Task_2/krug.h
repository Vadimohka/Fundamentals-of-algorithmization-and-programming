#ifndef KRUG_H
#define KRUG_H

#include "figure.h"
#include <QBrush>

class Krug : public Figure
{
public:
    Krug(qreal x,qreal y, qreal diametr);
private:
    QGraphicsItemGroup* group;
};

class KrugDraw : public FigureDraw
{
    Q_OBJECT

public:
    explicit KrugDraw(QPointF point, QGraphicsObject *parent = 0) :
        FigureDraw(point,parent)
    {
        Q_UNUSED(point)
    }

    ~KrugDraw(){

    };

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // KRUG_H
