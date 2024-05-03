#ifndef STAR_H
#define STAR_H

#include "shape.h"

class Star : public Shape
{
private:
    int sRad;
    int bRad;
public:
    Star(QPointF first, QPointF second,int n);
    void setSize(QPointF nPoint) override;
};

#endif // STAR_H
