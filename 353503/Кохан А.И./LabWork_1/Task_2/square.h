#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{
    Q_OBJECT

public:
    Square(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // SQUARE_H
