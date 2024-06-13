#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent)
    : QWidget{parent}
{
    this->setParent(parent);
}

void PaintArea::mousePressEvent(QMouseEvent *event){
    if (Rectangle::num % 2 == 0){
        rect = new Rectangle(this);
        Rectangle::point1 = event->globalPos();
        Rectangle::point2 = event->globalPos();
    }
    Rectangle::num++;
}

void PaintArea::mouseMoveEvent(QMouseEvent *event){
    if (Rectangle::num % 2 == 1){
        Rectangle::point2 = event->globalPos();

    }
}
