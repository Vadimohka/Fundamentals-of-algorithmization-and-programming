#ifndef STAR8_H
#define STAR8_H

#include "figures.h"

class Star8 : public Figures
{
public:
    Star8();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // STAR8_H
