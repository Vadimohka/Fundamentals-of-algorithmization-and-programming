#ifndef FFTRIANGLE_H
#define FFTRIANGLE_H

#include "figure.h"

class ffTriangle : public figure
{
public:
    ffTriangle();

    void setPoints(QPoint msBeg, QPoint msNow);
};

#endif // FFTRIANGLE_H
