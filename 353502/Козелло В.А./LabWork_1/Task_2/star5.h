#ifndef STAR5_H
#define STAR5_H

#include "figures.h"

class Star5 : public Figures
{
public:
    Star5();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // STAR5_H
