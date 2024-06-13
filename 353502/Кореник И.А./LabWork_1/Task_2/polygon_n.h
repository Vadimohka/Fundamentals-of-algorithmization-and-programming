#ifndef POLYGON_N_H
#define POLYGON_N_H
#include "figure.h"

class Polygon_N : public Figure
{
public:
    explicit Polygon_N(QWidget* parent);

    void setN(QString) override;

private:
    void setPoints() override;

    double r;

    int n;

    void calcArea() override;

    void calcPerimetr() override;

};

#endif // POLYGON_N_H
