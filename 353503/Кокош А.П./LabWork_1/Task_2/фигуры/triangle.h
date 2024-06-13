#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtWidgets>
#include "figures.h"

class triangle : public figures
{
public:
    triangle() = default;

    void setPoints(QMouseEvent * /*event*/) override;
};

#endif // TRIANGLE_H
