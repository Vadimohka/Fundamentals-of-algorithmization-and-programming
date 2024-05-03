#include "glaz_with_srachok.h"
#include <QTimer>

glaz_with_srachok::glaz_with_srachok() {
    zrachok1 = new QGraphicsEllipseItem(212,205,25,25);
    zrachok1->setBrush(Qt::black);
    bel_kysok1 = new QGraphicsEllipseItem(210,202,10,10);
    bel_kysok1->setBrush(Qt::white);

    zrachok2 = new QGraphicsEllipseItem(342,205,25,25);
    zrachok2->setBrush(Qt::black);
    bel_kysok2 = new QGraphicsEllipseItem(340,202,10,10);
    bel_kysok2->setBrush(Qt::white);


}

void glaz_with_srachok::myTimerEllipse1()
{
    time_glaza_1 = new QTimer;
    QObject::connect(time_glaza_1, &QTimer::timeout ,[=](){
    static int i = 0,j = 0;
    j++;
    if(j<25){
        i++;
        proverka = 1;

        glaz1->setPos(i,0);
        glaz2->setPos(i,0);
        zrachok1->setPos(i,0);
        zrachok2->setPos(i,0);
        bel_kysok1->setPos(i,0);
        bel_kysok2->setPos(i,0);

    }
    else{
        i--;
        proverka = 1;

        glaz1->setPos(i,0);
        glaz2->setPos(i,0);
        zrachok1->setPos(i,0);
        zrachok2->setPos(i,0);
        bel_kysok1->setPos(i,0);
        bel_kysok2->setPos(i,0);
        if(i == 0){
            time_glaza_1->stop();
            j = 0;
            proverka = 0;

        }
    }

    });
    time_glaza_1->start(30);
}

void glaz_with_srachok::myTimerEllipse2()
{
    time_glaza_2 = new QTimer;

    QObject::connect(time_glaza_2, &QTimer::timeout, [=](){
    static int i = 0,f = 0;
    f++;
    if(f<25){
        i--;
        proverka = -1;

        glaz1->setPos(i,0);
        glaz2->setPos(i,0);
        zrachok1->setPos(i,0);
        zrachok2->setPos(i,0);
        bel_kysok1->setPos(i,0);
        bel_kysok2->setPos(i,0);
    }
    else{
        i++;
        proverka = -1;

        glaz1->setPos(i,0);
        glaz2->setPos(i,0);
        zrachok1->setPos(i,0);
        zrachok2->setPos(i,0);
        bel_kysok1->setPos(i,0);
        bel_kysok2->setPos(i,0);
        if(i == 0){
            time_glaza_2->stop();
            f = 0;
            proverka = 0;

        }
    }
    });
    time_glaza_2->start(30);
}

