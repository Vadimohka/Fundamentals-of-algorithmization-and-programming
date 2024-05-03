#ifndef TRIANGLEFIGURE_H
#define TRIANGLEFIGURE_H

#include "abstractpolygon.h"

class TriangleFigure : public AbstractPolygon
{
public:
    TriangleFigure();

    void editPolygon() override;
    void drawFigure(QPainter* painter) override;
    double getSquare() override;
};

#endif // TRIANGLEFIGURE_H
