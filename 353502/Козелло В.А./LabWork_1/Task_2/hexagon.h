#ifndef HEXAGON_H
#define HEXAGON_H

#include "figures.h"

class Hexagon : public Figures
{
public:
    Hexagon();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // HEXAGON_H
