#ifndef STAR6_H
#define STAR6_H

#include <QtWidgets>
#include "stars.h"

class star6 : public stars {
public:
    star6() = default;

    void setPoints(QMouseEvent * /*event*/) override;
};

#endif // STAR6_H
