#ifndef STAR6_H
#define STAR6_H

#include "figure.h"

class Star6: public Figure{
public:
    Star6();
private:
    float radius1 = 80;
    float radius2 = 80;
    int count = 6;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // STAR6_H
