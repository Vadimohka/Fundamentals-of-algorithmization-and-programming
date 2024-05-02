#pragma once

#include <QPainter>
#include "Pramouh.h"

class Kvadr: public Pramouh
{
public:
    Kvadr();
    Kvadr(int cx, int cy, int a, int b);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
};
