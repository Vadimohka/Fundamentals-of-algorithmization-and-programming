#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figures.h"

class Rectangle : public Figures
{
public:
    Rectangle();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // RECTANGLE_H
