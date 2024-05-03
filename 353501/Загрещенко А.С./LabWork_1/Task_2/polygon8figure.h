#ifndef POLYGON8FIGURE_H
#define POLYGON8FIGURE_H


#include "abstractpolygon.h"

class Polygon8Figure : public AbstractPolygon
{
public:
    Polygon8Figure();
    void drawFigure(QPainter *painter) override;
    void editPolygon() override;

};

#endif // POLYGON8FIGURE_H
