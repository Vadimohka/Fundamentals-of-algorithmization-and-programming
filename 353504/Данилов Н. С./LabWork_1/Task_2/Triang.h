#pragma once

#include <QPainter>
#include "GeomFigure.h"
class Triang: public GeomFigure
{
public:
    Triang();
    Triang(int cx, int cy, int a, int b);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
};
