#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H
#include<QWidget>
#include <QPainter>

class Rec:public QWidget{
public:
    int x=460;
    void paintEvent(QPaintEvent *event);
    void drawRec(QPainter *painter);
    void UP();
    void DOWN();
private:
    int angle = 0;
};

#endif

