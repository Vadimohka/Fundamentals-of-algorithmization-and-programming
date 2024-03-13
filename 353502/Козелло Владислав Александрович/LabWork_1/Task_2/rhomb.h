#ifndef RHOMB_H
#define RHOMB_H

#include "figures.h"

class Rhomb : public Figures
{
public:
    Rhomb();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // RHOMB_H
