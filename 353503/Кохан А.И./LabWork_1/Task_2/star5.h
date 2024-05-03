#ifndef STAR5_H
#define STAR5_H

#include "figure.h"

class Star5 : public Figure
{
    Q_OBJECT

public:
    Star5(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // STAR5_H
