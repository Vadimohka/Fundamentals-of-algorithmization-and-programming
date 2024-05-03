#ifndef CIRCLE_H
#define CIRCLE_H

#include <figure.h>

class Circle :  public Figure
{
private:
    double radiusX = 100;
    double radiusY = 100;
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    double findSquare() override;
    double findPerimeter() override;
};

#endif // CIRCLE_H
