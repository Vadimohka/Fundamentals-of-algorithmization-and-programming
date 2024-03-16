#ifndef STAR_H
#define STAR_H

#include "Shape.h"

class Star : public Shape
{
public:
    Star();
    void setRadA(int radius)override;
    void setRadB(int radius)override;
    void setN(int edges)override;
    float area() override;
    float perim() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    int radA; // Outer radius
    int radB; // Inner radius
    int n;    // Number of edges
};

#endif // STAR_H
