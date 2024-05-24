#include "../Headers/Widget.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent)
{

}


Widget::~Widget()
{

}


void Widget::paintEvent(QPaintEvent * event)
{
    QPainter *painter = new QPainter;
    painter->begin(this);

    QRect * rectangle = new QRect(QPoint(0,0),QPoint(1000,600));

    QImage * sky = new QImage("../Pictures/images.jpeg");

    painter->drawImage(*rectangle,*sky);

    painter->end();
}
