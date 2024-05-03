#ifndef RECT_H
#define RECT_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setRotation(int angle);
    float perimeter() override;
    float area() override;
    float centerX();
    float centerY();
};

#endif // RECT_H
