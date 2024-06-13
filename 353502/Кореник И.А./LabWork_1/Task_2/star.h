#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure
{
    Q_OBJECT

public:
    explicit Star(QWidget* parent = nullptr);

protected:
    void setPoints() override;

    void calcArea() override;

    void calcPerimetr() override;

    void calcCentre() override;

    int n;
};

#endif // STAR_H
