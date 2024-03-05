#ifndef STAR6_H
#define STAR6_H

#include "stars.h"

class star6 : public stars
{
public:
    star6()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STAR6_H
