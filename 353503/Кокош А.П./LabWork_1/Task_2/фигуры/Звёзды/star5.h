#ifndef STAR5_H
#define STAR5_H

#include <QtWidgets>
#include "stars.h"

class star5 : public stars {
public:
    star5() = default;

    void setPoints(QMouseEvent * /*event*/) override;
};

#endif // STAR5_H
