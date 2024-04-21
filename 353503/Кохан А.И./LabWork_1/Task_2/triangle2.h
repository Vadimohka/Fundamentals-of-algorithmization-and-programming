#ifndef TRIANGLE2_H
#define TRIANGLE2_H

#include "figure.h"

class Triangle2 : public Figure
{
    Q_OBJECT

public:
    Triangle2(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // TRIANGLE2_H
