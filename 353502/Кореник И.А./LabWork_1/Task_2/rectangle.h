#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <figure.h>

class Rectangle : public Figure
{
    Q_OBJECT
public:
    explicit Rectangle(QWidget *parent = nullptr);

    void setPoints() override;

    void calcCentre() override;
    void calcArea() override;
    void calcPerimetr() override;

private:
    double a;
    double b;




};

#endif // RECTANGLE_H
