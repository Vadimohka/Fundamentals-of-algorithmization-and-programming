#ifndef STAR6_H
#define STAR6_H

#include "figures.h"

class Star6: public Figures
{
public:
    Star6();
    float area() override;
    float perimeter() override;
private:
    float radius1 = 80;
    float radius2 = 80;
    int count = 6;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // STAR6_H
