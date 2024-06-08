#include "rect.h"

Rect::Rect()
{

}

Rect::Rect(Rect &other)
{
    x = other.x;
    y = other.y;
    h = other.h;
    w = other.w;
}

Rect::~Rect()
{

}

void Rect::setParam(int x, int y, int w, int h)
{
    setPos(x, y);
    this->y = y;
    this->h = h;
    this->w = w;
    update();
}

Rect& Rect::operator=(Rect& other)
{
    this->x = other.x;
    this->y = other.y;
    this->h = other.h;
    this->w = other.w;
    return *this;
}

QRectF Rect::boundingRect() const
{
    return QRectF(0, 0, w, h);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    if(aim){
        painter->setBrush(QBrush(Qt::magenta));
    }
    else{
        painter->setBrush(QBrush(Qt::white));
    }
    painter->drawRect(0,0,w,h);
}
