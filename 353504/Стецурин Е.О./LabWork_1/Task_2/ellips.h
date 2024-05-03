#ifndef ELLIPS_H
#define ELLIPS_H

#include "figure.h"
#include <QBrush>

class Ellips : public Figure
{
public:
    Ellips(qreal x,qreal y, qreal diametr1, qreal diametr2);

private:
    QGraphicsItemGroup* group;
};

class EllipseDraw : public FigureDraw
{
    Q_OBJECT

public:
    explicit EllipseDraw(QPointF point, QGraphicsObject *parent = 0) :
        FigureDraw(point,parent)
    {
        Q_UNUSED(point)
    }

    ~EllipseDraw(){

    };

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ELLIPS_H
