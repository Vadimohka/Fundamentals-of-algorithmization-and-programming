#ifndef LINE_H
#define LINE_H

#include "basicshape.h"

class Line: public BasicShape
{
public:
    Line();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // LINE_H
