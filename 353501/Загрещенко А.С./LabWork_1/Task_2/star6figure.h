#ifndef STAR6FIGURE_H
#define STAR6FIGURE_H

#include "abstractpolygon.h"

class Star6Figure : public AbstractPolygon
{
public:
    Star6Figure();
    void drawFigure(QPainter *painter) override;
    void editPolygon() override;

};

#endif // STAR6FIGURE_H
