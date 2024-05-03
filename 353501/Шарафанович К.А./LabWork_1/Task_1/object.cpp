#include "object.h"
#include <QtWidgets>
#include <QTimer>
#include <QDebug>

object::object()
{
    rectangle = new QGraphicsRectItem(-40,-40,180,100,this);
    rectangle ->setBrush(Qt::black);
}

    void object::MoveLeft(){
    setPos(x()-10,y());

    }
    void object::MoveRight(){

    setPos(x()+10,y());

    }


    object::~object(){
    }
    void object::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    }

    QRectF object::boundingRect() const
    {
    return QRectF(-40,-40,80,60);
    }



