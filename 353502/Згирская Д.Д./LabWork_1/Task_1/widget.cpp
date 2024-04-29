#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}


Widget::~Widget(){}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter;
    painter->begin(this);
    QRect *rect = new QRect(0,0,800,600);
    QImage * image  = new QImage("/home/zgdarya/QTWORKS/Task1/Untitled.jpeg");
    painter->drawImage(*rect,*image);
    painter->end();
}
