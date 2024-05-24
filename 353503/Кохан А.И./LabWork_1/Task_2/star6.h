#ifndef STAR6_H
#define STAR6_H

#include "figure.h"

class Star6 : public Figure
{
    Q_OBJECT

public:
    Star6(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // STAR6_H
