#include <QGraphicsItem>
#include <QPainter>
#include <QApplication>
#include <QTransform>
#include <QStyleOptionGraphicsItem>


#ifndef MOVINGCIRCLE_H
#define MOVINGCIRCLE_H

class MovingCircle : public QGraphicsEllipseItem, public QObject{
    public:
        MovingCircle();
        int xc=0;
        int yc=0;
        void moveLeft();
        void moveRight();
        void moveDown();
        void moveUp();
};

#endif // MOVINGCIRCLE_H
