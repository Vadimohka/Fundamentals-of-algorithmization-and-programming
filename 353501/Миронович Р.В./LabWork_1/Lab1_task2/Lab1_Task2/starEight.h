#ifndef STAREIGHT_H
#define STAREIGHT_H

#include "stars.h"

class star8 : public stars
{
public:
    star8()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STAREIGHT_H
