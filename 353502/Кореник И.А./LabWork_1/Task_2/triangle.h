#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <figure.h>

class Triangle : public Figure
{
    Q_OBJECT
public:
    explicit Triangle(QWidget *parent = nullptr);

private:

    void setPoints() override;

    void calcArea() override;

    void calcPerimetr() override;

    void calcCentre() override;


};

#endif // TRIANGLE_H
