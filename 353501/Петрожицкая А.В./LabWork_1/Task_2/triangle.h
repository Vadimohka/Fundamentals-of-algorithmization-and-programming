#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float perimeter();
    float area() override;
    float centerX();
    float centerY();
};

#endif // TRIANGLE_H
