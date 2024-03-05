#ifndef POLYLINE_H
#define POLYLINE_H
#include "figures.h"
class Polyline: public figure
{
public:
    void setP(QMouseEvent *)override;
    void draw(QPainter *)override;
    void findSquare()override;
    void findPerimetr()override;
};

#endif // POLYLINE_H
