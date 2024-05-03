#ifndef STAR6_H
#define STAR6_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Star6 : public Figure
{
public:
    Star6();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float perimeter();
    float area() override;
    float centerX();
    float centerY();
};

#endif // STAR6_H
