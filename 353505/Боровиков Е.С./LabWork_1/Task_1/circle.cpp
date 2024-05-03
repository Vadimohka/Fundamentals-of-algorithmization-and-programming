#include "circle.h"

Circle::Circle() {

    smalic = new QGraphicsEllipseItem(30,30,550,550);
    smalic->setBrush(Qt::yellow);

    Osnova_glaz1 = new QGraphicsEllipseItem(170,120,110,200);
    Osnova_glaz1->setBrush(Qt::white);

    Osnova_glaz2 = new QGraphicsEllipseItem(300,120,110,200);
    Osnova_glaz2->setBrush(Qt::white);
}
