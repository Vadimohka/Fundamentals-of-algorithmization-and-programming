#pragma once
#include <QWidget>
#include <QPainter>
#include "GeomFigure.h"
class Circle: public GeomFigure
{
private:
    
public:
    Circle(/* args */);
    Circle(int cx, int cy, int a, int b);
    virtual void Draw(QPainter *pr) override;
    virtual void CountS() override;
    virtual void CountP() override;
    virtual void Resize(bool) override;
};
