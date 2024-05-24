#ifndef STAR8_H
#define STAR8_H

#include "figure.h"

class Star8: public Figure
{
public:
    Star8();
    float area() override;
    float perimeter() override;
private:
    float radius1=80;
    float radius2=100;
    int count=8;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // STAR8_H
