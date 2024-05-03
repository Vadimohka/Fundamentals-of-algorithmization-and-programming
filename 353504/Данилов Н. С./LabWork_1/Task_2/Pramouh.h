#pragma once

#include <QPainter>
#include "GeomFigure.h"

class Pramouh: public GeomFigure
{
public:
    Pramouh();
    Pramouh(int cx, int cy, int a, int b);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
};
