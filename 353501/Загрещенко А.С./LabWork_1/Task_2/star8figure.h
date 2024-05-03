#ifndef STAR8FIGURE_H
#define STAR8FIGURE_H

#include "abstractpolygon.h"

class Star8Figure : public AbstractPolygon
{
public:
    Star8Figure();
    void drawFigure(QPainter *painter) override;
    void editPolygon() override;
};

#endif // STAR8FIGURE_H
