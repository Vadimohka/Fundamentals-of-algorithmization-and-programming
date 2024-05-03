#ifndef STAR5FIGURE_H
#define STAR5FIGURE_H

#include "abstractpolygon.h"

class Star5Figure : public AbstractPolygon
{
public:
    Star5Figure();
    void drawFigure(QPainter *painter) override;
    void editPolygon() override;

};

#endif // STAR5FIGURE_H
