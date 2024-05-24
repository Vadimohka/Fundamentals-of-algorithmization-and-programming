#ifndef HEXAGON_H
#define HEXAGON_H
#include"shape.h"

class Hexagon:public Shape
{
public:
    Hexagon();
    Hexagon(double R);
    ~Hexagon();

    void updateHexagon(double R);
    double R;
    int nearestVertex(QPointF point);
    void moveVertex(int index,QPointF point);
    void resetVertices();
private:
    void paint(QPainter*p);
};

#endif // HEXAGON_H
