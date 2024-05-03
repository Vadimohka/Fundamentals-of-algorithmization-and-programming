#pragma once

#include <QPainter>
#include "GeomFigure.h"

class Star_5: public GeomFigure
{
public:
    Star_5();
    Star_5(int cx, int cy, int a, int b);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
};
