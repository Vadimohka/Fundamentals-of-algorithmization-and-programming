#include "ellipse.h"

Ellipse::Ellipse(int x1,int y1, int x2, int y2){

    rect = QRectF(x1,y1,x2,y2);
    show_borders = false;
}

Ellipse::~Ellipse(){

}

void Ellipse::drawFigure(QPainter *painter){

        brush.setColor(Qt::red);
        brush.setStyle(Qt::SolidPattern);
        painter->setBrush(brush);
        painter->drawEllipse(rect.x(), rect.y(), rect.width(), rect.height());

}
