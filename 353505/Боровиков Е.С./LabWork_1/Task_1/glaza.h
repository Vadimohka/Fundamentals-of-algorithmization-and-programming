#ifndef GLAZA_H
#define GLAZA_H
#include <QWidget>
#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>
#include<QTimer>

class Glaza_1
{
public:
    int proverka = 0;
    Glaza_1();
    QGraphicsEllipseItem * glaz1;
    QGraphicsEllipseItem * glaz2;

    QTimer * time_glaza_1;
    QTimer * time_glaza_2;

    virtual void myTimerEllipse1();

    virtual void myTimerEllipse2();
private slots:


};

#endif // GLAZA_H
