#ifndef FLAGG_H
#define FLAGG_H
#include <QPainter>
#include <moverect.h>
#include <QPaintEvent>

class flagg : public moverect
{
public:
    void draw(QPainter&);
};

#endif // FLAGG_H
