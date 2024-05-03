#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class Ellipse : public Figure
{
    Q_OBJECT
public:
    Ellipse(QVector<QPointF> temp, QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    qreal x_side;
    qreal y_side;
};

#endif // ELLIPSE_H
