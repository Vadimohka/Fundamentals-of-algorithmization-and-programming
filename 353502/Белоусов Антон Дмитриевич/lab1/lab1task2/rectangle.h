#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class rectangle : public figure
{
public:
    rectangle();
    ~rectangle() override;
    double getSquare() override;
    double getPerimeter() override;
    void setFigure(QPointF* points) override;
    bool isPointInside(QPointF point) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // RECTANGLE_H
