#include "fish.h"

Fish::Fish(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    xj=&x;
    yj=&y;
    wj=&w;
    hj=&h;
}

Fish::~Fish()
{

}

QRectF Fish::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void Fish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QImage image("url(:/Images/Images/15.png)");
    QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish3.jpg");
    QRect recrangle(-30,-30,60,60);
    QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
    /*painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,60,60);*/
    painter->drawImage(recrangle, image);

    /*painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,60,60);*/
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Fish::growFish(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, int i)
{
    QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish3.jpg");
    for(int j=1; j<=i; ++j)
    {
    QRect recrangle(0,0,w+j,h+j);
    painter->drawImage(recrangle, image);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

void Fish::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
this->setPos(mapToScene(event->pos()));
}

void Fish::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Fish::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void Fish::move(int k)
{
    x+=k;
    if(x<0||x+w>=1200)
        x-=k;
    //repaint();
}
