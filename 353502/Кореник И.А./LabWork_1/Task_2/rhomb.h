#ifndef RHOMB_H
#define RHOMB_H
#include "figure.h"

class Rhomb : public Figure
{
public:
    explicit Rhomb(QWidget* parent = nullptr);
private:
    void setPoints() override;

    void calcArea() override;

    void calcPerimetr() override;

    void calcCentre() override;
};

#endif // RHOMB_H
