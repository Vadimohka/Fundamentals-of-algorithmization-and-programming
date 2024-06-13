#include "rect.h"

Rect::Rect(int x1,int y1, int x2, int y2){

    rect = QRectF(x1,y1,x2,y2);
    show_borders = false;
}

Rect::~Rect(){
}

void Rect::drawFigure(QPainter *painter){

    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    double x1 = boundingRect().x();
    double y1 = boundingRect().y();
    double width1 = boundingRect().width();
    double height1 = boundingRect().height();
    painter->drawRect(x1,y1,width1,height1);
}
