#ifndef PARALLELOHRAM_H
#define PARALLELOHRAM_H

#include"shape.h"

class Parallelohram: public Shape
{
public:
    Parallelohram();
    float area() override;
    float perimeter() override;
    float b=100;
    float c=95;
private:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // PARALLELOHRAM_H
