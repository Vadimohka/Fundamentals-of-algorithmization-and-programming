#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Circle : public Figure
{
public:
    Circle();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float perimeter();
    float area() override;
    float centerX();
    float centerY();
};
#endif // CIRCLE_H
