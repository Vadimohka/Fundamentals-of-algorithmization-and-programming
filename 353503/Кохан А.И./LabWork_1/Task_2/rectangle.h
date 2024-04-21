#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT

public:
    Rectangle(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // RECTANGLE_H
