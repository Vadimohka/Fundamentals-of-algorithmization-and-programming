#ifndef STAR6_H
#define STAR6_H

#include "figure.h"

class Star6 : public Figure
{
    Q_OBJECT
public:
    Star6(QVector<QPointF> temp, QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    qreal base;
    qreal tri_side;
    qreal temp_perim;
    qreal diag;
    qreal side;
};

#endif // STAR6_H
