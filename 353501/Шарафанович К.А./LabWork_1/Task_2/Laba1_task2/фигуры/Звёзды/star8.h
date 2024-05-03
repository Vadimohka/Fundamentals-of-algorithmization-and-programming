#ifndef STAR8_H
#define STAR8_H


#include <QtWidgets>
#include "stars.h"

class star8 : public stars {
public:
    star8() = default;

    void setPoints(QMouseEvent *) override;
};

#endif // STAR8_H
