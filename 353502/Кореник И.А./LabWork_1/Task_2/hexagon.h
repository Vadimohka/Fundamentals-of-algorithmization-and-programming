#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.h"

class Hexagon : public Figure
{
public:
    explicit Hexagon(QWidget* parent = nullptr);

private:
    void setPoints() override;

    void calcPerimetr() override;

    void calcArea() override;

    double r;
};

#endif // HEXAGON_H
