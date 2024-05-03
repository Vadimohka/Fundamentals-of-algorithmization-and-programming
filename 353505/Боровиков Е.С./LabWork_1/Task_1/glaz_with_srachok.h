#ifndef GLAZ_WITH_SRACHOK_H
#define GLAZ_WITH_SRACHOK_H
#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>
#include"glaza.h"

class glaz_with_srachok:public Glaza_1
{
public:
    glaz_with_srachok();
    QGraphicsEllipseItem * zrachok1;
    QGraphicsEllipseItem * bel_kysok1;

    QGraphicsEllipseItem * zrachok2;
    QGraphicsEllipseItem * bel_kysok2;

    void myTimerEllipse1() override;

    void myTimerEllipse2() override;

};

#endif // GLAZ_WITH_SRACHOK_H
