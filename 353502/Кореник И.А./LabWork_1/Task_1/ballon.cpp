#include "ballon.h"

Ballon::Ballon(Ellipse *parent)
    : Ellipse{}
{
    this->setParent(parent);
}
void Ballon::paintEvent(QPaintEvent *event){
    QPainter* painter = new QPainter;
    painter->begin(this);
    QPixmap picture("/home/lidskae/Downloads/5465.png");
    painter->drawPixmap(50, 90, 300, 300, picture);

    painter->end();
}

void Ballon::boom(){

    this->hide();

}
