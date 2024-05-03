#ifndef STARFIVE_H
#define STARFIVE_H
#include "stars.h"

class star5 : public stars
{
public:
    star5()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STARFIVE_H
