#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "abstractfigure.h"

class Ellipse : public AbstractFigure
{
public:
    Ellipse(int x1 =0 , int y1 = 0, int x2 = 150 , int y2 = 150);
    ~Ellipse();

    void drawFigure(QPainter* painter) override;

};

#endif // ELLIPSE_H
