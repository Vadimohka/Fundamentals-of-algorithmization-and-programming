#ifndef PENTAGON_H
#define PENTAGON_H

#include "figures.h"

class Octagon : public Figures
{
public:
    Octagon();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // PENTAGON_H
