#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class rhombus : public figure
{
public:
    rhombus();
    ~rhombus() override;
    double getSquare() override;
    double getPerimeter() override;
    void setFigure(QPointF* points) override;
    bool isPointInside(QPointF point) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // RHOMBUS_H
