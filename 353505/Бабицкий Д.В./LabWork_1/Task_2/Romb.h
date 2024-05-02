#pragma once

#include <QPainter>
#include "GeomFigure.h"

class Romb: public GeomFigure
{
public:
    Romb();
    Romb(int, int, int, int);
    virtual void SetWidth(int);
    virtual void SetHeight(int);
};
