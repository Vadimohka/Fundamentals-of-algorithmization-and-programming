#ifndef PARALLELOHRAM_H
#define PARALLELOHRAM_H

#include"figures.h"

class Parallelohram: public Figures
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
