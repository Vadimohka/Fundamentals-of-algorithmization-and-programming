#ifndef HEXAGON_H
#define HEXAGON_H
#include"shape.h"


class Hexagon: public Shape
{
public:
    Hexagon(int);
    float radius=90;
    float area() override;
    float perim() override;
     void setn(int edges)override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
private:
    int n;
};

#endif // HEXAGON_H
