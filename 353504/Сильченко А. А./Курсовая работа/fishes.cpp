#include "fishes.h"

Fishes::Fishes(QObject *parent) : QObject(parent), QGraphicsItem(){
    w=randomBetween(30,100);
    h=w;
}

Fishes::~Fishes()
{

}

int Fishes::randomBetween(int low, int high)
{
    return (QRandomGenerator::global()->generate()%((high + 1) - low) + low);
}

QRectF Fishes::boundingRect() const
{
    return QRectF (0,0,w,h);
}

void Fishes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    //QImage image("url(:/Images/Images/15.png)");
    fsh=randomBetween(1,11);
    if(fsh==1)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish1.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==2)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish2.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==3)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish4.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==4)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish5.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==5)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish6.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==6)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish7.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==7)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish8.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==8)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish9.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else if (fsh==9)
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish10.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    else
    {
        QImage image("/home/oblachko/Projects/Курсовая работа/resource/fish11.jpg");
        QRect recrangle(0,0,w,h);
        QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
        painter->drawImage(recrangle, image);
    }
    //qDebug()<<m;
    pathGeneration();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Fishes::move()
{
    m=rand()%4;
    //qDebug()<<m;
    switch(m)
    {
    case 0:
        for(; x<1700; x+=0.01)
        {
            this->setPos(x, y);
            t->start(10000);
        }
    case 1:
        for(; x<1700&&y>600; x+=0.01, y+=0.01)
        {
            this->setPos(x, y);
        t->start(10000);
        }
    case 2:
        for(; x<1700&&y>0; x+=0.01, y-=0.01)
        {

            this->setPos(x, y);
        t->start(10000);
        }
    default:
        update();
    }
}

void Fishes::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
    /*    m=0;
    //m=rand()%4;
    //qDebug()<<m;
    switch(m)
    {
    case 0:
        for(; x<1700; x+=0.01)
        {
            this->setPos(x, y);
        }
    case 1:
        for(; x<1700&&y>600; x+=0.01, y+=0.01)
            this->setPos(x, y);
    case 2:
        for(; x<1700&&y>0; x+=0.01, y-=0.01)
            this->setPos(x, y);
    default:
    }*/
}

void Fishes::pathGeneration()
{
    m=rand()%5;
    //qDebug()<<m;
    if(x<=0)
    {
        switch(m)
        {
        case 0:
            for(; x<1700; x+=0.01)
                this->setPos(x, y);
        case 1:
            for(; x<1700&&y<600; x+=0.02, y+=0.01)
                this->setPos(x, y);
        case 2:
            for(; x<1700&&y>0; x+=0.03, y-=0.04)
                this->setPos(x, y);
        case 3:
            for(; x<1700&&y<600; x+=0.001, y+=0.001)
                this->setPos(x, y);
        case 4:
            for(; x<1700&&y>0; x+=0.02, y-=0.02)
                this->setPos(x, y);
        default:
        }
    }
    else
    {
        switch(m)
        {
        case 0:
            for(; x>0; x-=0.01)
            {
                this->setPos(x, y);
            }
        case 1:
            for(; x>0&&y<600; x+=0.02, y+=0.03)
                this->setPos(x, y);
        case 2:
            for(; x>0&&y>0; x+=0.03, y-=0.01)
                this->setPos(x, y);
        case 3:
            for(; x>0&&y<600; x+=0.01, y+=0.03)
                this->setPos(x, y);
        case 4:
            for(; x>0&&y>0; x+=0.001, y-=0.02)
                this->setPos(x, y);
        default:
        }
    }
}
