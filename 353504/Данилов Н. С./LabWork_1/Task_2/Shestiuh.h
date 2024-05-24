#pragma once

#include <QPainter>
#include "GeomFigure.h"

class Shestiuh: public GeomFigure
{
public:
    Shestiuh();
    Shestiuh(int cx, int cy, int a, int b);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
};
