#ifndef STAR8_H
#define STAR8_H

#include <QtWidgets>
#include "stars.h"

class star8 : public stars
{
private:
public:
    star8() = default;

    void setPoints(QMouseEvent * /*event*/) override;
};

#endif // STAR8_H
