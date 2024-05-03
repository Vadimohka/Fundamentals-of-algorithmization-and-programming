#ifndef STAR5_H
#define STAR5_H

#include "figure.h"

class Star5 : public Figure
{
    Q_OBJECT
public:
    Star5(QVector<QPointF> temp, QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    qreal base;
    qreal tri_side;
    qreal temp_perim;
    qreal diag;
    qreal side;
};

#endif // STAR5_H
