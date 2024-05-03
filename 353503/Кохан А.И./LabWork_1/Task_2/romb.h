#ifndef ROMB_H
#define ROMB_H

#include "figure.h"

class Romb : public Figure
{
    Q_OBJECT

public:
    Romb(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // ROMB_H
