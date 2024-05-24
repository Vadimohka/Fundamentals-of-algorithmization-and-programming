#ifndef FFSQUARE_H
#define FFSQUARE_H

#include "figure.h"

class ffSquare : public figure
{
public:
    ffSquare();

    virtual void setPoints(QPoint msBeg, QPoint msNow);
};

#endif // FFSQUARE_H
