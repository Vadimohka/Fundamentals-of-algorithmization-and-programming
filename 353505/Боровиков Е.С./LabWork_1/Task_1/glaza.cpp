#include "glaza.h"
Glaza_1::Glaza_1()
{

    glaz1 = new QGraphicsEllipseItem(197.5,190,55,55);
    glaz1->setBrush(QColor(0,204,255));

    glaz2 = new QGraphicsEllipseItem(327.5,190,55,55);
    glaz2->setBrush(QColor(0,204,255));
}

void Glaza_1::myTimerEllipse1(){
    time_glaza_1 = new QTimer;
    QObject::connect(time_glaza_1, &QTimer::timeout ,[=](){
        static int i = 0,j = 0;
        j++;
        if(j<25){
            i++;
            proverka = 1;
            glaz1->setPos(i,0);
            glaz2->setPos(i,0);
        }
        else{
            i--;
            proverka = 1;
            glaz1->setPos(i,0);
            glaz2->setPos(i,0);
            if(i == 0){
                time_glaza_1->stop();
                j = 0;
                proverka = 0;

            }
        }
    });
    time_glaza_1->start(30);
}

void Glaza_1 ::myTimerEllipse2(){
    time_glaza_2 = new QTimer;
    QObject::connect(time_glaza_2, &QTimer::timeout ,[=](){
    static int i = 0,f = 0;
    f++;
    if(f<25){
        i--;
        proverka  = -1;
        glaz1->setPos(i,0);
        glaz2->setPos(i,0);
    }
    else{
        i++;
        proverka  = -1;
        glaz1->setPos(i,0);
        glaz2->setPos(i,0);
        if(i == 0){
            time_glaza_2->stop();
            f = 0;
            proverka  = 0;

        }
    }
    });
    time_glaza_2->start(30);
}
