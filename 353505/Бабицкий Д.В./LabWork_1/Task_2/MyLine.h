#pragma once

#include <QPainter>
#include "GeomFigure.h"

class MyLine: public GeomFigure
{
private:

public:
    MyLine(/* args */);
    MyLine(int cx, int cy, int a, int b);
    virtual void Draw(QPainter *pr) override;
    void CountS() override;
};
