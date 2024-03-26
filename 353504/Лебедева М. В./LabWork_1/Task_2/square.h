#ifndef SQUARE_H
#define SQUARE_H

#include"figures.h"

class Square: public Figures
{
public:
    Square();
    float size=100;
    float area() override;
    float perimeter() override;
private:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // SQUARE_H
