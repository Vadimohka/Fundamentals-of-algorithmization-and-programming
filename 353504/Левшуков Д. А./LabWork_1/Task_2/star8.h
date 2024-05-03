#ifndef STAR8_H
#define STAR8_H

#include "stars.h"

class star8 : public stars
{
public:
    star8()=default;
    void setP(QMouseEvent* m)override;
};

#endif // STAR8_H
