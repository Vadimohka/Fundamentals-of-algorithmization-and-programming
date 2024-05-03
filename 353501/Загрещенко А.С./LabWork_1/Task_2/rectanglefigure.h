#ifndef RECTANGLEFIGURE_H
#define RECTANGLEFIGURE_H

#include "abstractfigure.h"

class RectangleFigure : public AbstractFigure
{
public:
    RectangleFigure();

    void drawFigure(QPainter* painter) override;
    double getSquare() override;
    double getPerimetr() override;
};

#endif // RECTANGLEFIGURE_H
