#ifndef RHOMBUSFIGURE_H
#define RHOMBUSFIGURE_H

#include "abstractpolygon.h"

class RhombusFigure : public AbstractPolygon
{
public:
    RhombusFigure();
    void drawFigure(QPainter *painter) override;
    void editPolygon() override;

};

#endif // RHOMBUSFIGURE_H
