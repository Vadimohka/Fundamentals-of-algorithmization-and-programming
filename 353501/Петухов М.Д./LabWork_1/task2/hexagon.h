#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure
{
private:
    double angleHex;
    int num_vertices = 6;
    double radius = 100;
    double theta;
public:
    Hexagon();
    void setVertices(int vertices) override;
    void calculatePoints() override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

#endif // HEXAGON_H
