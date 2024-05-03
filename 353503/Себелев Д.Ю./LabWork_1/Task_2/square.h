#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{
    Q_OBJECT
public:
    Square(QVector<QPointF> temp, QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    qreal diag;
};

#endif // SQUARE_H
