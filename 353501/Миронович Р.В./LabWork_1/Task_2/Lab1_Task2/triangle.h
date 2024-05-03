#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figures.h"

class Triangle : public figure
{
public:

    void setP(QMouseEvent *)override;

};

#endif // TRIANGLE_H
