#include "abstractfigure.h"

AbstractFigure::AbstractFigure() {

    rect = QRectF(0,0,100,100);
    show_borders = true;
    show_point = false;
}

AbstractFigure::~AbstractFigure(){

}
QRectF AbstractFigure::boundingRect() const{
    return rect;
}

void AbstractFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    drawFigure(painter);
    if(show_borders)
        drawBorders(painter);
    if(show_point)
        drawPoints(painter);

}

void AbstractFigure::setShowBorders(bool value){
    show_borders = value;
}

void AbstractFigure::setShowPoint(bool value){
    show_point = value;
}

void AbstractFigure::drawBorders(QPainter*painter){
    pen.setColor(Qt::black);
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);

    brush.setColor(Qt::black);
    brush.setStyle(Qt::Dense5Pattern);
    painter->setBrush(brush);

    painter->drawRect(rect.x(), rect.y(), rect.width(), rect.height());
}

void AbstractFigure::drawPoints(QPainter *painter){
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);

    painter->setBrush(brush);
    painter->drawEllipse(this->boundingRect().center(),4,4);
    painter->drawEllipse(this->boundingRect().topLeft(),4,4);
    painter->drawEllipse(this->boundingRect().topRight(),4,4);
    painter->drawEllipse(this->boundingRect().bottomRight(),4,4);
    painter->drawEllipse(this->boundingRect().bottomLeft(), 4,4);
}

void AbstractFigure::setColor(QColor color1)
{
    color = color1;
}



void AbstractFigure::drawFigure(QPainter *painter){

}
void AbstractFigure::setRect(double dx1, double dy1, double dx2, double dy2) {
    double width = rect.width();
    double height = rect.height();

    if (dx1 != 0 && width - dx1 > 20)
        rect.setRect(rect.left() + dx1, rect.top(), rect.width() - dx1, rect.height());

    if (dy1 != 0 && height - dy1 > 20)
        rect.setRect(rect.left(), rect.top() + dy1, rect.width(), rect.height() - dy1);


    if (dx2 != 0 && width + dx2 > 20)
        rect.setRect(rect.left(), rect.top(), rect.width() + dx2, rect.height());

    if (dy2 != 0 && height + dy2 > 20)
        rect.setRect(rect.left(), rect.top(), rect.width(), rect.height() + dy2);
}


