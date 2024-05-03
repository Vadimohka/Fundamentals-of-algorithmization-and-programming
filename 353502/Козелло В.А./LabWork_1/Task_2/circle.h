#ifndef CIRCLE_H
#define CIRCLE_H

#include "figures.h"

class Circle : public Figures
{
public:
    Circle();

    void setPoints(QMouseEvent*) override;
    void create(QPainter*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};

#endif // CIRCLE_H
