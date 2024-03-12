#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line: public Shape
{
public:
    Line();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // LINE_H
