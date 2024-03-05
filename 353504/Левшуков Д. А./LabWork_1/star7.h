#ifndef STAR7_H
#define STAR7_H

#include "stars.h"

class star7 : public stars
{
public:
    star7()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STAR7_H
