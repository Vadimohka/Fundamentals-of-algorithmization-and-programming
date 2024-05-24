#include "circle.h"

Circle::Circle(){

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(-radius / 2, -radius / 2, radius, radius);
}

float Circle::area(){
    return this->getScale() * this->getScale() * M_PI * radius * radius;
}

float Circle::perimeter(){
    return 2 * M_PI * radius * this->getScale();
}

