#include "rectangle.h"

QRectF rectangle::boundingRect() const{
    return QRectF();
}


void rectangle::per_left(){
    if (!is_left()){
        per_x -= 1;
        grad -= 0.8;
    }
}

void rectangle::per_right(){
    if (!is_right()){
        per_x += 1;
        grad += 0.8;
    }
}

bool rectangle::is_right(){
    if (per_x < 900){
        return false;
    }
    else{
        return true;
    }
}

bool rectangle::is_left(){
    if (per_x > -200){
        return false;
    }
    else{
        return true;
    }
}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter -> setBrush(Qt::red);
    painter -> drawRect(per_x - 600, 255, 300, 30);
}

