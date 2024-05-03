#ifndef STAR8_H
#define STAR8_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Star8 : public Figure
{
public:
    Star8();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float perimeter();
    float area() override;
    float centerX();
    float centerY();
};

#endif // STAR8_H
