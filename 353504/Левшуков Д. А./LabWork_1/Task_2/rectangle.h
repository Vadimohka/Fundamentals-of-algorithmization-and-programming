#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figures.h"
class Rectangle: public figure
{
public:
    void setP(QMouseEvent *)override;
    void reset(bool sp)override;
    void make_sq();
private:
    bool Square=false;
};

#endif // RECTANGLE_H
