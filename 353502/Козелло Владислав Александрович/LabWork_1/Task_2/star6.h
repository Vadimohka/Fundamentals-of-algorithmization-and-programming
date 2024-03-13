#ifndef STAR6_H
#define STAR6_H

#include "figures.h"

class Star6 : public Figures
{
public:
    Star6();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // STAR6_H
