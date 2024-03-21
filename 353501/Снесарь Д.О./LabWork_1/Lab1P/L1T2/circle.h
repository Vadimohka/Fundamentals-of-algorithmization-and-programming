#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellipse.h"

class Circle : public Ellipse
{

public:
    Circle();
    Circle(QPointF p, QPointF r);

    void setSize (QPointF nPoint) override;
    double getS() override;
    double getP() override;
};

#endif // CIRCLE_H
