#ifndef STAR8_H
#define STAR8_H

#include "figure.h"

class Star8 : public Figure
{
    Q_OBJECT
public:
    Star8(QVector<QPointF> temp, QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    qreal base;
    qreal tri_side;
    qreal temp_perim;
    qreal diag;
    qreal side;
};

#endif // STAR8_H
