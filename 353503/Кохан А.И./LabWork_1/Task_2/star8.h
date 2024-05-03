#ifndef STAR8_H
#define STAR8_H

#include "figure.h"

class Star8 : public Figure
{
    Q_OBJECT

public:
    Star8(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};

#endif // STAR8_H
