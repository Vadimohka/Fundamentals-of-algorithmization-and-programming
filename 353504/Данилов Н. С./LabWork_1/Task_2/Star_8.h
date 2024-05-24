#pragma once

#include <QPainter>
#include "GeomFigure.h"

class Star_8: public GeomFigure
{
public:
    Star_8();
    Star_8(int cx, int cy, int a, int b);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
};
