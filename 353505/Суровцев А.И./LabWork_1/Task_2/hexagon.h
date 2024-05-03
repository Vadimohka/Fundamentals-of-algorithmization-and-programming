#ifndef HEXAGON_H
#define HEXAGON_H
#include "par_polygon.h"
class Hexagon:public par_polygon
{
public:
    Hexagon(qreal R);
    void SetStartParams();
    bool isRegularHexagon();
    void SquareHexagon();
    qreal GetSquareHex();
    void SetNewCoord(qreal R);
private:
    qreal start_R = 0;
    qreal squareHex = 0;
    bool correct = false;
    qreal SCH = 0;
    void SquareCorrectHexagon();
};

#endif // HEXAGON_H
