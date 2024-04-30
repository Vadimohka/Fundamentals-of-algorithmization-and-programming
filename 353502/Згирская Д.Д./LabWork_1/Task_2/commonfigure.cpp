#include "commonfigure.h"

CommonFigure::CommonFigure(QWidget *parent) : QWidget(parent){
    this->setParent(parent);

    this->timer = new QTimer;
}

CommonFigure::~CommonFigure(){
    delete this->timer;
}

void CommonFigure::drawPressEvent(QMouseEvent *event){
    insertionPoint.setX(event->x());

    insertionPoint.setY(event->y());
}


