#ifndef FFRECT_H
#define FFRECT_H

#include "figure.h"

class ffRect : public figure
{
public:
    ffRect();

    void setPoints(QPoint msBeg, QPoint msNow);

protected:
};

#endif // FFRECT_H
