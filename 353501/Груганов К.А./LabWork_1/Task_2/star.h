#ifndef STAR_H
#define STAR_H
#include"shape.h"

class Star:public Shape
{
public:
    Star();
    Star(int points,double innerR,double outerR);
    ~Star();
    int points;
    double innerR;
    double outerR;

    void updateStar(int points, double innerR, double outerR);
    void updatePts(int points);
    void updateInnerR(double innerR);
    void updateOuterR(double outerR);
private:
    void print(QPainter*p);
};

#endif // STAR_H
