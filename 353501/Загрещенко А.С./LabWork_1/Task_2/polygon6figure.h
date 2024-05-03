#ifndef POLYGON6FIGURE_H
#define POLYGON6FIGURE_H

#include "abstractpolygon.h"

class Polygon6Figure : public AbstractPolygon
{
public:
    Polygon6Figure();
    void drawFigure(QPainter *painter) override;
    void editPolygon() override;

};

#endif // POLYGON6FIGURE_H
