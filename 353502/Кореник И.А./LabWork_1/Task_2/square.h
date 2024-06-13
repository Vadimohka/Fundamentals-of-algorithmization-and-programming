#ifndef SQUARE_H
#define SQUARE_H
#include "figure.h"

class Square : public Figure
{
public:
    explicit Square(QWidget* parent = nullptr);

private:
    void setPoints() override;

    void calcArea() override;

    void calcCentre() override;

    void calcPerimetr() override;

    double side;

};

#endif // SQUARE_H
