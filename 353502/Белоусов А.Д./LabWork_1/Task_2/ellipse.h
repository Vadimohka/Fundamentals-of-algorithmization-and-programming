#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class ellipse : public figure
{
public:
    ellipse();
    ~ellipse() override;
    double getSquare() override;
    double getPerimeter() override;
    void setFigure(QPointF* points) override;
    bool isPointInside(QPointF point) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // ELLIPSE_H
