#ifndef FORSQUARE_H
#define FORSQUARE_H

#include "figure.h"

class foursquare : public figure
{
public:
    foursquare();
    ~foursquare() override;
    double getSquare() override;
    double getPerimeter() override;
    void setFigure(QPointF* points) override;
    bool isPointInside(QPointF point) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // FORSQUARE_H
