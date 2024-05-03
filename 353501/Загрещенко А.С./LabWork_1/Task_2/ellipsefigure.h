#ifndef ELLIPSEFIGURE_H
#define ELLIPSEFIGURE_H

#include "abstractfigure.h"

class EllipseFigure : public AbstractFigure {
public:
    EllipseFigure();

    void drawFigure(QPainter *painter) override;
    double getSquare();
    double getPerimetr();
};

#endif // ELLIPSEFIGURE_H
