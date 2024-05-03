#ifndef CIRCLE_H
#define CIRCLE_H
#include "figures.h"

class Circle: public figure
{
public:
    Circle()=default;
    void draw(QPainter *)override;
    void move_figure()override;//fixed
    void DrawP(QPainter *)override;
    void reset(bool sp)override;
private:
    double radius=0;
    bool NoCircle=false;

    void updCenter() override;
    void findPerimetr()override;
    void findSquare()override;
};

#endif // CIRCLE_H
