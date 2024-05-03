#ifndef STARSIX_H
#define STARSIX_H
#include "stars.h"

class star6 : public stars
{
public:
    star6()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STARSIX_H
