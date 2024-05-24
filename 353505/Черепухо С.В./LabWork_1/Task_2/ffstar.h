#ifndef FFSTAR_H
#define FFSTAR_H

#define PI 3.1415926535898

#include "figure.h"

class ffStar : public figure
{
public:
    ffStar(int n);

    virtual void setPoints(QPoint msBeg, QPoint msNow);
};

#endif // FFSTAR_H
