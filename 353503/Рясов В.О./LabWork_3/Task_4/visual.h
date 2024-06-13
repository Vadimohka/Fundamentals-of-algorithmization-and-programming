#ifndef VISUAL_H
#define VISUAL_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include "hanoibrick.h"

class Visual : public QGraphicsScene
{
    int _x, _y, _w, _h;
public:
    Visual();
    HanoiBrick* intializeItems();
private:
};

#endif // VISUAL_H
