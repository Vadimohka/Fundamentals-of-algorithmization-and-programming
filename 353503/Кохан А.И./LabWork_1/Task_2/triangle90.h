#ifndef TRIANGLE90_H
#define TRIANGLE90_H

#include "figure.h"

class Triangle90 : public Figure
{
    Q_OBJECT

public:
    Triangle90(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // TRIANGLE90_H
