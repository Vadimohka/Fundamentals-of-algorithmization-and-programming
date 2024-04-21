#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class Ellipse : public Figure
{
    Q_OBJECT

public:
    Ellipse(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // ELLIPSE_H
