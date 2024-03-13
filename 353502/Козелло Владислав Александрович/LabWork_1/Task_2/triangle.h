#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figures.h"

class Triangle : public Figures
{
public:
    Triangle();

    void setPoints(QMouseEvent*) override;
    void mousePress(QMouseEvent*) override;
    void updateData() override;
    void setNewPoints(const double, const int) override;
private:
    bool pointsFlag = false;
};

#endif // TRIANGLE_H
