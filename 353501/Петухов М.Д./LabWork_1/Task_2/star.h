#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure
{
private:
    double inner_radius = 100;
    double outer_radius = 200;
    int num_vertices = 5;
    double starAngle;
public:
    Star();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void setInnerRadius() override;
    void setOuterRadius() override;
    void setVertices(int vertices) override;
    void setInnerRadiusDown() override;
    void setOuterRadiusDown() override;
    void calculatePoints() override;
};

#endif // STAR_H
