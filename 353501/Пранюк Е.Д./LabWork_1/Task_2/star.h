#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure
{
public:
    Star();

    //int n=1;

    void paintEvent(QPaintEvent *event);
};

#endif // STAR_H
