#ifndef FFNANGLYY_H
#define FFNANGLYY_H

#define PI 3.1415926535898

#include "figure.h"

class ffNanglyy : public figure
{
public:
    ffNanglyy(int n);

    virtual void setPoints(QPoint msBeg, QPoint msNow);
};

#endif // FFNANGLYY_H
