#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QSlider>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <cmath>
//#include "customscene.h"

class Figure : public QGraphicsScene, public QGraphicsItem
{

public:

    QPoint center;
    Figure();
    bool Flag = true;
    float Radius1 = 50 , Radius2 = 50;
    float Radius = 100;
    float Length = 200;
    float Width = 100;
    float Size = 50;
    float Scale = 1;
    float getScale();
    QPoint getCenter();
    virtual float Area();
    virtual float Perimeter();
    float scale = 1.0;
    void makeFlagTrue();
    void setCenterX( int CenterX );
    void setCenterY( int CenterY );
    void changeLength( int newLength );
    void changeWidth( int newWidth );
    void changeSize( int newSize );
    void changeRadius( int newRadius );
    void changeRadius1( int newRadius1 );
    void changeRadius2( int newRadius2 );
    void changeScale( int newScale );

protected:

    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);


};

#endif // FIGURE_H
