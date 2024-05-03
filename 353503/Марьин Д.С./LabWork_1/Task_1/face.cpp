#include "face.h"

Face::Face(QRectF face,QColor color):
    MovingEllips(nullptr,face,color)

{
    nose = new QGraphicsEllipseItem();
    nose->setRect(face.x() + face.width() / 2 - 25 ,face.y() + face.height() / 2 , 50 , 50);

    left_ear = new QGraphicsEllipseItem();
    right_ear = new QGraphicsEllipseItem();
    right_ear->setRect(face.x() + face.width() - 25,face.y() + face.height()/2 - 70,50,70);
    left_ear->setRect(face.x() - 25,face.y() + face.height() / 2 - 70, 50 ,70);
}

void Face::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(QColor(207,178,144));
    painter->setBrush(QColor(207,168,144));
    painter->drawEllipse(right_ear->rect());

    painter->setPen(QColor(166, 134, 115));
    painter->setBrush(QColor(166, 134, 115));
    painter->drawEllipse(right_ear->rect().x() + 10,right_ear->rect().y() + 13,right_ear->rect().width()/1.5,right_ear->rect().height()/1.5);

    painter->setPen(QColor(207,178,144));
    painter->setBrush(QColor(207,168,144));
    painter->drawEllipse(left_ear->rect());

    painter->setPen(QColor(166, 134, 115));
    painter->setBrush(QColor(166, 134, 115));
    painter->drawEllipse(left_ear->rect().x() + 10,left_ear->rect().y() + 13,left_ear->rect().width()/1.5,left_ear->rect().height()/1.5);

    painter->setPen(get_color());
    painter->setBrush(get_color());
    painter->drawEllipse(get_Rect());

    painter->setPen(Qt::darkRed);
    painter->setBrush(Qt::red);
    painter->drawEllipse(nose->rect());



    // painter->setBrush(Qt::NoBrush);
    // painter->drawRect(x,y,width ,height);
}

