#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

const int NUMBER_OF_SIDES = 6;

class hexagon : public figure
{
public:
    hexagon();
    ~hexagon() override;
    double getSquare() override;
    double getPerimeter() override;
    void setFigure(QPointF* points) override;
    bool isPointInside(QPointF point) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // HEXAGON_H
