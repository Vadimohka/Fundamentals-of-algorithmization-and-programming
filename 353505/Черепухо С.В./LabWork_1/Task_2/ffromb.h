#ifndef FFROMB_H
#define FFROMB_H

#include "figure.h"

class ffRomb : public figure
{
public:
    ffRomb();

    virtual void setPoints(QPoint msBeg, QPoint msNow);
};

#endif // FFROMB_H
