#pragma once

#include <QPainter>
#include "GeomFigure.h"

class Star_6: public GeomFigure
{
public:
    Star_6();
    Star_6(int cx, int cy, int a, int b);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
};
