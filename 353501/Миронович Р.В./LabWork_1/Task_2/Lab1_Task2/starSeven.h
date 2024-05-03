#ifndef STARSEVEN_H
#define STARSEVEN_H

#include "stars.h"

class star7 : public stars
{
public:
    star7()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STARSEVEN_H
