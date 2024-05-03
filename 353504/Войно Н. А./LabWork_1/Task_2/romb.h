#ifndef ROMB_H
#define ROMB_H

#include "base.h"

class romb: public base
{
public:
    romb();
    void draw(QGraphicsScene *scene, int width, int height, int a, int &h)override;
    void getParametrs(int &side1, int &side2, int &side3, int a) override;
    void perSquareMasse(int width, int height, int a)override;
    bool proverka(int side1, int side2, int side3);
};

#endif // ROMB_H
