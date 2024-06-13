#ifndef RECT_H
#define RECT_H

#include "abstractfigure.h"

class Rect : public AbstractFigure
{
public:
    Rect(int x1 =0 , int y1 = 0, int x2 = 150 , int y2 = 150);
    ~Rect();
    void drawFigure(QPainter* painter) override;
};

#endif // RECT_H
