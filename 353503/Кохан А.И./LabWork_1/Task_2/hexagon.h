#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure
{
    Q_OBJECT

public:
    Hexagon(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // HEXAGON_H
