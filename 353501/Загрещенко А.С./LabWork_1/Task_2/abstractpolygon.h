#ifndef ABSTRACTPOLYGONE_H
#define ABSTRACTPOLYGONE_H

#include "abstractfigure.h"

class AbstractPolygon : public AbstractFigure
{
public:
    AbstractPolygon();

    void setRect(double dx1, double dy1, double dx2, double dy2) override;
protected:
    virtual void editPolygon();
    QPolygon polygon;
    virtual double getSquare() override;
    virtual double getPerimetr();
};

#endif // ABSTRACTPOLYGONE_H
