#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <figure.h>

class Rectangle : public Figure
{
private:
    double width;
    double height;
    qreal x1, y1, x2, y2, x3, y3, x4, y4;
public:
    Rectangle();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void setWidthRectangle(double value) override;
    void setHeightRectangle(double value) override;
    void calculatePoints() override;
};

#endif // RECTANGLE_H
