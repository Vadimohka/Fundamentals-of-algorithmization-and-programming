#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QtWidgets>

class Shape: public QGraphicsScene, public  QGraphicsItem
{
public:
    Shape();
    float getScale();
    virtual float area()=0;
    virtual float perim()=0;
    float x;
    float y;

    double angle = 0;
    float scale = 1.0;

    float triScale=1.0;

    QPointF center;

    int targetA;
    int targetB;

    int targetHei;
    int targetWid;

    int targetF;

    double targetRHei;
    double targetRWid;

    bool detached = false;
    QPointF shift;
    QPointF shiftDetached;

    virtual void getPoint(QPointF){};

    QVector<QPointF> points;

    float shiftX = 0;
    float shiftY = 0;
    float lastShiftX;
    float lastShiftY;


    virtual void setN(int){};
    virtual void setn(int){};
    virtual void setRadB(int){};
    virtual void setRadA(int){};

    virtual float getRadF(){return 0;};
    virtual float getRadS(){return 0;};

    virtual void setRadF(float){};
    virtual void setRadS(float){}

    virtual float getWid(){return 0;};
    virtual float getHei(){return 0;};

    virtual void setWid(float){};
    virtual void setHei(float){}

    virtual double getS(){return 0;};
    virtual double getP(){return 0;};

    virtual float getS1(){return 0;};
    virtual void setS1(float){};

    virtual float getDiam1(){return 0;};
    virtual float getDiam2(){return 0;};

    virtual void setDiam1(float){};
    virtual void setDiam2(float){};



    void getSize();

    void rotate(int ) ;

private:

    QMouseEvent *mouse;

protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){};

};

#endif // SHAPE_H
