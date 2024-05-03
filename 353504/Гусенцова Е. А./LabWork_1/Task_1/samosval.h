#ifndef SAMOSVAL_H
#define SAMOSVAL_H
#include "movingrectangle.h"

class Samosval:public Rec
{
public:
    void paintEvent(QPaintEvent *event);
    void drawSam(QPainter *painter);
};
#endif

