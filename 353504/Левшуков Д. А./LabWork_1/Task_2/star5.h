#ifndef STAR5_H
#define STAR5_H

#include "stars.h"

class star5 : public stars
{
public:
    star5()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STAR5_H
